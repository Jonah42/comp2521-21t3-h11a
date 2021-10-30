#include "Graph.h"
#include <stdlib.h>

bool isEulerPath(Graph g, Edge e[], int nE) {
	// has to have the same number of edges as the og graph
	int nV = GraphNumVertices(g);
	int count = 0;
	for (int u = 0; u < nV; u++) {
		for (int v = u+1; v < nV; v++) {
			if (GraphIsAdjacent(g, u, v)) count++;
		}
	}
	if (nE != count) return false;
	// there are no duplicates
	int *seen[nV]; // 2D array of 0
	for (int i = 0; i < nV; i++) {
		seen[i] = calloc(nV, sizeof(int));
	}
	for (int i = 0; i < nE; i++) {
		if (seen[e[i].v][e[i].w]) return false;
		seen[e[i].v][e[i].w] = 1;
		seen[e[i].w][e[i].v] = 1;
	}
	return true;
}

int main(void) {
	Graph g = GraphRead();
	int nE;
	Edge* e = EdgeRead(&nE);
	printf("Is Euler path? %s\n", isEulerPath(g, e, nE) ? "True" : "False");
	GraphFree(g);
	free(e);
	return 0;
}