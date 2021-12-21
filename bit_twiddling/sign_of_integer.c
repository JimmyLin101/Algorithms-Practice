/*
 * Compute the sign of an integer
 * https://stackoverflow.com/questions/14579920/fast-sign-of-integer-in-c
 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>


int main(void)
{
	int v = -123; // we want to find the sign of v
	int sign; // the result goes here 

	// CHAR_BIT is the number of bits per byte (normally 8).

	sign = -(v < 0);  // if v < 0 then -1, else 0. 
	// or, to avoid branching on CPUs with flag registers (IA32):
	printf("Sign v1 %d\n", sign);

	sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
	printf("Sign v2 %d\n", sign);

	// or, for one less instruction (but not portable):
	sign = v >> (sizeof(int) * CHAR_BIT - 1); 
	printf("Sign v3 %d\n", sign);

	sign = (v > 0) - (v < 0);
	printf("Sign v4 %d\n", sign);
	return 0;
}

