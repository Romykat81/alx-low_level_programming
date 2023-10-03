#include "lists.h"

/*
* find_listint_loop - find loop in ll
* @head: head
* return: addr of node
*/
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *p;
    listint_t pre;

    p = head;
    pre = head;
    while (head && p && p->next)
    {
        head = head->next;
        p = p->next;

        if (head == p)
        {
            head = pre;
            pre = p;
            while (1)
            {
                p = pre;
                while (p->next != head && p->next != pre)
                {
                    p = p->next;
                }
                if (p->next == head)
                    break;
                
                head = head->next;
            }
            return (p->next);
        }
    }
    return (NULL);
}