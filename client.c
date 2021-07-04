#include <signal.h>
#include "libft.h"

void	signal_handler(int a)
{
	(void)a;
	write(1, "Message Received", 16);
}

int	ft_pid(int a, int x)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (((0x80000000 >> i) & a) != 0)
		{
			if (kill(x, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(x, SIGUSR2) == -1)
				return (0);
		}
		usleep(25);
		i++;
	}
	return (1);
}

void	ft_string(char *b, int x)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (b[j] != '\0')
	{
		if (((128 >> i) & b[j]) != 0)
			kill(x, SIGUSR1);
		else
			kill(x, SIGUSR2);
		usleep(25);
		if (i == 7)
		{
			i = 0;
			j++;
		}
		else
			i++;
	}
	while (++i < 9)
	{
		kill(x, SIGUSR2);
		usleep(25);
	}
}

int	main(int a, char *b[])
{
	int	x;

	if (a != 3)
	{
		write(1, "Error Arg", 9);
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	x = ft_atoi((char *)b[1]);
	if (!ft_pid(getpid(), x))
	{
		write(1, "Retype Server's PID", 19);
		return (0);
	}
	ft_string(b[2], x);
	return (0);
}
