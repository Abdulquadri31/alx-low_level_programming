#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the new sorted hash table, or NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(hash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;
    ht->head = NULL;
    ht->tail = NULL;

    return (ht);
}

/**
 * shash_table_set - Adds or updates an element in the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key of the element.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *current, *prev;
    char *value_copy;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    value_copy = strdup(value);
    if (value_copy == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
    {
        free(value_copy);
        return (0);
    }

    new_node->key = strdup(key);
    new_node->value = value_copy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Inserting in the sorted linked list */
    if (ht->head == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        ht->head = new_node;
        ht->tail = new_node;
    }
    else
    {
        current = ht->head;
        prev = NULL;
        while (current && strcmp(key, current->key) > 0)
        {
            prev = current;
            current = current->next;
        }

        new_node->next = current;
        new_node->prev = prev;

        if (current)
            current->prev = new_node;

        if (prev == NULL)
            ht->head = new_node;
        else
            prev->next = new_node;

        if (current == NULL)
            ht->tail = new_node;
    }
    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if the key is not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];
    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table in ascending order.
 * @ht: The sorted hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
    hash_node_t *node;
    int comma_flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->head;
    while (node)
    {
        if (comma_flag)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        comma_flag = 1;
        node = node->next;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order.
 * @ht: The sorted hash table.
 */
void hash_table_print_rev(const hash_table_t *ht)
{
    hash_node_t *node;
    int comma_flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->tail;
    while (node)
    {
        if (comma_flag)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        comma_flag = 1;
        node = node->prev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_node_t *node, *temp;

    if (ht == NULL)
        return;

    node = ht->head;
    while (node)
    {
        temp = node->next;
        free(node->key);
        free(node->value);
        free(node);
        node = temp;
    }

    free(ht->array);
    free(ht);
}
