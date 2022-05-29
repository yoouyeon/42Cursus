/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:43:52 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/29 18:58:37 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>
#include <stdlib.h>

int	ft_mutex_init(t_data *data, t_philo *philos)
{
	int	idx;

	data->forks = malloc(sizeof(pthread_mutex_t) * (data->num_philo));
	if (data->forks == 0)
		return (FALSE);
	idx = 0;
	while (idx < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[idx], NULL) != 0)
			return (FALSE);
		idx++;
	}
	if (pthread_mutex_init(&data->check_data, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

int	ft_philo_init(t_data *data, t_philo *philos)
{
	int	idx;

	memset(philos, 0, data->num_philo * sizeof(t_philo));
	if (ft_mutex_init(data, philos) == FALSE)
		return (FALSE);
	idx = 0;
	while (idx < data->num_philo)
	{
		philos[idx].id = idx + 1;
		philos[idx].data = data;
		philos[idx].left_fork = &(data->forks[idx % data->num_philo]);
		philos[idx].right_fork = &(data->forks[(idx + 1) % data->num_philo]);
		philos[idx].eat_cnt = 0;
		idx++;
	}
	return (TRUE);
}

int	get_philo_data(t_data *data, char **argv, int argc)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	memset(data, 0, sizeof(t_data));
	data->num_philo = philo_atoi(argv[1]);
	data->time_to_die = philo_atoi(argv[2]);
	data->time_to_eat = philo_atoi(argv[3]);
	data->time_to_sleep = philo_atoi(argv[4]);
	data->end_flag = FALSE;
	if (argc == 6)
	{
		data->num_must_eat = philo_atoi(argv[5]);
		if (data->num_must_eat <= 0)
			return (FALSE);
	}
	else
		data->num_must_eat = -1;
	if (data->num_philo <= 0 || data->time_to_die <= 0 || \
			data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (FALSE);
	else
		return (TRUE);
}
