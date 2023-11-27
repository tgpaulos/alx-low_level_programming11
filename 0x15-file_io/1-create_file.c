#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 * Return: 1 on success, -1 on failure
 */

vint create_file(const char *filename, char *text_content)
{
	int length;
	int fd;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		length = 0;

		while (text_content[length] != '\0')
			length++;

		if (write(fd, text_content, length * sizeof(char)) == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

