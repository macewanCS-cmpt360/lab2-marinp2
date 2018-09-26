#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(void)
{
	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10];

	cmdline = calloc(1, 1024);
	i = 0;

	while (1) {
		printf("prompt> ");
		fgets(cmdline, 1024, stdin);

		token = strtok(cmdline, "\n ");
		while (token != NULL) {
			args[i++] = strdup(token);
			token = strtok(NULL, "\n ");
		}
		args[i] = NULL;

		free(cmdline);

		rc = fork();

		if (rc < 0) {
			fprintf(stderr, "fork failed\n");
			exit(1);
		}

		else if (rc == 0) {
			execvp(args[0], args);
			exit(0);
		}

		else {
			wait(NULL);
		}
	}
}
