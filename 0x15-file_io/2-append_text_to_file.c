#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the file to append the text to
 * @text_content: the content to append into the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int kr, t, s = 0;

	if (!filename)
		return (-1);

	kr = open(filename, O_WRONLY | O_APPEND);
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
