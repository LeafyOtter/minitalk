/*
 *	client.c
 *	by wind
 *	<loutre@courrier.dev>
 *	22/07/21 18:07:19
 *	25/07/21 05:18:24
 */

#include "microblabla.h"

static int	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		if (c & (1 << 8))
		{
			if (kill(pid, SIGUSR2) < 0)
				return (1);
		}
		else if (kill(pid, SIGUSR1) < 0)
			return (1);
		c <<= 1;
		usleep(50);
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		write(1, NB_ARG, ft_strlen(NB_ARG));
		return (1);
	}
	pid = ft_atoi_pid(1[av]);
	if (pid <= 0)
	{
		write(1, INV_PID, ft_strlen(INV_PID));
		return (1);
	}
	while (*2[av])
	{
		if (send_char(pid, *2[av]))
			return (1);
		2[av]++;
	}
	if (send_char(pid, *2[av]))
		return (1);
	return (0);
}
