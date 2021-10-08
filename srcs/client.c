/*
 *	client.c
 *	by wind
 *	<loutre@courrier.dev>
 *	22/07/21 18:07:19
 *	25/07/21 05:18:24
 */

#include "microblabla.h"

static int	g_status = 1;

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_status = 1;
	if (sig == SIGUSR2 && write(1, ACKNOWLEDGEMENT, ft_strlen(ACKNOWLEDGEMENT)))
		g_status = 2;
}

static void	sig_init(void)
{
	struct sigaction	act;

	act.sa_handler = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

static int	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		usleep(20);
		if (c & (1 << 8))
		{
			if (kill(pid, SIGUSR2) < 0)
				return (1);
		}
		else if (kill(pid, SIGUSR1) < 0)
			return (1);
		c <<= 1;
		g_status = 0;
		usleep(1000);
		if (!g_status && write(1, LST_SIG, ft_strlen(LST_SIG)))
			return (1);
		if (g_status == 2)
			return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 && write(1, NB_ARG, ft_strlen(NB_ARG)))
		return (1);
	pid = ft_atoi_pid(1[av]);
	if (pid <= 0 && write(1, INV_PID, ft_strlen(INV_PID)))
		return (1);
	sig_init();
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
