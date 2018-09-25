#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int x = 500;

	printf("Initial value of x: %d\n", x);
	int f = fork();

	if (f < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}

	else if (f == 0) {
		printf("I am child\t");
		printf("Value of x: %d\t", x);
		x = 1000;
		printf("New value of x: %d\n", x);
	}

	else {
		printf("I am parent\t");
		printf("Value of x: %d\t", x);
		x = 2000;
		printf("New value of x: %d\n", x);
	}

	return 0;
}
