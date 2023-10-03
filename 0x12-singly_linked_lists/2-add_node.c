#include "main.h"

/*
* add_node - adds a new node
* @head: head of linked list
* @str: str to store in the list
* return: address head
*/
list_t *add_node(list_t **head, const char *str)
{
    list_t *new;
    size_t i;

    new = malloc(sizeof(list_t));
        if (new == NULL)
            return (NULL);

    new->str = strdup(str);

    for (i = 0; str[i]; i++)
       ;
        
    new->len = i;
    new->len = *head;
    *head = new;

   return (*head);
}