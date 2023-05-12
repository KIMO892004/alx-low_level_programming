#include "main.h"

/**
 * main - entry point
 * description: copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the array of arguments
 * Return: 0 on success, 97-100 on failure
 */
int main(int argc, char *argv[])
{
	int kr_from, kr_to, read_bytes, write_bytes;
	char buf[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	kr_from = open(argv[1], O_RDONLY);
	if (kr_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	kr_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (kr_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((read_bytes = read(kr_from, buf, 1024)) > 0)
	{
		write_bytes = write(kr_to, buf, read_bytes);
		if (write_bytes == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(kr_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", kr_from), exit(100);

	if (close(kr_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", kr_to), exit(100);

	return (0);
}
