/*
 * Excerpt from Introduction to Algorithm chapter 8:
 * Counting sort assumes that each of the n input elements is an integer in the
 * range 0 to k.
 */
#include <stdio.h>
#include <stdint.h>

#define ARRAY_LEN 8
#define MAX_E 5

void show_arr(int A[], int size)
{
	int i;
	printf("   ");
	for (i = 0; i < size; i++)
		printf("%2d ", A[i]);

	printf("\n");
}

void counting_sort(int A[], int B[], int k)
{
	int C[MAX_E + 1] = {0}; /* Initializes the array C to all zeros */

	int j;
	for (j = 0; j < ARRAY_LEN; j++) {
		C[A[j]]++;
	}
	printf("C[i] contains the number of elements equal to i\n");
	show_arr(C, MAX_E + 1);

	int i;
	for (i = 1; i <= MAX_E; i++) {
		C[i] = C[i] + C[i - 1];
	}
	printf("C[i] contains the number of elements less than or equal to i\n");
	show_arr(C, MAX_E + 1);

	for (j = ARRAY_LEN - 1; j >= 0; j--) {
		printf("Move A[%d] to position %d of B\n", j, C[A[j]] - 1);
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
}

int main(void)
{
	int A[ARRAY_LEN] = {2, 5, 3, 0, 2, 3, 0, 3};
	printf("Array A:\n");
	show_arr(A, ARRAY_LEN);
	int B[ARRAY_LEN] = {0};
	counting_sort(A, B, MAX_E); /* Maximum number is 5 = k */

	printf("Array B:\n");
	show_arr(B, ARRAY_LEN);

	return 0;
}

