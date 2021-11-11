#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE * fp1 = fopen("in1.txt", "r");
	FILE * fp2 = fopen("in2.txt", "r");
	if (fp1 == NULL || fp2 == NULL) {
		printf("Invalid input file(s).\n");
		return 0;
	}
	int in1, in2, eof1, eof2;
	eof1 = fscanf(fp1, "%d", &in1);
	eof2 = fscanf(fp2, "%d", &in2);

	while (eof1 != EOF && eof2 != EOF) {
		if (in1 <= in2) {
			printf("%d ", in1);
			eof1 = fscanf(fp1, "%d", &in1);
			// tmp[k++] = A[i++];
		} else {
			printf("%d ", in2);
			eof2 = fscanf(fp2, "%d", &in2);
			// tmp[k++] = A[j++];
		}
	}

	while (eof1 != EOF) {
		printf("%d ", in1);
		eof1 = fscanf(fp1, "%d", &in1);
	}
	while (eof2 != EOF) {
		printf("%d ", in2);
		eof2 = fscanf(fp2, "%d", &in2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}