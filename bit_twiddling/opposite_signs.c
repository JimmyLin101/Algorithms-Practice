/*
 * Detect if two integers have opposite signs
 */
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main(void)
{
	int x = 12, y = -34; // input values to compare signs

	printf("The leftmost bit of X = %d, Y = %d\n",
		x >> (sizeof(int) * CHAR_BIT - 1),
		y >> (sizeof(int) * CHAR_BIT - 1));

	bool f = ((x ^ y) < 0); // true iff x and y have opposite signs
	printf("The negative result of XOR sign bit"
			"indicates that x and y have opposite signs, %d\n", f);
	return 0;
}

