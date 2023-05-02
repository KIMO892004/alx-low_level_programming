#ifndef _LISTS_
#define _LISTS_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @k: integer
 * @nextt: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listint_s
{
	int k;
	struct listint_s *nextt;
} listint_t;

/**
 * struct listp_s - singly linked list
 * @pointer: pointers of nodes
 * @nextt: points to the next node
 *
 * Description: singly linked list of pointers
 */
typedef struct listp_s
{
	void *pointer;
	struct listp_s *nextt;
} listp_t;

size_t print_listint(const listint_t *r);
size_t listint_len(const listint_t *r);
listint_t *add_nodeint(listint_t **head, const int k);
listint_t *add_nodeint_end(listint_t **head, const int k);
void free_listint(listint_t *head);
void free_listint2(listint_t **head);
int pop_listint(listint_t **head);
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
int sum_listint(listint_t *head);
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int k);
int delete_nodeint_at_index(listint_t **head, unsigned int index);
listint_t *reverse_listint(listint_t **head);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **r);
listint_t *find_listint_loop(listint_t *head);

#endif
