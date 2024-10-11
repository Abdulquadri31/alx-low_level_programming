#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - Adds or updates a key/value pair in a hash table.
 * @ht: The hash table to add or update the key/value in.
 * @key: The key. It cannot be an empty string.
 * @value: The value associated with the key. It is duplicated.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *current_node;
    unsigned long int index;

    /* Validate input */
    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    /* Get the index of the key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Check if the key already exists in the hash table */
    current_node = ht->array[index];
    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            /* Update the value if the key already exists */
            free(current_node->value);
            current_node->value = strdup(value);
            if (current_node->value == NULL)
                return (0);
            return (1);
        }
        current_node = current_node->next;
    }

    /* Create a new node if the key doesn't exist */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    /* Add the new node at the beginning of the list */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
