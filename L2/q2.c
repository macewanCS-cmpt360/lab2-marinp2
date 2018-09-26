/*
 * Yes, both the child and parent can access the file descriptor returned by
 * open. When both processes are writing to the file concurrently, one message
 * (either the parent or child message) is written first followed by the other
 * message.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(void)
{
	int text_file = open("HelloWorld.txt",
	O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}

	else if (rc == 0) {
		char *child_msg = "Hello I am child\n";
		write(text_file, child_msg, strlen(child_msg));
	}

	else {
		char *parent_msg = "Hello I am parent\n";
		write(text_file, parent_msg, strlen(parent_msg));
	}

	return 0;
}
