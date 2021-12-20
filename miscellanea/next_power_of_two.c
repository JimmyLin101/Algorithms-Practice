/*
 * Rounding up to the next power of two
 * https://stackoverflow.com/questions/466204/rounding-up-to-next-power-of-2
 * https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
 * https://jameshfisher.com/2018/03/30/round-up-power-2/
 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t next_pow2_ver1(uint64_t x)
{
	uint64_t p = 1;
	while (p < x) {
		p *= 2;
	}
	return p;
}

uint64_t next_pow2_ver2(uint64_t x)
{
	uint64_t p = 1;
	while (p < x) {
		p <<= 1;
	}
	return p;
}

uint64_t next_pow2_ver3(uint64_t v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	v++;
	return v;
}

int main(void)
{
	printf("Ver 1 %"PRIx64 "\n", next_pow2_ver1(0x1122));
	printf("Ver 2 %"PRIx64 "\n", next_pow2_ver2(0x1122));
	printf("Ver 3 %"PRIx64 "\n", next_pow2_ver3(0x1122));
	return 0;
}

