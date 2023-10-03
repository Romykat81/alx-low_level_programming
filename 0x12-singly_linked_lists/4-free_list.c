#include "main.h"

/*
* free_list - free list
* @head: head of ll
* return: nothing
*/
void free_list(list_t *head)
{
    list_t list;

    while ((list = head) != NULL)
    {
        head = head->next;
        free(list->str);
        free(list);
    }
}