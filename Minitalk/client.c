/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:32:09 by jeyoon            #+#    #+#             */
/*   Updated: 2022/02/26 00:41:11 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_char(int pid, char c)
{
	int		cnt;
	char	mask;
	int		result;

	cnt = 0;
	while (cnt <= 7)
	{
		mask = 1 << (7 - cnt);
		if (c & mask)
			result = kill(pid, SIGUSR2);
		else
			result = kill(pid, SIGUSR1);
		if (result < 0)
		{
			ft_putstr_fd("Kill error!\n", 1);
			exit(1);
		}
		cnt++;
		usleep(50);
	}
}

void	client_action(int pid, char *str)
{
	int	len;
	int	idx;

	len = ft_strlen(str);
	idx = 0;
	while (idx <= len)
	{
		send_char(pid, str[idx]);
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("Invalid arguments!\n", 1);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid == 1)
	{
		ft_putstr_fd("Invalid arguments!\n", 1);
		exit(1);
	}
	client_action(pid, argv[2]);
	return (0);
}
