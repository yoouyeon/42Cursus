/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:39:16 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/29 18:52:16 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	ft_philo_eat(t_philo *philo)
{
	ft_philo_print(philo, IS_EATING);
	pthread_mutex_lock(&(philo->data->check_data));
	philo->time_of_last_eat = ft_get_time();
	pthread_mutex_unlock(&(philo->data->check_data));
	ft_msleep(philo->data->time_to_eat);
	philo->eat_cnt += 1;
	pthread_mutex_lock(&(philo->data->check_data));
	if (philo->eat_cnt == philo->data->num_must_eat)
		philo->data->full_eat_cnt += 1;
	pthread_mutex_unlock(&(philo->data->check_data));
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	ft_philo_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (ft_philo_print(philo, HAS_FORK) == TRUE)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (FALSE);
	}
	if (philo->data->num_philo == 1)
	{
		ft_msleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (FALSE);
	}
	pthread_mutex_lock(philo->right_fork);
	if (ft_philo_print(philo, HAS_FORK) == TRUE)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (FALSE);
	}
	return (TRUE);
}

void	ft_philo_sleep(t_philo *philo)
{
	if (ft_philo_print(philo, IS_SLEEPING) == TRUE)
		return ;
	ft_msleep(philo->data->time_to_sleep);
}

void	*ft_philo_act(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2)
		usleep(500);
	while (1)
	{
		if (check_end_flag(data) == TRUE)
			break ;
		if (ft_philo_fork(philo) == FALSE)
			break ;
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		if (ft_philo_print(philo, IS_THINKING) == TRUE)
			break ;
		usleep(500);
	}
	return (0);
}

int	ft_philo_start(t_data *data, t_philo *philos)
{
	int			idx;
	long long	start_time;

	idx = 0;
	start_time = ft_get_time();
	data->time_start = start_time;
	while (idx < data->num_philo)
	{
		philos[idx].time_of_last_eat = start_time;
		if (pthread_create(&philos[idx].thread, NULL, \
					ft_philo_act, &philos[idx]) != 0)
			return (FALSE);
		idx++;
	}
	if (pthread_create(&data->monitor, NULL, philo_monitoring, philos) != 0)
		return (FALSE);
	pthread_join(data->monitor, NULL);
	idx = 0;
	while (idx < data->num_philo)
	{
		pthread_join(philos[idx].thread, NULL);
		idx++;
	}
	return (TRUE);
}
