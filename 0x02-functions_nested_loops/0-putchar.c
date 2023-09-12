#include "main.h"
/**
 * main - Entry point
 *
 * Return:  0 (done)
 */

int main(void)
{
	char *str;
	int i;

	str = "_putchar";
	for (i = 0; i < 8; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	return (0);
}
