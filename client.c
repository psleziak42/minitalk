#include <signal.h>
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

void	signal_handler(int a)
{
	(void)a;
	write(1, "Message Received", 16);
}

void	ft_pid(int a, int x)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (((0x80000000 >> i) & a) != 0)
			kill(x, SIGUSR1);
		else
			kill(x, SIGUSR2);
		usleep(25);
		i++;
	}
}

void	ft_string(char b, int x)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (b != 0)
	{
		if (((128 >> i) & b) != 0)
			kill(x, SIGUSR1);
		else
			kill(x, SIGUSR2);
		usleep(25);
		if (i == 7)
			break ;
		i++;
	}
	while (b == '\0')
	{
		kill(x, SIGUSR2);
		usleep(25);
	}
}

int	main(int a, char *b[])
{
	int	x;
	int	fd;
	char buf;

	fd = open("charmander.xpm", O_RDONLY);
	if (a != 2)
	{
		write(1, "Error Arg", 9);
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	x = ft_atoi((char *)b[1]);
	ft_pid(getpid(), x);
	while (read(fd, &buf, 1))
		ft_string(buf, x);
	ft_string(buf, x); // wysyla \0
}
