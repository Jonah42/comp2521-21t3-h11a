#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char * word = argv[1];
	// iterate through word
	for (int l = 0, r = strlen(word)-1; l < r; l++, r--) {
		if (word[l] != word[r]) {
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
	return 0;
}

// O(n/2) -> O(n)