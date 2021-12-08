#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int fd;
	int fd2;
	char buf;

	buf = 0;
	if (argc != 4)
	{
		printf("Error args");
		return (-1);
	}
	if (!strncmp(argv[1], "cp", 3))
	{
		fd = open(argv[2], O_RDONLY);
		fd2 = open(argv[3], O_CREAT | O_WRONLY | O_APPEND, 0700);
		while (read(fd, &buf, 1))
			write(fd2, &buf, 1);
		close(fd);
		close(fd2);
	}
	else
	{
		printf("unrecognized system call: %s\n", argv[1]);
		return (-1);
	}
}
