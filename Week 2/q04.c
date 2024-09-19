// Recursive function to delete the first instance of a given value
// from a linked list, if it exists

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

// Recursive Solution
struct node *listDelete(struct node *l, int value) {

    // base case
    if (l == NULL) {
        return NULL;
    }

    // is this the node to delete?
    if (l->data == value) {
        struct node *rest = l->next;
        free(l);
        return rest;
    }

    // recursive case
    struct node *rest = listDelete(l->next, value);
    l->next = rest;
    return l;
}
