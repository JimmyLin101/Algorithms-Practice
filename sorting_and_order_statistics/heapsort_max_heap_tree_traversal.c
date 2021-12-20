/*
 * Excerpt from Introduction to Algorithm chapter 6:
 * Heapsort
 */
#include <stdio.h>

#define PARENT(i) (i) >> 1
#define LEFT(i) (i) << 1
#define RIGHT(i) ((i) << 1) + 1

void inorder_tree(int tree[], int node)
{
	if (node < 1 || node > 16)
		return;

	if (tree[node - 1] == -1)
		return;

	int l = LEFT(node);
	inorder_tree(tree, l);

	printf("node: %d\n", tree[node - 1]);

	int r = RIGHT(node);
	inorder_tree(tree, r);
}

void preorder_tree(int tree[], int node)
{
	if (node < 1 || node > 16)
		return;

	if (tree[node - 1] == -1)
		return;

	printf("node: %d\n", tree[node - 1]);
	int l = LEFT(node);
	preorder_tree(tree, l);
	int r = RIGHT(node);
	preorder_tree(tree, r);
}

void postorder_tree(int tree[], int node)
{
	if (node < 1 || node > 16)
		return;

	if (tree[node - 1] == -1)
		return;

	int l = LEFT(node);
	postorder_tree(tree, l);

	int r = RIGHT(node);
	postorder_tree(tree, r);

	printf("node: %d\n", tree[node - 1]);
}

int main(void)
{
	/*
	 * Binary heap data structure is an array that we can vies as a nearly
	 * complete binary tree
	 */
	int bin_heap[16] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1, -1, -1, -1, -1, -1, -1};

	/* Depth First Traversals */
	printf("Inorder (Left, Root, Right)\n");
	inorder_tree(bin_heap, 1);

	printf("Preorder (Root, Left, Right)\n");
	preorder_tree(bin_heap, 1);

	printf("Postorder (Left, Right, Root)\n");
	postorder_tree(bin_heap, 1);


	return 0;
}

