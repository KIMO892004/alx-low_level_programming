#include "main.h"
/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments passed to the program
 * @argv: the array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int kr_r, kr_w, r, a, b;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	kr_r = open(argv[1], O_RDONLY);
	if (kr_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	kr_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((r = read(kr_r, buf, BUFSIZ)) > 0)
	{
		if (kr_w < 0 || write(kr_w, buf, r) != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(kr_r);
			exit(99);
		}
	}

	if (r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	a = close(kr_r);
	b = close(kr_w);
	if (a < 0 || b < 0)
	{
		if (a < 0)
			dprintf(STDERR_FILENO, "Error: Can't close kr %d\n", kr_r);
		if (b < 0)
			dprintf(STDERR_FILENO, "Error: Can't close kr %d\n", kr_w);
		exit(100);
	}

	return (0);
}
