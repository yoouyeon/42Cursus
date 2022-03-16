/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:52:47 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 13:24:09 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (a -> size <= 1)
		return ;
	a -> top = a -> top -> prev;
	ft_putstr_fd("rra\n", 1);
	return ;
}

void	rrb(t_stack	*b)
{
	if (b -> size <= 1)
		return ;
	b -> top = b -> top -> prev;
	ft_putstr_fd("rrb\n", 1);
	return ;
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a -> size > 1)
		a -> top = a -> top -> prev;
	if (b -> size > 1)
		b -> top = b -> top -> prev;
	ft_putstr_fd("rrr\n", 1);
}
