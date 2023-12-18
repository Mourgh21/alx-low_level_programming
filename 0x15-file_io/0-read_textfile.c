#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"
/**
 * read_textfile - read certain number of chars of file.
 * @filename: pointer to file to read from
 * @letters: number of chars to output
 * Return: 0 or numbers of chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int myFile;
	ssize_t isread, iswrite;
	char *hold;

	if (filename == 0)
	{
		return (0);
	}
	myFile = open(filename, O_RDONLY);
	if (myFile == -1)
	{
		return (0);
	}
	hold = malloc(sizeof(char) * letters);
	if (hold == 0)
	{
		close(myFile);
		return (0);
	}
	isread = read(myFile, hold, letters);
	close(myFile);
	if (isread == -1)
	{
		free(hold);
		return (0);
	}
	iswrite = write(STDOUT_FILENO, hold, isread);
	if (isread != iswrite)
	{
		return (0);
	}
	return (iswrite);
}
