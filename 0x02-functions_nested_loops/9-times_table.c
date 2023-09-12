#include "main.h"
/**
 * times_table - prints the times table from 0 - 9.
 *
 * Return: void
 */
void times_table(void)
{
	int rows, columns, times;

	for (rows = 0; rows <= 9; rows++)
	{
		for (columns = 0; columns <= 9; columns++)
		{
			times = (rows * columns);
			if (columns != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (times >= 10)
			{
				_putchar((times / 10) + '0');
				_putchar((times % 10) + '0');
			}
			else if (times < 10 && columns != 0)
			{
				_putchar(' ');
				_putchar((times % 10) + '0');
			}
			else
				_putchar((times % 10) + '0');
		}
		_putchar('\n');
	}
}
