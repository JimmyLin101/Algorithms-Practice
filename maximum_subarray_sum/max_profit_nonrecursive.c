/*
 * Excerpt from Introduction to Algorithm chapter 4:
 * Exercise 4.1-5
 * Kadane's Algorithm
 */
#include <stdio.h>

int main(void)
{
	/* stock price delta */
	int A[] =
		{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int n = sizeof(A) / sizeof(A[0]);

	/*
	 * Kadane's Algorithm is an iteraive dynamic programming algorithm.
	 * MaxSubarraySum[i] = Max(A[i], MaxSubarraySum[i - 1] + A[i])
	 */
	int low_idx = 0, high_idx = 0;

	int tmp_sum = 0;
	int max_so_far = 0;
	for (int i = 0; i <= n - 1; i++) {
		if (A[i] > tmp_sum + A[i]) {
			tmp_sum = A[i];
			low_idx = i;

		} else {
			/* Accumulate temporary sum */
			tmp_sum = tmp_sum + A[i];
		}

		if (max_so_far < tmp_sum) {
			/* Update maximum sum */
			max_so_far = tmp_sum;
			high_idx = i;
		}	
		printf("Index %d, Tmp Sum %d, Max Sum %d\n", i, tmp_sum, max_so_far);
	}

	printf("Maximum subarry L %d, R %d, Sum %d\n", low_idx, high_idx, max_so_far);

	return 0;
}

