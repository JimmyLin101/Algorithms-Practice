/*
 * Excerpt from Introduction to Algorithm chapter 10
 */
#include <stdio.h>
#include <stdlib.h>


struct lnk_e {
	int key;
	struct lnk_e *prev;
	struct lnk_e *next;
};

/*
 * Singly doubly linked list
 */
struct S_LS_s {
	struct lnk_e *head;
} S_LS = { .head = NULL };

void show_sl(struct S_LS_s *ls)
{
	if (!ls)
		return;

	struct lnk_e *x = ls->head;
	while (x) {
		printf("%d->", x->key);
		x = x->next;		
	}
	printf("Null\n");
}

void insert_sl(struct S_LS_s *ls, struct lnk_e *new)
{
	new->next = ls->head;
	if (ls->head)
		ls->head->prev = new;

	ls->head = new;
	new->prev = NULL;
}

struct lnk_e* search_sl(struct S_LS_s *ls, int key)
{
	struct lnk_e *x = ls->head;
	while (x) {
		if (x->key == key)
			return x;

		x = x->next;		
	}
	return x;
}

void delete_sl(struct S_LS_s *ls, struct lnk_e* x)
{
	if (x->prev)
		x->prev->next = x->next;
	else
		ls->head = x->next;

	if (x->next)
		x->next->prev = x->prev;
}

/*
 * Circular doubly linked list
 */
struct C_LS_s {
	struct lnk_e nil;
};

void show_cl(struct C_LS_s *ls)
{
	if (!ls)
		return;

	struct lnk_e *x = ls->nil.next;
	while (x != &ls->nil) {
		printf("%d->", x->key);
		x = x->next;		
	}
	printf("Null\n");
}

void insert_cl(struct C_LS_s *ls, struct lnk_e *new)
{
	new->next = ls->nil.next;
	ls->nil.next->prev = new;
	ls->nil.next = new;
	new->prev = &ls->nil;
}

struct lnk_e* search_cl(struct C_LS_s *ls, int key)
{
	struct lnk_e *x = ls->nil.next;
	while (x != &ls->nil && x->key != key) {
		x = x->next;		
	}
	return x;
}

void delete_cl(struct C_LS_s *ls, struct lnk_e* x)
{
	if (x == &ls->nil)
		return;

	x->next->prev = x->prev;
	x->prev->next = x->next;
}

int main(void)
{
	struct lnk_e *new = malloc(sizeof(struct lnk_e));
	new->key = 1;
	insert_sl(&S_LS, new);

	new = malloc(sizeof(struct lnk_e));
	new->key = 4;
	insert_sl(&S_LS, new);

	new = malloc(sizeof(struct lnk_e));
	new->key = 16;
	insert_sl(&S_LS, new);
	
	new = malloc(sizeof(struct lnk_e));
	new->key = 9;
	insert_sl(&S_LS, new);

	printf("\nSingly Linked List:\n");
	show_sl(&S_LS);

	printf("\n----- Insert 25 -----\n");
	new = malloc(sizeof(struct lnk_e));
	new->key = 25;
	insert_sl(&S_LS, new);
	show_sl(&S_LS);

	printf("\n----- Delete 4 -----\n");
	struct lnk_e *p = search_sl(&S_LS, 4);
	delete_sl(&S_LS, p);
	free(p);
	show_sl(&S_LS);

	struct C_LS_s C_LS;
	C_LS.nil.next = C_LS.nil.prev = &C_LS.nil;

	new = malloc(sizeof(struct lnk_e));
	new->key = 1;
	insert_cl(&C_LS, new);

	new = malloc(sizeof(struct lnk_e));
	new->key = 4;
	insert_cl(&C_LS, new);

	new = malloc(sizeof(struct lnk_e));
	new->key = 16;
	insert_cl(&C_LS, new);

	new = malloc(sizeof(struct lnk_e));
	new->key = 9;
	insert_cl(&C_LS, new);

	printf("\nCircular Linked List:\n");
	show_cl(&C_LS);

	printf("\n----- Insert 25 -----\n");
	new = malloc(sizeof(struct lnk_e));
	new->key = 25;
	insert_cl(&C_LS, new);
	show_cl(&C_LS);

	printf("\n----- Delete 1 -----\n");
	p = search_cl(&C_LS, 1);
	delete_cl(&C_LS, p);
	show_cl(&C_LS);

	return 0;
}
