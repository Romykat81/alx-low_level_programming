#include "main.h"

/*
* add_node_end - adds a new node
* @head: head of ll
* @str: str to store list
* return: address head
*/
list_t *add_node_end(list_t **head, const char *str)
{
    list_t list, *temp;
    size_t i;

    list = malloc(sizeof(list_t));
    if (list == NULL)
        return (NULL);

    list->str = stdup(str);

    for (i = 0; str[i]; i++)
        ;

        list->len - i;
        list->next = NULL;
        temp = *head;

        if (temp == NULL)
        {
            *head = list;
        }
        else
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new;
        }
        return (*head);
}