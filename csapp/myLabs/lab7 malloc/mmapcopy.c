#include "csapp.h"

/* Tool functions defined in csapp.h */
void unix_error(char *msg) /* Unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

int Open(const char *pathname, int flags, mode_t mode) 
{
    int rc;

    if ((rc = open(pathname, flags, mode))  < 0)
	unix_error("Open error");
    return rc;
}

void *Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset) 
{
    void *ptr;

    if ((ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void *) -1))
	unix_error("mmap error");
    return(ptr);
}

ssize_t Write(int fd, const void *buf, size_t count) 
{
    ssize_t rc;

    if ((rc = write(fd, buf, count)) < 0)
	unix_error("Write error");
    return rc;
}

/*
 * mmapcopy - uses mmap to copy file fd to stdout
 */
void mmapcopy (int fd, int size) {
	char *bufp; /* ptr to memory-mapped VM area */
	bufp = Mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	Write(1, bufp, size);
	return ;
}

/* mmapcopy driver */
int main (int argc, char **argv) {
	struct stat stat;
	int fd;

	/* Check for required command-line argument */
	if (argc != 2) {
		printf("Invalid input. Usage: %s <filename>\n", argv[0]);
		exit(0);
	}

	/* Copy the input argument to stdout */
	fd = Open(argv[1], O_RDONLY, 0);
	fstat(fd, &stat);
	mmapcopy(fd, stat.st_size);
	exit(0);
}

