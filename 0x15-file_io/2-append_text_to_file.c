#include "main.h"
/**
 * append_text_to_file - add data to the end of a file.
 * @filename: pointer to the file name
 * @text_content: amount of data to append to file
 * Return: 1 when success or -1 otherwise
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int myFile, letters, writeing;

	if (filename == 0)
	{
		return (-1);
	}
	myFile = open(filename, O_WRONLY | O_APPEND);
	if (myFile == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		for (letters = 0; text_content[letters]; letters++)
		{

		}

		writeing = write(myFile, text_content, letters);
		if (writeing == -1)
		{
			return (-1);
		}
	}
	close(myFile);
	return (1);
}
