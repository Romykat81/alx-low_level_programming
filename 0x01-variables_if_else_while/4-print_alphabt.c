#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that prints the alphabet in lowercase followed by a new line
 * 
 * Return: always 0.
 *
 */
int main(void)
{
        char a = 'a';

        while (a <= 'z')
        {
                if (a != 'q' && a!= 'e')
                {
                        putchar(a);
                }
                a++;
        }
        putchar ('\n');
        return (0);
}
