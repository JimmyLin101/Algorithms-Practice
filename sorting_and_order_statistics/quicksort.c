/*
 * Excerpt from Introduction to Algorithm chapter 7:
 * Quicksort
 */
#include <stdio.h>
#include <stdint.h>

#define SWAP(x, y) {x ^= y; y ^= x; x ^= y;}

void show_arr(int A[], int size)
{
	int i;
	printf("   ");
	for (i = 0; i < size; i++)
		printf("%2d ", A[i]);

	printf("\n");
}

void partition(int A[], int p, int r)
{
	int i, j;
	i = p - 1;
	/* A[r] is a pivot element */
	if (p >= r)
		return;

	printf("quick sort: p = %d, r = %d\n", p, r);
	show_arr(A, 8);
	printf("\n");

	/*
	 * For any array index k,
	 * 1. If p <= k <= i, then A[k] <= x
	 * 2. If i + 1 <= k <= j - 1, then A[k] < x.
	 * 3. If k = r, then A[k] = x.
	 */
	for (j = p; j < r; j++) {
		/* if A[j] > A[r], after j is incremented, it still satifies condition 2. */
		if (A[j] < A[r]) {
			i++;
			if (i != j) {
				SWAP(A[i], A[j]);
				printf("%*ci%*cj (Swap i, j)\n",
					4 + 3 * i, ' ',
					(4 + 3 * j) - (5 + 3 * i), ' ');
				show_arr(A, 8);
			}

		}
	}
	i += 1;
	if (i != r) {
		printf("%*ci%*cr (Swap i, r)\n",
			4 + 3 * i, ' ',
			(4 + 3 * r) - (5 + 3 * i), ' ');
			SWAP(A[i], A[r]);
	}

	partition(A, 0, i - 1);
	partition(A, i + 1, r);

}

int main(void)
{
	int A[8] = {2, 8, 7, 1, 3, 5, 6, 4};
	partition(A, 0, 7);

	return 0;
}

