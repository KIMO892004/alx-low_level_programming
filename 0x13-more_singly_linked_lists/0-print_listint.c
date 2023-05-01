#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @k: head of the list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *k)
{
const listint_t *cursor = k;
size_t count = 0;

while (cursor != NULL)
{
printf("%d\n", cursor->n);
count += 1;
cursor = cursor->next;
}
return (count);
}
