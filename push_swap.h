/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:30 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/* ************************************************************************** */
# include <ctype.h>
# include "libft.h"
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdbool.h"
/* ************************************************************************** */
# define FLAG_INFO	1
# define FLAG_INFO_RES	1
/* ************************************************************************** */
# define EXIT_YES	1
# define EXIT_NO	0
/* ************************************************************************** */
# define STACK_ID_A	1
# define STACK_ID_B	2
/* ************************************************************************** */
# define ALGO_1	1
# define ALGO_2	2
# define ALGO_3	3
# define ALGO_4	4
# define ALGO_5	5
# define ALGO_6	6
# define ALGO_7	7
# define ALGO_8	8
# define ALGO_9 9
# define ALGO_10 10
/* ************************************************************************** */
# define COL_VAL	0
# define COL_ELEM	1
# define COL_INDEX	2
/* ************************************************************************** */
# define DIR_A_TO_B 1
# define DIR_B_TO_A 2
/* ************************************************************************** */
typedef struct s_data t_data;
typedef struct s_stk t_stk;
typedef struct s_algo t_algo;
typedef struct s_ps t_ps;
typedef struct s_cmd t_cmd;
typedef struct s_vpi t_vpi;
/* ************************************************************************** */
typedef struct s_stk
{
	/* ---------------- */
	t_ps	*head;
	t_ps	*tail;
	int		size;
	int		stk_id;
	/* ---------------- */
}	t_stk;
/* ************************************************************************** */
typedef struct s_algo
{
	/* ---------------- */
	int		id;
	int		coef;
	/* ---------------- */
	int 	complexity;
	int		a;
	int		b;
	int		c;
	int		d;
}	t_algo;
/* ************************************************************************** */
typedef struct s_data
{
	/* ---------------- */
	t_stk	a;
	t_stk	b;
	/* ---------------- */
	t_ps	*pivot;
	t_ps	*bigger;
	t_ps	*smaller;
	/* ---------------- */
	t_ps	*stk_cmd;
	int		cnt_cmd;
	/* ---------------- */
	t_ps	*tail_ref;
	/* ---------------- */
	int		algo_direction;
	int		algo_choosed;
	/* ---------------- */
	t_algo	algo_1;
	t_algo	algo_2;
	t_algo	algo_3;
	t_algo	algo_4;
	t_algo	algo_5;
	t_algo	algo_6;
	t_algo	algo_7;
	t_algo	algo_8;
	t_algo	algo_9;
	t_algo	algo_10;
	/* ---------------- */
	t_algo	algo;
	/* ---------------- */
	t_ps	*h_elem;
	t_ps	*l_elem;
	int		pos_h_elem;
	int		pos_l_elem;
	int 	cur_stk;
	int 	cur_stk_size;
	/* ---------------- */
	t_ps	*a_elem;
	t_ps	*b_elem;
	/* ---------------- */
	int		coef_a;
	int		coef_b;
	int		coef_c;
	int		coef_d;
	/* ---------------- */
	void (*p)(t_data *d, int loop);
	void (*p_back)(t_data *d, int loop);
	void (*rot)(t_data *d, int loop);
	void (*rev)(t_data *d, int loop);
	void (*s)(t_data *d);
	/* ---------------- */
	t_vpi	*vpi;
	int		vpi_size;
	/* ---------------- */
} t_data;
/* ************************************************************************** */
typedef struct s_ps
{
	int			val;
	int			index;
	int			stk_id;
	bool		is_pivot;
	bool		sorted;
	bool		chunk_start;
	bool		chunk_end;
	struct s_ps	*prev;
	struct s_ps	*next;
}	t_ps;
/* ************************************************************************** */
typedef struct s_cmd
{
	int				val_cmd;
	char			*str_cmd;
	int				should_print;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;
/* ************************************************************************** */
typedef struct s_vpi
{
	int		val;
	t_ps	*ptr;
	int		index;
}	t_vpi;
/* ************************************************************************** */
void	do_vpi(t_data *d);
void	quicksort_vpi(t_vpi *vpi, int start, int end);
t_vpi	*vpi_create(int size);
void	vpi_free(t_vpi **vpi);
void	vpi_do_index(t_vpi *vpi, int size);
void	vpi_display(t_vpi *vpi, int size);
/* ************************************************************************** */
void	midsort(t_data *d);
void	midsort_to_a(t_data *d);
void	midsort_to_b(t_data *d);
/* ---------------------------------------- */
t_ps	*sort_insertion(t_ps *stack);
/* ---------------------------------------- */
// void	quick_sort(t_stk *stk, t_ps **start, t_ps **end, t_data *d);
void	find_bigger_than_pivot(t_data *d);
void	find_smaller_than_pivot(t_data *d);
int		distance_to_top_upwards(t_ps *elem);
int		distance_to_top_downwards(t_ps *elem);
/* ************************************************************************** */
// void	init_push_swap(t_stk *a, t_stk *b, t_data *d);
void	init_push_swap(t_data *d);
bool	manage_parameter(int argc, char **argv, t_data *d);
bool	manage_arg_doublequote(char **argv, t_data *d);
void	ps_ski_sort(t_data *d);
void	do_rotation(t_data *d);
void	do_swap(t_data *d);
bool	is_ready_push_b(t_data *d);
bool    is_ready_push_a(t_data *d);
/* ************************************************************************** */
void	swap_far_elem(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo1(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo2(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo3(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo4(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo5(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo6(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo7(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo8(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo9(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	swap_far_algo10(t_ps *elem_1, t_ps *elem_2, t_data *d);
/* ---------------------------------------- */
void	assign_high_and_low_elem(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	assign_a_and_b_elem(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	assign_fct(t_ps *elem_1, t_ps *elem_2, t_data *d);
/* ---------------------------------------- */
void	calculate_coef(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	calculate_coef_1_or_2(t_data *d);
void	calculate_coef_3_or_4(t_data *d);
void	calculate_coef_5_to_8(t_ps *elem_a, t_ps *elem_b,  t_data *d);
void	calculate_coef_9_or_10(t_data *d);
/* ************************************************************************** */
long	ft_atoil(const char *str);
/* ************************************************************************** */
bool	is_param_ok(char *str, int pos);
bool	is_countable(char *str);
bool	is_bigger_than_int(char *str);
bool	is_duplicated (t_ps **stack, int val);
bool	is_in_order(t_ps *top_elem);
/* ---------------------------------------- */
bool	has_0_elem_only(t_ps **stack);
bool	has_1_elem_only(t_ps **stack);
bool	has_2_elem_only(t_ps **stack);
/* ---------------------------------------- */
bool	has_1_elem_or_more(t_ps **stack);
bool	has_2_elem_or_more(t_ps **stack);
/* ---------------------------------------- */
bool	has_less_than_2_elem(t_ps **stack);
/* ************************************************************************** */
t_ps	*ps_new_elem(int val);
void	ps_new_elem_at_bottom(int val, t_stk *stk);
/* ---------------------------------------- */
void	ps_add_elem_to_top(t_ps *new, t_stk *stk);
void	ps_add_elem_to_bottom(t_ps *new, t_stk *stk);
t_ps	*ps_rem_elem_from_top(t_stk *stk);
t_ps	*ps_rem_elem_from_bottom(t_stk *stk);
/* ---------------------------------------- */
void	ps_del_list(t_ps **stack);
void	ps_del_elem(t_ps *elem);
int		ps_size(t_ps *top_elem);
t_ps	*ps_get_elem(t_stk *stk, int position);
t_ps	*ps_get_last_elem(t_ps **ptr_top);
int		ps_get_position(t_data *d, t_ps *elem);
/* ************************************************************************** */
void	swap(t_stk *stk);
void	swap_a(t_data *d);
void	swap_b(t_data *d);
void	swap_2(t_data *d);
/* ---------------------------------------- */
void	push_to(t_stk *src, t_stk *dst);
void	push_to_a(t_data *d);
void	push_to_b(t_data *d);
void	push_to_a_loop(t_data *d, int loop);
void	push_to_b_loop(t_data *d, int loop);
/* ---------------------------------------- */
void	rotate(t_stk *stk);
void	rotate_a(t_data *d);
void	rotate_b(t_data *d);
void	rotate_2(t_data *d);
void	rotate_a_loop(t_data *d, int loop);
void	rotate_b_loop(t_data *d, int loop);
void	rotate_2_loop(t_data *d, int loop);
/* ---------------------------------------- */
void	rev_rot(t_stk *stk);
void	rev_rot_a(t_data *d);
void	rev_rot_b(t_data *d);
void	rev_rot_2(t_data *d);
void	rev_rot_a_loop(t_data *d, int loop);
void	rev_rot_b_loop(t_data *d, int loop);
void	rev_rot_2_loop(t_data *d, int loop);
/* ************************************************************************** */
void	display(t_data *d);
void	display_1_list(t_ps *top_elem);
void	display_2_list(t_data *d);
void	display_size(t_data *d);
void	display_stack_address(t_data *d);
void	display_algo_coef(t_data *d);
/* ************************************************************************** */
void	printf_red();
void	printf_yellow();
void	printf_reset();
/* ************************************************************************** */
#endif