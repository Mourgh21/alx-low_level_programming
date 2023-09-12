#include "main.h"
/**
 * _islower - Check code
 * @c: An input character
 * Description: function uses _putchar function to print
 * _islower in lowercase 10 times
 * Return: 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
