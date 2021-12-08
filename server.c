#include "libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>

int	g_x;

void	ft_string_handler(int a, int *j)
{
	static char	b;
	static int	i;

	if (a == SIGUSR1)
		b = b | (0x80 >> i);
	i++;
	if (i == 8)
	{	
		if (b == 0x00)
		{
			i = 0;
			b = 0;
			*j = 0;
			kill(g_x, SIGUSR1);
			g_x = 0;
			return ;
		}
		write(1, &b, 1);
		i = 0;
		b = 0;
	}
}

void	ft_pid_handler(int a)
{
	static int	j;

	if (j < 32)
	{
		if (a == SIGUSR1)
			g_x = g_x | (0x80000000 >> j);
		j++;
		return ;
	}
	ft_string_handler(a, &j);
}		

int	main(void)
{
	pid_t	process_id;
	int		fd;

	fd = open("charmander_copy.xpm", O_CREAT | O_WRONLY);
	signal(SIGUSR1, ft_pid_handler);
	signal(SIGUSR2, ft_pid_handler);
	process_id = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(process_id, 1);
	dup2(fd, STDOUT_FILENO);
	while (1)
		pause ();
}
