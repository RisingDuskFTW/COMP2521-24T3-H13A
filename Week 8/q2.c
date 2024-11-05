#include "Graph.h"
#include "Set.h"
#include "Queue.h"

static void doRecursiveDFS(Graph g, Vertex v, Set seen);

Set reachable(Graph g, Vertex src) {
	Set seen = SetNew();
	doRecursiveDFS(g, src, seen);
	return seen;
}

static void doRecursiveDFS(Graph g, Vertex v, Set seen) {
	SetAdd(seen, v);

	// for each vertex
	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		// check if it is adjacent
		if (GraphIsAdjacent(g, v, w) && !SetContains(seen, w)) {
			// traverse to that vertex
			doRecursiveDFS(g, w, seen);
		}
	}
}
