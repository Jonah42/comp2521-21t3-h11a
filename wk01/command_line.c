// 2521 Tut1 command line Q, Jonah Meggs
// Simple program to shed light upon the mysteries of argc and argv

#include <stdio.h>

int main(int argc, char** argv) {
	printf("Number of args: %d\n", argc);
	int i = 0;
	while (argv[i] != NULL) {
		printf("Argument %d is %s\n", i, argv[i]);
		i++;
	}
	return 0;
}