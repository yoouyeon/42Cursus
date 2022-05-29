/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:56:34 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/29 19:04:39 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int	check_end_flag(t_data *data)
{
	pthread_mutex_lock(&(data->check_data));
	if (data->end_flag == TRUE)
	{
		pthread_mutex_unlock(&(data->check_data));
		return (TRUE);
	}
	pthread_mutex_unlock(&(data->check_data));
	return (FALSE);
}

int	check_death(t_philo *philos, t_data *data)
{
	int			idx;
	long long	now;

	idx = 0;
	while (idx < data->num_philo)
	{
		pthread_mutex_lock(&(data->check_data));
		now = ft_get_time();
		if (now - philos[idx].time_of_last_eat >= data->time_to_die)
		{
			printf("%lld %d %s\n", now - data->time_start, philos[idx].id, DIED);
			data->end_flag = TRUE;
			pthread_mutex_unlock(&(data->check_data));
			return (TRUE);
		}
		pthread_mutex_unlock(&(data->check_data));
		idx++;
	}
	return (FALSE);
}

int	check_full(t_data *data)
{
	pthread_mutex_lock(&(data->check_data));
	if (data->full_eat_cnt == data->num_philo)
	{
		data->end_flag = TRUE;
		pthread_mutex_unlock(&(data->check_data));
		return (TRUE);
	}
	pthread_mutex_unlock(&(data->check_data));
	return (FALSE);
}

void	*philo_monitoring(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		if (check_death(philo, data) == TRUE || check_full(data) == TRUE)
			break ;
		usleep(500);
	}
	return (0);
}
