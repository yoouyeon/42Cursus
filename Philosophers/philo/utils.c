/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 03:37:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/29 19:04:13 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void	ft_msleep(int time)
{
	long long	temp;

	temp = ft_get_time();
	while (ft_get_time() < temp + time)
		usleep(500);
}

int	ft_philo_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->data->check_data));
	if (philo->data->end_flag == FALSE)
	{
		printf("%lld %d %s\n", ft_get_time() - philo->data->time_start, \
				philo->id, msg);
		pthread_mutex_unlock(&(philo->data->check_data));
		return (FALSE);
	}
	else
	{
		pthread_mutex_unlock(&(philo->data->check_data));
		return (TRUE);
	}
}	

long long	ft_get_time(void)
{
	struct timeval	now;
	long long		ret;

	gettimeofday(&now, NULL);
	ret = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (ret);
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	philo_atoi(char *str)
{
	long long	ret;
	int			idx;
	int			len;

	len = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	len = ft_strlen(str);
	if (len == 0 || str[0] == '-')
		return (-1);
	ret = 0;
	if (str[0] == '+')
		idx = 1;
	else
		idx = 0;
	while (idx < len)
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (-1);
		ret = ret * 10 + (str[idx] - '0');
		if (ret > 2147483647)
			return (-1);
		idx++;
	}
	return ((int)ret);
}
