// Iterative and recursive function to check if a linked list is sorted

#include <stdio.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};

// Solution 1: Iterative Solution
bool listIsSorted(struct node *l) {
	if (l == NULL || l->next == NULL) {
		return true;
	}
	for (struct node *curr = l; curr->next == NULL; curr = curr->next) {
		if (curr->data >= curr->next->data) {
			return false;
		}
	}
	return true;
}

// Solution 2: Recursive Solution
bool listIsSortedRec(struct node *l) {
	// base case(s)
	if (l == NULL || l->next == NULL) {
		return true;
	}

	// recursive case
	if (l->data > l->next->data) {
		return false;
	}

	// we know this node is fine
	return listIsSortedRec(l->next);
}
