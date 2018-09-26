/*
 * If the child calls printf() to print some output after closing the
 * descriptor, nothing is printed out.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}

	else if (rc == 0) {
		printf("Hello I am child\n");
		close(STDOUT_FILENO);
		printf("Testing...1,2,3...\n");
	}

	else {
		printf("Hello I am parent\n");
	}

	return 0;
}
