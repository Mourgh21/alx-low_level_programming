#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - print all integer numbers, begin from input number stop at 98.
 * @n: the input number
 * Return: void
 */
void print_to_98(int n)
{
	if (n < 98)
	{
		for (n = n; n < 98; n++)
			printf("%d, ", n);
		printf("%d\n", 98);
	}
	else if (n > 98)
	{
		for (n = n; n > 98; n--)
			printf("%d, ", n);
		printf("%d\n", 98);
	}
	else
		printf("%d\n", 98);
}
