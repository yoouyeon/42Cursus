/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:19:57 by jeyoon            #+#    #+#             */
/*   Updated: 2022/02/26 02:58:41 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nbr;
	char			temp;

	if (fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	temp = ((nbr % 10) + '0');
	write(fd, &temp, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s || fd < 0)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

static unsigned int	atonbr(const char *str, int idx)
{
	unsigned int	nbr;

	nbr = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			nbr = nbr * 10 + (str[idx] - '0');
		else
			break ;
		idx++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	unsigned int	nbr;
	int				sign;
	int				i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nbr = atonbr(str, i);
	if (sign == -1 && nbr > 2147483648)
		return (0);
	if (sign == 1 && nbr > 2147483647)
		return (-1);
	return ((int)(nbr * sign));
}
