#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list.
 * @head: The head of the linked list.
 */
void free_list(list_t *head)
{
    list_t *temp;

    while (head != NULL)
    {
        temp = head;           // Save the current node
        head = head->next;     // Move to the next node
        free(temp->str);       // Free the duplicated string
        free(temp);            // Free the current node
    }
}

