#include "function_pointers.h"

/**
 * print_kamal - prints a kamal
 * @kamal: the string name
 * @k: the printing function pointer
 *
 * Return: void
 */
void print_kamal(char *kamal, void (*k)(char *))
{
	if (kamal && k)
		k(kamal);
}
