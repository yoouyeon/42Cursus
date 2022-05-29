/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 03:03:10 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/29 18:48:31 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_philo_free(t_data *data, t_philo *philos)
{
	int	idx;

	if (data != 0)
	{
		pthread_mutex_destroy(&data->check_data);
		if (data->forks != 0)
		{
			idx = 0;
			while (idx < data->num_philo)
			{
				pthread_mutex_destroy(&data->forks[idx]);
				idx++;
			}
			free(data->forks);
		}
		free(data);
	}
	if (philos != 0)
	{
		pthread_mutex_destroy(philos->left_fork);
		pthread_mutex_destroy(philos->right_fork);
		free(philos);
	}
}

static int	ft_print_error(t_data *data, t_philo *philos, char *msg)
{
	ft_philo_free(data, philos);
	printf("%s\n", msg);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philos;

	data = 0;
	philos = 0;
	data = malloc(sizeof(t_data));
	if (data == 0)
		return (ft_print_error(data, philos, "malloc error."));
	if (get_philo_data(data, argv, argc) == FALSE)
		return (ft_print_error(data, philos, "arguments error"));
	philos = malloc(data->num_philo * sizeof(t_philo));
	if (philos == 0)
		return (ft_print_error(data, philos, "malloc error."));
	if (ft_philo_init(data, philos) == FALSE)
		return (ft_print_error(data, philos, \
				"Failed to initialize philosophers"));
	if (ft_philo_start(data, philos) == FALSE)
		return (ft_print_error(data, philos, "Failed to feed philosophers"));
	ft_philo_free(data, philos);
	return (0);
}
