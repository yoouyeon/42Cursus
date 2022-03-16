/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:58:55 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 15:51:54 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_move(t_stack *s, int pivot, int option, int size)
{
	t_node	*temp;

	if (s -> size <= 0)
		return (0);
	temp = s -> top;
	while (size--)
	{
		if (option == 0 && temp -> value <= pivot)
			return (1);
		if (option == 1 && temp -> value > pivot)
			return (1);
		temp = temp -> next;
	}
	return (0);
}

int	is_sorted_a(t_varlist *varlist)
{
	t_node	*temp;
	int		cnt;

	if (varlist -> a -> size == 0)
		return (0);
	if (varlist -> a -> size != varlist -> arg_cnt)
		return (0);
	temp = varlist -> a -> top;
	cnt = 0;
	while (cnt < varlist -> arg_cnt)
	{
		if (temp -> value != varlist -> sorted_arr[cnt])
			return (0);
		temp = temp -> next;
		cnt++;
	}
	return (1);
}

void	divide_two(t_varlist *varlist)
{
	int	pivot;

	if (varlist -> a -> size <= 5)
		return ;
	pivot = varlist -> sorted_arr[varlist -> arg_cnt / 2];
	while (need_move(varlist -> a, pivot, 0, varlist -> a -> size) != 0)
	{
		if (varlist -> a -> top -> value <= pivot)
			pb(varlist -> a, varlist -> b);
		else
			ra(varlist -> a);
	}
}

void	ft_push_swap(t_varlist *varlist)
{	
	if (is_sorted_a(varlist))
		return ;
	if (varlist -> a -> size <= 5)
	{
		sort_a_less_five(varlist);
		return ;
	}
	divide_two(varlist);
	while (varlist -> a -> size > 3)
		pb(varlist -> a, varlist -> b);
	if (varlist -> a -> size == 2)
		sort_two_a(varlist);
	else
		sort_three_a(varlist);
	while (varlist -> b -> size > 0)
		rotate_and_pa(varlist);
	rotate_last(varlist);
	return ;
}
