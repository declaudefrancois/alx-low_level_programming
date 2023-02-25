#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht;
	int i;
	char *value;
	char *items[][2] = {
		{"c", "fun"},
		{"python", "awesome"},
		{"Bob", "and Kris love asm"},
		{"N", "queens"},
		{"98", "Battery Street"},

		{"depravement", "depravement value"},
		{"serafins", "serafins value"},

		{"hetairas", "hetairas value"},
		{"mentioner", "mentioner value"},

		{"joyful", "joyful value"},
		{"synaphea", "synaphea value"},

		{"stylist", "stylist value"},
		{"redescribed", "redescribed value"},

		{"dram", "dram value"},
		{"vivency", "vivency value"},
	};

	ht = hash_table_create(1024);

	for (i = 0; i < 15; i++)
		hash_table_set(ht, items[i][0], items[i][1]);
	for (i = 0; i < 15; i++)
	{
		value = hash_table_get(ht, items[i][0]);
		printf("%s:%s\n", items[i][0], value);
	}

	return (EXIT_SUCCESS);
}
