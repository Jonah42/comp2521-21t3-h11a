#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NOT_HEIGHT_BALANCED -99
#define max(a,b) (a > b ? a : b)

typedef struct node BSTNode;
typedef Tree BSTree;

int BSTreeNumNodes(BSTree t) {
	// Base Case
	if (t == NULL) return 0;
	return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
}

int BSTreeCountOdds(BSTree t) {
	if (t == NULL) return 0;
	// return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
	return (t->value %2 ? 1 : 0) + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
}

int BSTreeHeight(BSTree t) {
	if (t == NULL) return 0;
	return 1 + max(BSTreeHeight(t->left), BSTreeHeight(t->right));
}

int BSTreeCountInternal(BSTree t) {
	if (t == NULL || (t->left == NULL && t->right == NULL)) return 0;
	return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
}

int BSTreeNodeLevel(BSTree t, int key) {
	if (t == NULL) return -1;
	if (t->value == key) return 0;
	if (key > t->value) { // recurse right
		int ret = BSTreeNodeLevel(t->right, key);
		return ret == -1 ? -1 : ret + 1;
	} else { // key < t->value
		int ret = BSTreeNodeLevel(t->left, key);
		return ret == -1 ? -1 : ret + 1;
	}
	return 0;
}

int BSTreeCountGreater(BSTree t, int key) {
	if (t == NULL) return 0;
	if (t->value <= key) return BSTreeCountGreater(t->right, key);
	return 1 + BSTreeCountGreater(t->left, key) + BSTreeCountGreater(t->right, key);
}

int isHeightBalanced(BSTree t) {
	if (t == NULL) return 0;
	int left_height = isHeightBalanced(t->left);
	int right_height = isHeightBalanced(t->right);
	if (left_height == NOT_HEIGHT_BALANCED 
		|| right_height == NOT_HEIGHT_BALANCED 
		|| abs(left_height-right_height) > 1) return NOT_HEIGHT_BALANCED;
	return 1 + max(left_height, right_height);
}

BSTree createNode(int value) {
	BSTree new = malloc(sizeof(*new));
	new->left = new->right = NULL;
	new->value = value;
	return new;
}

BSTree insert(BSTree t, int value) {
	if (t == NULL) return createNode(value);
	if (value < t->value) t->left = insert(t->left, value);
	else t->right = insert(t->right, value);
	return t;
}

int main(int argc, char **argv) {
	BSTree t = NULL;
	for (int i = 1; i < argc; i++) t = insert(t, atoi(argv[i]));
	printTree(t);
	printf("NumNodes: %d\n", BSTreeNumNodes(t));
	printf("CountOdds: %d\n", BSTreeCountOdds(t));
	printf("Height: %d\n", BSTreeHeight(t));
	printf("CountInternal: %d\n", BSTreeCountInternal(t));
	printf("NodeLevel: %d\n", BSTreeNodeLevel(t, 8));
	printf("CountGreater: %d\n", BSTreeCountGreater(t, 5));
	printf("HeightBalanced: %d\n", isHeightBalanced(t));
	return 0;
}