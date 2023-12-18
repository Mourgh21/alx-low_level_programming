#include <stdio.h>
#include "main.h"
/**
 * errorLine - provide error massage relating to the case.
 * @file_from: source file
 * @file_to: destination file
 * @argv: argument vector
 */
void errorLine(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - copy contents of a file to another file.
 * @argv: argument vector
 * @argc: argument count
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, error_close;
	ssize_t letters, writing;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	errorLine(file_from, file_to, argv);
	letters = 1024;
	while (letters == 1024)
	{
		letters = read(file_from, buf, 1024);
		if (letters == -1)
		{
			errorLine(-1, 0, argv);
		}
		writing = write(file_to, buf, letters);
		if (writing == -1)
		{
			errorLine(0, -1, argv);
		}
	}
	error_close = close(file_from);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	error_close = close(file_to);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
