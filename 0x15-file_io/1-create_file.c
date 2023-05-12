#include "main.h"
/**
 * create_file - creates a file and fills it with text
 * @filename: the name of the file to create
 * @text_content: the text to write in the file
 *
 * Return: 1 on success , -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int kr, t, s = 0;

	if (!filename)
		return (-1);

	kr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (kr < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[s])
			s++;
		t = write(kr, text_content, s);
		if (t != s)
			return (-1);
	}

	close(kr);

	return (1);
}
