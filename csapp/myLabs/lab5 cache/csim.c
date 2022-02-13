#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef unsigned long int uint_64;
typedef int bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    int hit;
    int miss;
    int eviction;
} result;

typedef struct {
    int valid;
    int lru;
    uint_64 tag;
} cacheLine;

void print_help(void){
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n"
            "Options:\n"
            "  -h         Print this help message.\n"
            "  -v         Optional verbose flag.\n"
            "  -s <num>   Number of set index bits.\n"
            "  -E <num>   Number of lines per set.\n"
            "  -b <num>   Number of block offset bits.\n"
            "  -t <file>  Trace file.\n\n"
            "Examples:\n"
            "  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n"
            "  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

void init_cacheLine(cacheLine** cache, int S, int E){
    for (int i=0; i<S; i++) {
        *(cache+i) = (cacheLine*)malloc(E*sizeof(cacheLine));
        for (int j=0; j<E; j++) {
            cache[i][j].valid = 0;
            cache[i][j].lru = -1U;
            cache[i][j].tag = -1U;
        }
    }
}

void update(cacheLine** cache, int s, int E, int b, uint_64 address, result* res) {
    uint_64 s_address =(address>>b) & ((-1U)>>(64-s));
    uint_64 t_address = address>>(s+b);

    cacheLine* target = cache[s_address];
    // tag匹配, hit
    for (int i=0; i<E; i++) {
        if ((target+i)->tag == t_address) {
            (target+i)->lru = 0;
            res->hit++;
            return;
        }
    }

    // tag不匹配, 有空位则放进去
    for (int i = 0; i<E; i++) {
        if ((target+i)->valid == 0) {
            (target+i)->valid = 1;
            (target+i)->lru = 0;
            (target+i)->tag = t_address;
            res->miss++;
            return;
        }
    }

    // 没空位则LRU
    int max_lru=0, idx=0;
    for (int i = 0; i<E; i++) {
        if ((target+i)->lru > max_lru) {
            idx = i;
            max_lru = (target+i)->lru;
        }
    }
    res->miss++;
    res->eviction++;
    target[idx].tag = t_address;
    target[idx].lru = 0;
}

void step(cacheLine** cache, int S, int E){
	for(int i=0;i<S;i++){
		for(int j=0;j<E;j++){
			if(cache[i][j].valid == 1)
				cache[i][j].lru++;		
		}	
	}
}

int main(int argc, char** argv)
{

    // parser
    // bool verbose=FALSE, error=TRUE, hv = FALSE;
    char opt;
    int s = -1, E = -1, b = -1, S = -1;
    char *fPath = NULL;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (opt) {
            case 'h':
                // hv = TRUE;
                break;
            case 'v':
                // hv = TRUE;
                // verbose = TRUE;
                break;
            case 's':
                s = atol(optarg);
				S = 2<<s;
                break;
            case 'E':
                E = atol(optarg);
                break;
            case 'b':
                b = atol(optarg);
                break;
            case 't':
                fPath = optarg;
                break;
            default:
                // error = TRUE;
                ;
        }
    }
    // printf("verbose=%d\n", verbose);
    // if (!hv||s<=0||E<=0||b<=0||fPath==NULL||error) {
    //     print_help();
    //     exit(0);
    // }

    // read traces, except instructions(no space)
    FILE* file = fopen(fPath, "r");
    char op;
    uint_64 address;
    int size;
    cacheLine** cache = (cacheLine**)malloc(S*sizeof(cacheLine*));
    init_cacheLine(cache, S, E);
    if (file==NULL) {
        printf("Open file error.\n");
        exit(0);
    }
	result* res = (result*)malloc(sizeof(result));
    while (fscanf(file," %c %lx,%d",&op,&address,&size)>0) {
        switch(op){
            case 'L':
                update(cache, s, E, b, address, res);
                break;
            case 'M':
                update(cache, s, E, b, address, res);
            case 'S':
                update(cache, s, E, b, address, res);
                break;
            default:
                ;
        }
        step(cache, S, E);
    }

	// end
	for(int i=0;i<S;i++){
		free(*(cache+i));
    }
	free(cache);
	fclose(file);

	// result
    printSummary(res->hit, res->miss, res->eviction);
    return 0;
}
