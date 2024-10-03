// Find the level that a given value is in the tree

#include <stdio.h>

struct node {
	int value;
	struct node *left;
	struct node *right;
};

int BSTNodeLevel(struct node *t, int key) {
    // TODO
	struct node *curr = t;
	int level = 0;
	while (curr != NULL) {
		if (key < t->value) {
			curr = curr->left;
		} else if (key > t->value) {
			curr = curr->right;
		} else {
			break;
		}
		level++;
	}
    return level;
}
