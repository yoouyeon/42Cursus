/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:53:04 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 21:34:29 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	print_error(t_varlist *varlist)
{
	free_all(varlist);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_all(t_varlist *varlist)
{
	if (varlist -> a)
	{
		while (varlist -> a -> size > 0)
			stack_pop(varlist -> a);
		free(varlist -> a);
	}
	if (varlist -> b)
	{
		while (varlist -> b -> size > 0)
			stack_pop(varlist -> b);
		free(varlist -> b);
	}
	if (varlist -> sorted_arr)
	{
		free(varlist -> sorted_arr);
	}
}

int	main(int argc, char **argv)
{
	t_varlist	varlist;

	varlist.a = NULL;
	varlist.b = NULL;
	varlist.sorted_arr = NULL;
	if (argc < 2)
		exit(1);
	if (!make_stack(&varlist))
		print_error(&varlist);
	if (!arg_preprocess(argc, argv, &varlist))
		print_error(&varlist);
	ft_push_swap(&varlist);
	free_all(&varlist);
	return (0);
}
