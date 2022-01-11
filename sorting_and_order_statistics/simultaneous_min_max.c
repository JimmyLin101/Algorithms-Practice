/*
 * Excerpt from Introduction to Algorithm chapter 9
 * and https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
 */
#include <stdio.h>

void show_arr(int A[], int size)
{
	int i;
	printf("   ");
	for (i = 0; i < size; i++)
		printf("%2d ", A[i]);

	printf("\n");
}

/*
 * Using minimum number of comparisions (3 * (n/2))
 */
void find_min_max(int A[], int size, int *min, int *max)
{
	int i;
	if (size & 0x1) {
		/* Old number of size */
		*min = *max = A[0];
		i = 1; /* Set the starting index for loop */

	} else {
		/* Even number of size */
		if (A[0] < A[1]) {
			*min = A[0];
			*max = A[1];
		} else {
			*max = A[0];
			*min = A[1];
		}
		i = 2; /* Set the starting index for loop */
	}

	for (;i < size; i += 2) {
		if (A[i] < A[i+1]) {
			if (A[i] < *min)
				*min = A[i];
			if (A[i+1] > *max)
				*max = A[i+1];

		} else {
			if (A[i+1] < *min)
				*min = A[i+1];
			if (A[i] > *max)
				*max = A[i];
		}
	}
}

int main(void)
{
	int A[10] = {3, 2, 9, 0, 7, 5, 4, 8, 6, 1};
	int B[5] = {5, 4, 8, 6, 1};

	int len = sizeof(A) / sizeof(int);
	printf("Array A:\n");
	show_arr(A, len);

	int min, max;
	find_min_max(A, len, &min, &max);
	printf("Minimum %d, Maximum %d\n", min, max);

	len = sizeof(B) / sizeof(int);
	printf("Array B:\n");
	show_arr(B, len);
	find_min_max(B, len, &min, &max);
	printf("Minimum %d, Maximum %d\n", min, max);

	return 0;
}
