/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_preprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:04:08 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 13:24:59 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	arg_preprocess(int argc, char **argv, t_varlist *varlist)
{
	int	idx;
	int	len;

	idx = 1;
	varlist -> arg_cnt = 0;
	while (idx < argc)
	{
		len = ft_strlen(argv[idx]);
		if (len == 0)
			return (0);
		if (!arg_parse_push(varlist, argv[idx], len))
			return (0);
		idx++;
	}
	if (varlist -> arg_cnt == 0)
	{
		free_all(varlist);
		exit(1);
	}
	if (!make_array(varlist))
		return (0);
	selection_sort(varlist -> sorted_arr, varlist -> arg_cnt);
	if (!check_arg(varlist))
		return (0);
	return (1);
}

int	arg_parse_push(t_varlist *varlist, char *str, int len)
{
	int				idx;
	int				cnt;
	long long int	arg;

	idx = 0;
	while (idx < len)
	{
		cnt = 0;
		if (str[idx] != ' ')
		{
			while (str[idx + cnt] && str[idx + cnt] != ' ')
				cnt++;
			arg = ft_atonum(&str[idx], cnt);
			if (arg > INT_MAX || !stack_push_bottom(varlist -> a, (int)arg))
				return (0);
			idx += cnt + 1;
			varlist -> arg_cnt++;
		}
		else
			idx++;
	}
	if (cnt == 0)
		return (0);
	else
		return (1);
}

int	make_array(t_varlist *varlist)
{
	int		idx;
	t_node	*temp;

	varlist -> sorted_arr = (int *)malloc(varlist -> arg_cnt * sizeof(int));
	if (!varlist -> sorted_arr)
		return (0);
	idx = 0;
	temp = varlist -> a -> top;
	while (idx < varlist -> arg_cnt)
	{
		varlist -> sorted_arr[idx] = temp -> value;
		temp = temp -> next;
		idx++;
	}
	return (1);
}

int	check_arg(t_varlist *varlist)
{
	int	idx;

	idx = 0;
	while (idx < varlist -> arg_cnt - 1)
	{
		if (varlist -> sorted_arr[idx] == varlist -> sorted_arr[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}
