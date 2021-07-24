/*
 *	microblabla.h
 *	by wind
 *	<loutre@courrier.dev>
 *	22/07/21 17:03:43
 *	22/07/21 22:04:48
 */

#ifndef MICROBLABLA_H
# define MICROBLABLA_H

# include <unistd.h>
# include <signal.h>
# include <stddef.h>
# include <stdlib.h>

# define PID_SERV "Server's pid is : \e[33m"
# define ENDC "\e[0m"
# define NB_ARG "Wrong number of arguments, expecting pid and string\n"
# define INV_PID "First argument is not a valid pid\n"
# define ACKNOWLEDGEMENT "\n\e[32mMessage received !\n\e[0m"

# ifndef BONUS
#  define BONUS 0
# endif

#endif
