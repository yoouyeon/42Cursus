/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:45:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 16:04:40 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	make_stack(t_varlist *varlist)
{
	varlist -> a = (t_stack *)malloc(sizeof(t_stack));
	varlist -> b = (t_stack *)malloc(sizeof(t_stack));
	if (!varlist -> a || !varlist -> b)
		return (0);
	varlist -> a -> top = NULL;
	varlist -> a -> size = 0;
	varlist -> b -> top = NULL;
	varlist -> b -> size = 0;
	return (1);
}

int	stack_push(t_stack *stack, int new_value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node -> value = new_value;
	if (!stack -> top)
	{
		stack -> top = new_node;
		new_node -> prev = new_node;
		new_node -> next = new_node;
	}
	else
	{
		new_node -> next = stack -> top;
		new_node -> prev = stack -> top -> prev;
		stack -> top -> prev -> next = new_node;
		stack -> top -> prev = new_node;
		stack -> top = new_node;
	}
	stack -> size++;
	return (1);
}

int	stack_pop(t_stack *stack)
{
	t_node	*temp;

	if (stack -> size == 0)
		return (0);
	else if (stack -> size == 1)
	{
		free(stack -> top);
		stack -> top = NULL;
	}
	else
	{
		stack -> top -> prev -> next = stack -> top -> next;
		stack -> top -> next -> prev = stack -> top -> prev;
		temp = stack -> top -> next;
		free(stack -> top);
		stack -> top = temp;
	}
	stack -> size--;
	return (1);
}

int	stack_get_max_element(t_stack *stack)
{
	int		idx;
	int		max_ele;
	t_node	*temp;

	idx = 0;
	max_ele = INT_MIN;
	temp = stack -> top;
	while (idx < stack -> size)
	{
		if (temp -> value >= max_ele)
			max_ele = temp -> value;
		temp = temp -> next;
		idx++;
	}
	return (max_ele);
}

int	stack_get_min_element(t_stack *stack)
{
	int		idx;
	int		min_ele;
	t_node	*temp;

	idx = 0;
	min_ele = INT_MAX;
	temp = stack -> top;
	while (idx < stack -> size)
	{
		if (temp -> value <= min_ele)
			min_ele = temp -> value;
		temp = temp -> next;
		idx++;
	}
	return (min_ele);
}
