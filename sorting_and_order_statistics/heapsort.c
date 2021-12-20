/*
 * Excerpt from Introduction to Algorithm chapter 6:
 * Heapsort
 */
#include <stdio.h>
#include <stdint.h>

#define PARENT(i) (i) >> 1
#define LEFT(i) (i) << 1
#define RIGHT(i) ((i) << 1) + 1

#define SWAP(x, y) {x ^= y; y ^= x; x ^= y;}
#if 0
#define SWAP(x, y) (x ^= y ^= x ^=y)
#endif

/*
 * https://stackoverflow.com/questions/466204/rounding-up-to-next-power-of-2
 * https://jameshfisher.com/2018/03/30/round-up-power-2/
 */
static uint32_t next_pow2(uint32_t x)
{
	x -= 1;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x += 1;
  return x;
}

void show_tree(int tree[], uint32_t size)
{
	int len_n = next_pow2(size);
	int i, j;
	for (i = 1; i < size; i *=2) {
		for (j = i; j < i * 2; j++) {
			if (j > size) {
				printf("\n");
				return;
			}
			printf("%*s%d ", len_n / (j + 1), " ", tree[j - 1]);
		}
		printf("\n");
	}
}

void maintain_heap_tree(int A[], int i, int heap_size)
{

	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	/* Compare with Left child */
	if (l <= heap_size && A[l - 1] > A[i - 1])
		largest = l;
	else
		largest = i;

	/* Compare with Right child */
	if (r  <= heap_size && A[r - 1] > A[largest - 1])
		largest = r;

	/* Switch node */
	if (largest != i) {
		SWAP(A[i - 1], A[largest - 1]);
		maintain_heap_tree(A, largest, heap_size);
	}
}

void build_heap_tree(int A[], int heap_size)
{
	int i;
	for (i = heap_size /2; i >= 1; i--) {
		maintain_heap_tree(A, i, heap_size);
	}

}

void heapsort(int A[], int heap_size)
{
	build_heap_tree(A, heap_size);
	printf("Build Max heap tree:\n");
	show_tree(A, heap_size);

	int i;
	for (i = heap_size; i >= 1; i--) {
		printf("Output [%d] and heapify it:\n", A[0]);

		SWAP(A[1 - 1], A[i - 1]);
		heap_size -= 1;
		maintain_heap_tree(A, 1, heap_size);
		show_tree(A, heap_size);
	}

}

int main(void)
{
	/*
	 * Binary heap data structure is an array that we can vies as a nearly
	 * complete binary tree
	 */
	uint32_t heap_size = 10;
	int bin_heap[16] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, -1, -1, -1, -1, -1, -1};
	printf("Input data:\n");
	show_tree(bin_heap, heap_size);

	heapsort(bin_heap, heap_size);

	return 0;
}

