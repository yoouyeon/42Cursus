/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:55:18 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 17:03:21 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ro_cnt(t_varlist *varlist, int *cnt_ra, int *cnt_rb)
{
	t_node	*temp;
	int		b_idx;
	int		new_cnt_ra;
	int		new_cnt_rb;

	temp = varlist -> b -> top;
	b_idx = 0;
	while (b_idx < varlist -> b -> size)
	{
		new_cnt_ra = get_cnt_ra(varlist, temp -> value);
		if (b_idx > varlist -> b -> size / 2)
			new_cnt_rb = (varlist -> b -> size - b_idx) * -1;
		else
			new_cnt_rb = b_idx;
		if (b_idx == 0 || is_new_best_way
			(*cnt_ra, *cnt_rb, new_cnt_ra, new_cnt_rb) == 1)
		{
			*cnt_ra = new_cnt_ra;
			*cnt_rb = new_cnt_rb;
		}
		temp = temp -> next;
		b_idx++;
	}
}

int	get_cnt_ra(t_varlist *varlist, int target)
{
	int		a_idx;
	t_node	*temp;
	int		max_ele;
	int		min_ele;

	a_idx = 0;
	temp = varlist -> a -> top;
	max_ele = stack_get_max_element(varlist -> a);
	min_ele = stack_get_min_element(varlist -> a);
	if (max_ele < target || min_ele > target)
		return (get_cnt_ra_big_small(varlist, min_ele));
	while (1)
	{
		if (temp -> value > target && temp -> prev -> value < target)
			break ;
		temp = temp -> next;
		a_idx++;
	}
	if (a_idx > varlist -> a -> size / 2)
		return ((varlist -> a -> size - a_idx) * -1);
	return (a_idx);
}

int	get_cnt_ra_big_small(t_varlist *varlist, int min_ele)
{
	int		a_idx;
	t_node	*temp;

	a_idx = 0;
	temp = varlist -> a -> top;
	while (temp -> value != min_ele)
	{
		temp = temp -> next;
		a_idx++;
	}
	if (a_idx > varlist -> a -> size / 2)
		return ((varlist -> a -> size - a_idx) * -1);
	return (a_idx);
}

int	is_new_best_way(int old_ra, int old_rb, int new_ra, int new_rb)
{
	int	old_way;
	int	new_way;

	old_way = cal_best_way(old_ra, old_rb);
	new_way = cal_best_way(new_ra, new_rb);
	if (old_way > new_way)
		return (1);
	else
		return (0);
}

int	cal_best_way(int cnt_ra, int cnt_rb)
{
	int	ra_sign;
	int	rb_sign;

	if (cnt_ra < 0)
		ra_sign = -1;
	else
		ra_sign = 1;
	if (cnt_rb < 0)
		rb_sign = -1;
	else
		rb_sign = 1;
	if (ra_sign * rb_sign < 0)
		return (cnt_ra * ra_sign + cnt_rb * rb_sign);
	if (cnt_ra * ra_sign < cnt_rb * rb_sign)
		return (cnt_rb * rb_sign);
	else
		return (cnt_ra * ra_sign);
}
