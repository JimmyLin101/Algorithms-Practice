/*
 * Excerpt from Introduction to Algorithm chapter 10
 */
#include <stdio.h>

#define STK_SIZ 8

struct queue_s {
	int head;
	int tail;
	int key[STK_SIZ];
} Q = {.head = 0, .tail = 0};


void enqueue(struct queue_s *Q, int x)
{
	/* Queue is full if only the most significat bit is different */
	if (Q->head == (Q->tail ^ STK_SIZ)) { /* inverts the most significant bit of start */
		printf("overflow\n");
		return;
	}
	Q->key[Q->tail & (STK_SIZ - 1)] = x; /* modulus of size - 1 */
	Q->tail++;
	Q->tail &= (2 * STK_SIZ - 1); /* modulus of 2*size */
}

int dequeue(struct queue_s *Q)
{
	if (Q->head == Q->tail) {
		printf("underflow\n");
		return 0;
	}

	int x = Q->key[Q->head & (STK_SIZ - 1)]; /* modulus of size - 1 */
	Q->head++;
	Q->head &= (2 * STK_SIZ - 1); /* modulus of 2*size */
	return x;
}

int main(void)
{
	int i;
	for (i = 1; i < 10; i++) {
		enqueue(&Q, i);
	}
	for (i = 1; i < 10; i++) {
		printf("Dequeue: %d\n", dequeue(&Q));
	}
	return 0;
}
