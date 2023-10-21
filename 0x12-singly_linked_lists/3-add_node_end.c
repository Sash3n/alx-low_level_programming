#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: The string to be inserted into the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node;
    list_t *last = *head; // Used to traverse to the last node
    unsigned int len = 0;

    if (str == NULL)
        return (NULL);

    new_node = (list_t *)malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    while (str[len])
        len++;

    new_node->len = len;
    new_node->next = NULL;

    // If the list is empty, then make the new node the head
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    // Traverse to the last node
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;

    return (new_node);
}
