#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 *
 * Description: This function deletes the entire hash table by freeing all the
 *              memory associated with the hash table, including each node's key
 *              and value, and then the array and hash table structure itself.
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node->next;
            free(node->key);  /* Free the key */
            free(node->value); /* Free the value */
            free(node);        /* Free the node */
            node = temp;
        }
    }
    free(ht->array); /* Free the array of the hash table */
    free(ht);        /* Free the hash table structure */
}
