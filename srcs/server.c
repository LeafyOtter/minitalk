/*
 *	server.c
 *	by wind
 *	<loutre@courrier.dev>
 *	22/07/21 17:07:35
 *	25/07/21 05:17:37
 */

#include "microblabla.h"

static void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				received = 0;
	static unsigned char	character = 0;

	(void)context;
	received++;
	usleep(10);
	kill(siginfo->si_pid, SIGUSR1);
	character <<= 1;
	if (sig == SIGUSR2)
		character += 1;
	if (received == 8)
	{
		if (!character)
			kill(siginfo->si_pid, SIGUSR2);
		write(1, &character, 1);
		received = 0;
		character = 0;
	}
}

static char	*print_pid(int pid, char *str)
{
	int		tmp;
	size_t	len;

	tmp = pid;
	len = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	len[str] = '\n';
	(len + 1)[str] = '\0';
	while (len-- > 0)
	{
		len[str] = pid % 10 + '0';
		pid /= 10;
	}
	return (str);
}

int	main(void)
{
	int					pid;
	char				str[8];
	struct sigaction	act;

	pid = getpid();
	print_pid(pid, str);
	write(1, PID_SERV, ft_strlen(PID_SERV));
	write(1, str, ft_strlen(str));
	write(1, ENDC, ft_strlen(ENDC));
	act.sa_sigaction = &signal_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		return (1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		return (1);
	while (1)
		pause();
}
