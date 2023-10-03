#include "lists.h"

/*
* sum_listint - returns sum of all nodes
* @head: head
* return: sum of all data
*/
int sum_listint(listint_t *head)
{
    int sum;

    sum = 0;
    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }
    return (sum);
}