#include <stdio.h>
#include <ctype.h>
#include <string.h>


int my_strlen(char *s) { //O(n)
	printf("Hello!\n");
	return strlen(s); //O(n)
}

void strToLower(char *s) {
	for (int i = 0; i < my_strlen(s); i++) { //O(n^2)
		s[i] = tolower(s[i]); //O(1)
	}
}

int main(int argc, char** argv) {
	char s[] = "rAnDoM stRiNg";
	printf("%s\n", s);
	strToLower(s);
	printf("%s\n", s);
	return 0;
}