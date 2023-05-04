#include "main.h"

/**
 * get_bit - A function that gets a bit at index
 * @n: The number to index
 * @index: the bit to get
 * Return: The value of the bit or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int maximum = 0x01;

	maximum <<= index;
	if (maximum == 0)
		return (-1);

	if ((n & maximum))
		return (1);
	else
		return (0);
}
