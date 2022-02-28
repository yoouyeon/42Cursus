/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:23:07 by jeyoon            #+#    #+#             */
/*   Updated: 2022/02/24 02:36:29 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);

#endif