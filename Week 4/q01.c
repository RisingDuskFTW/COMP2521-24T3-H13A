// Using a Stack ADT

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct queue {
	Stack s1;
	Stack s2;
};

typedef struct queue *Queue;

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueFree(Queue q) {
	StackFree(q->s1);
	StackFree(q->s2);
	free(q);
}

void QueueEnqueue(Queue q, int item) {
	StackPush(q->s1, item);
}

int QueueDequeue(Queue q) {
	// move everything from s1 to s2
	while (!StackIsEmpty(q->s1)) {
		int item = StackPop(q->s1);
		StackPush(q->s2, item);
	}
	// we will be able to remove the item we want
	int ret = StackPop(q->s2);
	// move everything back
	while (!StackIsEmpty(q->s2)) {
		int item = StackPop(q->s2);
		StackPush(q->s1, item);
	}
	return ret;
}
