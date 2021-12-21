/*
 * Compute the integer absolute value (abs) without branching
 * https://www.techiedelight.com/bit-hacks-part-5-find-absolute-value-integer-without-branching/
 */
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main(void)
{
	int v = -7; // we want to find the absolute value of v
	unsigned int r; // the result goes here 
	int const mask = v >> sizeof(int) * CHAR_BIT - 1;
	/*
	 * For negative number mask will be all 1 (sign extension)
	 * For positive number mask will be all 0
	 */

	/*
	 * A negative number is represented by (flipping all the bits) and (addding 1)
	 * -n = ~n + 1;
	 */
	r = (v ^ mask) - mask;
	printf("Flip and add 1: %d\n", r);

	/*
	 * To get positive counterpart of a negative number,
	 * subtract 1 (v + mask)
	 * and flip its bits (^ mask)
	 */
	r = (v + mask) ^ mask;
	printf("Subtract 1 and flip: %d\n", r);

	return 0;
}

