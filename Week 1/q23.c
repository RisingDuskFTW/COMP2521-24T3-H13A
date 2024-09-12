// Function to delete the first instance of a given value
// from a linked list, if it exists

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

// Solution:
void listDelete(struct list *l, int value) {
    // TODO

    // case 1: if the list is empty
    if (l->head == NULL) {
        return;
    }

    // if the value is the first one in the list
    if (l->head->value == value) {
        struct node *temp = l->head;
        l->head = l->head->next;
        free(temp);
        return;
    }

    // if the value is somewhere else in the list
    struct node *curr = l->head;
    while (curr->next != NULL) {
        if (curr->next->value == value) {
            struct node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            return;
        }
        curr = curr->next;
    }

    // value is not in the list
}
