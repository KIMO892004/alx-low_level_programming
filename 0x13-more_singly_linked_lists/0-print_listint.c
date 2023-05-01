#include "lists.h"

/**
 * print_listint - prints all of the elements of a linked list
 * @k: head of  list
 *
 * Return: the number of the nodes
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

