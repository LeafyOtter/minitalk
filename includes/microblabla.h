/*
 *	microblabla.h
 *	by wind
 *	<loutre@courrier.dev>
 *	22/07/21 17:03:43
 *	25/07/21 05:04:11
 */

#ifndef MICROBLABLA_H
# define MICROBLABLA_H

# include <signal.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define PID_SERV "Server's pid is : \e[33m"
# define ENDC "\e[0m"
# define NB_ARG "Wrong number of arguments, expecting pid and string\n"
# define INV_PID "First argument is not a valid pid\n"
# define LST_SIG "Signal was lost, restart server\n"
# define ACKNOWLEDGEMENT "\e[32mMessage sent and received !\n\e[0m"

# define BUFFER_SIZE 2048

int		ft_atoi_pid(char *str);
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif
