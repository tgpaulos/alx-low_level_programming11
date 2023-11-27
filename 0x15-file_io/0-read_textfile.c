#include <stdio.h>
#include "main.h"

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: letters to be read
 * Return: bytesWritten
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	char *buffer;
	ssize_t bytesRead;
	ssize_t bytesWritten;

	if (filename == NULL)
	{
		return (0);
	}
	file = open(filename, O_RDONLY);

	if (file == -1)
	{
		return (0);
	}
	buffer = (char *) malloc(letters);

	if (buffer == NULL)
	{
		close(file);
		return (0);
	}
	bytesRead = read(file, buffer, letters);

	if (bytesRead <= 0)
	{
		close(file);
		free(buffer);
		return (0);
	}
	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	close(file);
	free(buffer);

	if (bytesWritten != bytesRead)
	{
		return (0);
	}
	return (bytesWritten);
}
