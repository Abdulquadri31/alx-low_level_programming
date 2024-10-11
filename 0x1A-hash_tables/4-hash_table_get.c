#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table.
 * @ht: The hash table to look into.
 * @key: The key to search for in the hash table.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *current_node;

    /* Validate input */
    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    /* Get the index of the key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Search for the key in the linked list at the index */
    current_node = ht->array[index];
    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
            return (current_node->value); /* Return the value if key matches */
        current_node = current_node->next;
    }

    /* Return NULL if the key was not found */
    return (NULL);
}
