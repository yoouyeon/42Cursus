/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 03:05:57 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/29 18:58:10 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define FALSE 0
# define TRUE 1

# define HAS_FORK "\033[0;32mhas taken a fork\033[0m"
# define IS_EATING "\033[0;36mis eating\033[0m"
# define IS_SLEEPING "\033[0;34mis sleeping\033[0m"
# define IS_THINKING "\033[0;33mis thinking\033[0m"
# define DIED "\033[0;31mdied\033[0m"

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	long long		time_start;
	int				end_flag;
	int				full_eat_cnt;
	pthread_mutex_t	check_data;
	pthread_mutex_t	*forks;
	pthread_t		monitor;
};

struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		time_of_last_eat;
	int				eat_cnt;
	t_data			*data;
};

int			get_philo_data(t_data *data, char **argv, int argc);
int			philo_atoi(char *str);
long long	ft_get_time(void);
void		ft_msleep(int time);
int			ft_philo_print(t_philo *philo, char *msg);
int			ft_philo_start(t_data *data, t_philo *philos);
void		*philo_monitoring(void *arg);
int			check_end_flag(t_data *data);
int			ft_philo_init(t_data *data, t_philo *philos);

#endif