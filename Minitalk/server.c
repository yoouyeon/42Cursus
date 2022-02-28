/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:30:30 by jeyoon            #+#    #+#             */
/*   Updated: 2022/02/25 22:40:54 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler_sigusr(int sig)
{
	static unsigned char	temp = 0;
	static int				cnt = 0;

	if (sig == SIGUSR2)
		temp += 1;
	cnt++;
	if (cnt == 8)
	{
		if (temp != 0)
			write(1, &temp, 1);
		else
			write(1, "\n", 1);
		cnt = 0;
		temp = 0;
	}
	else
		temp = temp << 1;
}

int	main(void)
{
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
