#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *head1;

	head = NULL;
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	add_dnodeint_end(&head, 4);
	add_dnodeint_end(&head, 98);
	add_dnodeint_end(&head, 402);
	add_dnodeint_end(&head, 1024);
	print_dlistint(head);
	printf("-----------------\n");
	insert_dnodeint_at_index(&head, 5, 4096);
	print_dlistint(head);
	free_dlistint(head);
	head = NULL;

	head1 = NULL;
	print_dlistint(head1);
        printf("-----------------\n");
        insert_dnodeint_at_index(&head1, 0, 12);
        insert_dnodeint_at_index(&head1, 2, 4096);
        insert_dnodeint_at_index(&head1, 0, 11);
	print_dlistint(head1);
        printf("-----------------\n");
        insert_dnodeint_at_index(&head1, 0, 10);
	print_dlistint(head1);
        printf("-----------------\n");
        insert_dnodeint_at_index(&head1, 3, 13);
        print_dlistint(head1);
	free_dlistint(head1);
	head1 = NULL;
	return (EXIT_SUCCESS);
}
