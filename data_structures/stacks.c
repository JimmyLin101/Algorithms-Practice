/*
 * Excerpt from Introduction to Algorithm chapter 10
 */
#include <stdio.h>

#define STK_SIZ 8

struct stk_s {
	int top;
	int key[STK_SIZ];
} S = {.top = 0};

int empty(struct stk_s *S)
{
	if (!S->top)
		return 1;
	else
		return 0;
}

void push(struct stk_s *S, int new)
{
	if (S->top >= STK_SIZ) {
		printf("overflow\n");
		return;
	}
	S->key[S->top++] = new;
}

int pop(struct stk_s *S)
{

	if (empty(S)) {
		printf("underflow\n");
		return 0;
	}

	S->top--;
	return S->key[S->top];

}

int main(void)
{
	int i;
	for (i = 1; i < 10; i++) {
		push(&S, i);
	}
	for (i = 1; i < 10; i++) {
		printf("POP: %d\n", pop(&S));
	}
	return 0;
}
