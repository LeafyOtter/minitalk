/*
 *	utils.c
 *	by fire
 *	<loutre@courrier.dev>
 *	25/07/21 04:44:52
 *	25/07/21 04:45:59
 */

#include "microblabla.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str && (++i)[str])
		;
	return (i);
}

int	ft_atoi_pid(char *str)
{
	int	nb;

	nb = 0;
	while (*str == ' ' && str)
		str++;
	while (str && (*str >= '0' && *str <= '9'))
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb);
}
