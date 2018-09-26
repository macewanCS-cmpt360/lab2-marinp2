/*
 * The value of the variable x in the child process is equal to the initial
 * value of 500. When both the child and parent change the value of x, the
 * value of variable x changes to whatever is set by the two processes - the
 * value of x in the child process will change to whatever is set in that
 * process and the value of x in the parent process will also change to
 * whatever is set in that process.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int x = 1000;
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}

	else if (rc == 0) {
		printf("Hello I am child. ");
		printf("Initial value of x: %d ", x);
		x = 2000;
		printf("New value of x: %d\n", x);
	}

	else {
		printf("Hello I am parent. ");
		printf("Initial value of x: %d ", x);
		x = 3000;
		printf("New value of x: %d\n", x);
	}

	return 0;
}
