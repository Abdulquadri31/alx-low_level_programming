#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 *
 * Description: This function prints the key-value pairs in the hash table
 *              in the order they appear in the array. Each key-value pair is
 *              printed as 'key': 'value', and the pairs are separated by commas.
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node;
    int first = 1; /* To track if it's the first element printed */

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            if (!first) /* If not the first element, print a comma */
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            first = 0;
            node = node->next;
        }
    }
    printf("}\n");
}
