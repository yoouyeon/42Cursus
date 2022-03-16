/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:04:43 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 15:10:19 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_less_five(t_varlist *varlist)
{
	if (varlist -> a -> size == 2)
		sort_two_a(varlist);
	else if (varlist -> a -> size == 3)
		sort_three_a(varlist);
	else if (varlist -> a -> size == 4)
		sort_four_a(varlist);
	else
		sort_five_a(varlist);
}

void	sort_two_a(t_varlist *varlist)
{
	int	num1;
	int	num2;

	num1 = varlist -> a -> top -> value;
	num2 = varlist -> a -> top -> next -> value;
	if (num1 > num2)
		sa(varlist -> a);
}

void	sort_three_a(t_varlist *varlist)
{
	int	max_ele;

	max_ele = stack_get_max_element(varlist -> a);
	if (max_ele == varlist -> a -> top -> value)
		ra(varlist -> a);
	if (max_ele == varlist -> a -> top -> next -> value)
		rra(varlist -> a);
	if (varlist -> a -> top -> value > varlist -> a -> top -> next -> value)
		sa(varlist -> a);
}

void	sort_four_a(t_varlist *varlist)
{
	int		pivot;
	int		idx;
	int		size;

	pivot = varlist -> sorted_arr[1];
	idx = 0;
	size = varlist -> a -> size;
	while (idx < size)
	{
		if (varlist -> a -> top -> value < pivot)
		{
			pb(varlist -> a, varlist -> b);
			break ;
		}
		ra(varlist -> a);
		idx++;
	}
	sort_three_a(varlist);
	pa(varlist -> a, varlist -> b);
}

void	sort_five_a(t_varlist *varlist)
{
	int		pivot;
	int		idx;
	int		size;

	pivot = varlist -> sorted_arr[2];
	idx = 0;
	size = varlist -> a -> size;
	while (idx < size)
	{
		if (varlist -> a -> top -> value < pivot)
			pb(varlist -> a, varlist -> b);
		else
			ra(varlist -> a);
		idx++;
	}
	sort_three_a(varlist);
	if (varlist -> b -> top -> value < varlist -> b -> top -> next -> value)
		sb(varlist -> b);
	pa(varlist -> a, varlist -> b);
	pa(varlist -> a, varlist -> b);
}
