#include "main.h"
/*
*print_list - print elements of list_t
*@h: singly linked list
*return: no. of elements
*/
size_t print_list(const list_t *h)
{
    size_t e;

    e = 0;
    while (h != NULL)
    {
        if (h->str == NULL)
        printf("[%d] %s\n", 0, "(nil)");
        else
        printf("[%d] %s\n", h->len, h->str);
        h = h->next;
        e++;
    }
    return (e);
}
