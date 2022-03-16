/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:45:55 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 13:24:09 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a -> size < 2)
		return ;
	temp = a -> top -> value;
	a -> top -> value = a -> top -> next -> value;
	a -> top -> next -> value = temp;
	ft_putstr_fd("sa\n", 1);
	return ;
}

void	sb(t_stack *b)
{
	int	temp;

	if (b -> size < 2)
		return ;
	temp = b -> top -> value;
	b -> top -> value = b -> top -> next -> value;
	b -> top -> next -> value = temp;
	ft_putstr_fd("sb\n", 1);
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a -> size >= 2)
	{
		temp = a -> top -> value;
		a -> top -> value = a -> top -> next -> value;
		a -> top -> next -> value = temp;
	}
	if (b -> size >= 2)
	{
		temp = b -> top -> value;
		b -> top -> value = b -> top -> next -> value;
		b -> top -> next -> value = temp;
	}
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	int	temp;

	if (b -> size == 0)
		return ;
	temp = b -> top -> value;
	stack_pop(b);
	stack_push(a, temp);
	ft_putstr_fd("pa\n", 1);
	return ;
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp;

	if (a -> size == 0)
		return ;
	temp = a -> top -> value;
	stack_pop(a);
	stack_push(b, temp);
	ft_putstr_fd("pb\n", 1);
	return ;
}
