#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The unsigned long integer.
 */
void print_binary(unsigned long int n)
{
	int i = sizeof(n) * 8 - 1;
	int bit_printed = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (i >= 0)
	{
		if (n & (1UL << i))
		{
			_putchar('1');
			bit_printed = 1;
		}
		else if (bit_printed)
		{
			_putchar('0');
		}
		i--;
	}
}
