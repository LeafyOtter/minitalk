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

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			n;
	void			*ptr;
	unsigned char	*tmp;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	n = nmemb * size;
	tmp = (unsigned char *)ptr;
	while (n--)
		*tmp++ = '\0';
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = c;
	return (s);
}
