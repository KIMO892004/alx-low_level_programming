#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: the name of the file to be read
 * @letters: the number of letters to read and print
 *
 * Return: the number of letters printed , or 0 if it failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int kr;
	int s, t;
	char *buf;

	if (!filename)
		return (0);

	kr = open(filename, O_RDONLY);
	if (kr < 0)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);

	s = read(kr, buf, letters);
	if (s < 0)
	{
		free(buf);
		return (0);
	}
	buf[s] = '\0';

	close(kr);

	t = write(STDOUT_FILENO, buf, s);
	if (t < 0)
	{
		free(buf);
		return (0);
	}

	free(buf);
	return (t);
}
