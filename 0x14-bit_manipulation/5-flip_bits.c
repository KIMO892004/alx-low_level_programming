#include "main.h"

/**
 * flip_bits - return number of bits that would need to be flipped to
 * transform one number to another
 *
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits to flip to convert numbers
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int kamal = n ^ m;
	unsigned int k = 0;

	while (kamal)
	{
		if (kamal & 1ul)
			k++;
		kamal = kamal >> 1;
	}
	return (k);
}
