/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:32:37 by jeyoon            #+#    #+#             */
/*   Updated: 2022/02/25 22:41:49 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdlib.h>
# include "util.h"

void	send_char(int pid, char c);
void	client_action(int pid, char *str);

#endif
