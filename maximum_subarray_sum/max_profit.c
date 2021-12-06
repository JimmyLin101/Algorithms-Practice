/*
 * Excerpt from Introduction to Algorithm chapter 4:
 * Divide-and-conquer to find maximum profit
 */
#include <stdio.h>
#include <limits.h>
#include <math.h>

/*
 * Find a maximum subarray crossing the midpoint
 */
void find_max_crossing_subarray(
	int A[], int low, int mid, int high,
	int *p_low, int *p_hight, int *p_sum)
{
	int lef_sum = INT_MIN;
	int sum = 0;
	int i, max_lef;
	for (i = mid; i >= low; i--) {
		sum = sum + A[i];
		if (sum > lef_sum) {
			lef_sum = sum;
			max_lef = i;
		}
	}

	int right_sum = INT_MIN;
	sum = 0;
	int j, max_right;
	for (j = mid + 1; j <= high; j++) {
		sum = sum + A[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	*p_low = max_lef;
	*p_hight = max_right;
	*p_sum = lef_sum + right_sum;
}

void find_maximum_subarray(
	int A[],int low, int high,
	int *p_low, int *p_hight, int *p_sum)
{
	static int recursion_depth = 0;
    ++recursion_depth;
	if (high == low) {
		*p_low = low;
		*p_hight = high;
		*p_sum = A[low];
		printf("Deep %d, Indx %d, Sum %d\n", recursion_depth, high, A[low]);
		--recursion_depth;
		return;
	}
	/* else */
	int mid = floor(low + high) / 2;
	printf("Deep %d, low %d, high %d, mid = %d\n",
		recursion_depth, low, high, mid);

	/* Left */
	int l_l, l_h, l_sum;
	find_maximum_subarray(A, low, mid, &l_l, &l_h, &l_sum);

	/* Right */
	int r_l, r_h, r_sum;
	find_maximum_subarray(A, mid + 1, high, &r_l, &r_h, &r_sum);

	/* Cross  midpoint */
	int cross_l, cross_h, cross_sum;
	find_max_crossing_subarray(A, low, mid, high, &cross_l, &cross_h, &cross_sum);

	printf("Deep %d, L Sub %d, R Sub %d, Cross Sub= %d\n",
		recursion_depth, l_sum, r_sum, cross_sum);

	if (l_sum >= r_sum && l_sum >= cross_sum) {
		*p_low = l_l;
		*p_hight = l_h;
		*p_sum = l_sum;
	} else if (r_sum >= l_sum && r_sum > cross_sum) {
		*p_low = r_l;
		*p_hight = r_h;
		*p_sum = r_sum;
	} else {
		*p_low = cross_l;
		*p_hight = cross_h;
		*p_sum = cross_sum;
	}
	--recursion_depth;
}


int main(void)
{
	/* stock price delta */
	int A[16] =
		{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int n = sizeof(A) / sizeof(A[0]);

	int i;
	printf("Stock Price delta are :\n");
	for (i = 0; i < n; i++) {
		printf("%02d ", A[i]);
	}
	printf("\n\n");
	int low_idx, high_idx, sum;
	find_maximum_subarray(A, 0, n - 1, &low_idx, &high_idx, &sum);
	printf("Maximum subarray L %d, R %d, Sum %d\n", low_idx, high_idx, sum);
}

