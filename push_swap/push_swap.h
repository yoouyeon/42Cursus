/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:23:01 by jeyoon            #+#    #+#             */
/*   Updated: 2022/03/16 17:22:43 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX (long long) 2147483647
# define INT_MIN (long long) -2147483648

typedef struct s_node		t_node;
typedef struct s_stack		t_stack;
typedef struct s_varlist	t_varlist;

struct s_node
{
	int		value;
	t_node	*next;
	t_node	*prev;
};
struct s_stack
{
	t_node	*top;
	int		size;
};
struct s_varlist
{
	int			arg_cnt;
	int			*sorted_arr;
	t_stack		*a;
	t_stack		*b;
};

/* arg_preprocess.c */
int			arg_parse_push(t_varlist *varlist, char *str, int len);
int			arg_preprocess(int argc, char **argv, t_varlist *varlist);
int			check_arg(t_varlist *varlist);
int			make_array(t_varlist *varlist);
/* arg_preprocess_utils.c */
long long	ft_atonum(char *str, int len);
void		selection_sort(int *arr, int size);
int			stack_push_bottom(t_stack *stack, int new_value);
/* main.c */
void		free_all(t_varlist *varlist);
void		print_error(t_varlist *varlist);
/* op_reverse_rotate.c */
void		rra(t_stack *a);
void		rrb(t_stack	*b);
void		rrr(t_stack *a, t_stack *b);
/* op_rotate.c */
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
/* op_swap_push.c */
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
/* sort_less_five.c */
void		sort_a_less_five(t_varlist *varlist);
void		sort_five_a(t_varlist *varlist);
void		sort_four_a(t_varlist *varlist);
void		sort_three_a(t_varlist *varlist);
void		sort_two_a(t_varlist *varlist);
/* sort_rotate.c */
void		rotate_and_pa(t_varlist *varlist);
void		rotate_last(t_varlist *varlist);
void		rotate_stack_a(t_varlist *varlist, int *cnt_ra);
void		rotate_stack_a_b(t_varlist *varlist, int *cnt_ra, int *cnt_rb);
void		rotate_stack_b(t_varlist *varlist, int *cnt_rb);
/* sort_rotate_utils.c */
int			get_cnt_ra(t_varlist *varlist, int target);
int			get_cnt_ra_big_small(t_varlist *varlist, int min_ele);
void		get_ro_cnt(t_varlist *varlist, int *cnt_ra, int *cnt_rb);
int			is_new_best_way(int old_ra, int old_rb, int new_ra, int new_rb);
int			cal_best_way(int cnt_ra, int cnt_rb);
/* sort_utils.c */
void		divide_two(t_varlist *varlist);
void		ft_push_swap(t_varlist *varlist);
int			is_sorted_a(t_varlist *varlist);
int			need_move(t_stack *s, int pivot, int option, int size);
/* stack.c */
int			make_stack(t_varlist *varlist);
int			stack_get_max_element(t_stack *stack);
int			stack_get_min_element(t_stack *stack);
int			stack_pop(t_stack *stack);
int			stack_push(t_stack *stack, int new_value);
/* utils_std.c */
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *str);

#endif
