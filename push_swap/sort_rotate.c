/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:06:40 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 13:24:09 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_pa(t_varlist *varlist)
{
	int	cnt_ra;
	int	cnt_rb;

	cnt_ra = 0;
	cnt_rb = 0;
	get_ro_cnt(varlist, &cnt_ra, &cnt_rb);
	rotate_stack_a_b(varlist, &cnt_ra, &cnt_rb);
	rotate_stack_a(varlist, &cnt_ra);
	rotate_stack_b(varlist, &cnt_rb);
	pa(varlist -> a, varlist -> b);
}

void	rotate_stack_a_b(t_varlist *varlist, int *cnt_ra, int *cnt_rb)
{
	if (*cnt_ra > 0 && *cnt_rb > 0)
	{
		while (*cnt_ra > 0 && *cnt_rb > 0)
		{
			rr(varlist -> a, varlist -> b);
			*cnt_ra = *cnt_ra - 1;
			*cnt_rb = *cnt_rb - 1;
		}
		return ;
	}
	if (*cnt_ra < 0 && *cnt_rb < 0)
	{
		while (*cnt_ra < 0 && *cnt_rb < 0)
		{
			rrr(varlist -> a, varlist -> b);
			*cnt_ra = *cnt_ra + 1;
			*cnt_rb = *cnt_rb + 1;
		}
		return ;
	}
	return ;
}

void	rotate_stack_a(t_varlist *varlist, int *cnt_ra)
{
	if (*cnt_ra > 0)
	{
		while (*cnt_ra > 0)
		{
			ra(varlist -> a);
			*cnt_ra = *cnt_ra - 1;
		}
		return ;
	}
	if (*cnt_ra < 0)
	{
		while (*cnt_ra < 0)
		{
			rra(varlist -> a);
			*cnt_ra = *cnt_ra + 1;
		}
		return ;
	}
	return ;
}

void	rotate_stack_b(t_varlist *varlist, int *cnt_rb)
{
	if (*cnt_rb > 0)
	{
		while (*cnt_rb > 0)
		{
			rb(varlist -> b);
			*cnt_rb = *cnt_rb - 1;
		}
		return ;
	}
	if (*cnt_rb < 0)
	{
		while (*cnt_rb < 0)
		{
			rrb(varlist -> b);
			*cnt_rb = *cnt_rb + 1;
		}
		return ;
	}
	return ;
}

void	rotate_last(t_varlist *varlist)
{
	int		last_ra_cnt;
	t_node	*temp;

	last_ra_cnt = 0;
	temp = varlist -> a -> top;
	while (temp -> value != varlist -> sorted_arr[0])
	{
		temp = temp -> next;
		last_ra_cnt++;
	}
	if (last_ra_cnt > varlist -> a -> size / 2)
		last_ra_cnt = (varlist -> a -> size - last_ra_cnt) * -1;
	rotate_stack_a(varlist, &last_ra_cnt);
}
