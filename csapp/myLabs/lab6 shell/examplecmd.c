#include "csapp.h"

#define MAXARGS 128

/* Macro funcs */

void unix_error(char *msg) /* Unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

void app_error(char *msg) /* Application error */
{
    fprintf(stderr, "%s\n", msg);
    exit(0);
}

pid_t Fork(void) 
{
    pid_t pid;

    if ((pid = fork()) < 0)
	unix_error("Fork error");
    return pid;
}

char *Fgets(char *ptr, int n, FILE *stream) 
{
    char *rptr;

    if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream))
	app_error("Fgets error");

    return rptr;
}

/* Function prototypes */
void eval (char *cmdline);
int parseline (char *buf, char **argv);
int builtin_command(char **argv);

int main(){
    char cmdline[MAXLINE]; /* command line */

    while(1){
        /* Read */
        printf(">");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin)) {
            exit(0);
        }

        /* Evaluate */
        eval(cmdline);
    }
}

/* eval - Evaluate a command line */
void eval (char *cmdline) {
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg */
    pid_t pid;           /* Process id */

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL) {
        return; /* Ignore empty lines */
    }

    if (!builtin_command(argv)) {
        if ((pid = Fork()) == 0) { /* Child runs user job */
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }
    }

    /* Parents waite for foreground job to terminate */
    if (!bg) {
        int status;
        if (waitpid(pid, &status, 0)<0) {
            unix_error("waitfg: waitpid error");
        }
    }
    else {
        printf("%d %s", pid, cmdline);
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command (char **argv) {
    if (!strcmp(argv[0], "quit")) { /* quit command */
        exit(0);
    }
    if (!strcmp(argv[0], "&")) { /* Ignore singleton & */
        return 1;
    }
    if (!strcmp(argv[0], "hello")) { /* add hello command */
        printf("FUCK U Bc\n");
        return 1;
    }
    return 0; /* Not a builtin command */
}

/* parseline - Parse the command lien and build the argv array */
int parseline (char *buf, char **argv) {
    char *delim; /* Point s to first space delimiter */
    int argc;    /* Number of args */
    int bg;      /* Background job? */

    buf[strlen(buf)-1] = ' '; /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) { /* Ignore leading spaces */
        buf++;
    }

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) { /* Ignore spaces */
            buf++;
        }
    }
    argv[argc] = NULL;

    if (argc == 0) { /* Ignore blank line */
        return 1;
    }

    /* Should the job run in the background */
    if ((bg = (*argv[argc-1] == '&')) != 0) {
        argv[--argc] = NULL;
    }

    return bg;
}