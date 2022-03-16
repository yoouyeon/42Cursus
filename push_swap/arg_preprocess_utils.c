/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_preprocess_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 02:06:30 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 14:57:00 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	selection_sort(int *arr, int size)
{
	int	idx_a;
	int	idx_b;
	int	temp;

	idx_a = 0;
	while (idx_a < size - 1)
	{
		idx_b = idx_a + 1;
		while (idx_b < size)
		{
			if (arr[idx_a] > arr[idx_b])
			{
				temp = arr[idx_a];
				arr[idx_a] = arr[idx_b];
				arr[idx_b] = temp;
			}
			idx_b++;
		}
		idx_a++;
	}
}

long long	ft_atonum(char *str, int len)
{
	long long int	num;
	int				sign;
	int				idx;

	num = 0;
	idx = 0;
	sign = 1;
	if (idx < len && (str[idx] == '-' || str[idx] == '+'))
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	if (str[idx] < '0' || str[idx] > '9')
		return (INT_MAX + 1);
	while (idx < len && str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	if (idx < len && (str[idx] < '0' || str[idx] > '9'))
		return (INT_MAX + 1);
	if (num * sign < INT_MIN || num * sign > INT_MAX)
		return (INT_MAX + 1);
	return (num * sign);
}

int	stack_push_bottom(t_stack *stack, int new_value)
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
	}
	stack -> size++;
	return (1);
}
