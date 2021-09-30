#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char* A[3] = {"cat", "dog", "mouse"};
	int P[3] = {2,3,1};

	char *tmp[3];

	for (int index = 0; index < 3; index++) {
		int position = P[index]-1;
		tmp[position] = A[index];
	}
	for (int index = 0; index < 3; index++) {
		printf("%s ", tmp[index]);
	}
	printf("\n");
	return 0;
}