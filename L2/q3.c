/*
 * No, I don't think that I can do this without calling wait() in the parent.
 * One way to possibly get the child execute first would be to kill the parent
 * and/or create a new method that will print out the word "goodbye".
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}

	else if (rc == 0) {
		printf("hello\n");
	}

	else {
		wait(NULL);
		printf("goodbye\n");
	}
	return 0;
}
