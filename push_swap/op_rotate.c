/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:48:16 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 13:24:09 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a -> size > 1)
		a -> top = a -> top -> next;
	ft_putstr_fd("ra\n", 1);
	return ;
}

void	rb(t_stack *b)
{
	if (b -> size > 1)
		b -> top = b -> top -> next;
	ft_putstr_fd("rb\n", 1);
	return ;
}

void	rr(t_stack *a, t_stack *b)
{
	if (a -> size > 1)
		a -> top = a -> top -> next;
	if (b -> size > 1)
		b -> top = b -> top -> next;
	ft_putstr_fd("rr\n", 1);
}
