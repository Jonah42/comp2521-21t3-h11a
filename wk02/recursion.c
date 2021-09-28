//Written by Jonah Meggs for COMP2521 21T3

#include <stdio.h>

int recursive_factorial(int n) {
	// When to stop?? n == 1
	// BASE CASE
	if (n == 1) return 1;
	// GENERIC CASE
	return n*recursive_factorial(n-1);
}

int main(void) {
	recursive_factorial(4);
	return 0;
}