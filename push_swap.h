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
# define MAX_SIZE_OF_UNSORTED_CHUNK 3
/* ************************************************************************** */
# define COL_VAL	0
# define COL_ELEM	1
# define COL_INDEX	2
/* ************************************************************************** */
# define DIR_A_TO_B 1
# define DIR_B_TO_A 2
/* ************************************************************************** */
typedef struct s_stk t_stk;
typedef struct s_data t_data;
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
typedef struct s_data
{
	/* ---------------- */
	t_stk	a;
	t_stk	b;
	/* ---------------- */
	t_ps	*stk_cmd;
	int		cnt_cmd;
	/* ---------------- */
	t_vpi	*vpi;
	int		vpi_size;
	/* ---------------- */
	t_ps	*tail_ref;
	/* ---------------- */
} t_data;
/* ************************************************************************** */
typedef struct s_ps
{
	int			val;
	int			index;
	int			chk_id;
	int			stk_id;
	bool		is_pivot;
	bool		sorted;
	bool		chk_start;
	bool		chk_end;
	struct s_ps	*prev;
	struct s_ps	*next;
}	t_ps;
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
/* ---------------------------------------- */
void	split_to_a(t_data *d);
void	split_to_b(t_data *d);
/* ---------------------------------------- */
// void	sort_a(t_data *d);
void	sort_a(t_data *d, int cnt_rev_rot_a);
void	sort_b(t_data *d);
/* ---------------------------------------- */
int		get_chunk_size(t_stk *stk);
bool	is_chunk_a_in_order(t_data *d, int chk_size);
bool	is_chunk_b_in_order(t_data *d, int chk_size);
/* ************************************************************************** */
void	sort_chunk_a(t_data *d);
void	sort_chunk_b_to_a(t_data *d);
/* ************************************************************************** */
void	init_push_swap(t_data *d);
bool	manage_parameter(int argc, char **argv, t_data *d);
bool	manage_arg_doublequote(char **argv, t_data *d);
/* ************************************************************************** */
void	ski_sort(t_data *d);
void	do_rotation(t_data *d);
void	do_swap(t_data *d);
bool	is_ready_push_b(t_data *d);
bool    is_ready_push_a(t_data *d); // pas similaire a is_ready_push_b()
/* ************************************************************************** */
long	ft_atoil(const char *str);
/* ************************************************************************** */
bool	is_param_ok(char *str, int pos);
bool	is_countable(char *str);
bool	is_bigger_than_int(char *str);
bool	is_duplicated (t_ps **stack, int val);
bool	is_in_order(t_ps *top_elem);
bool	is_same_chunk_id_whole_stack(t_stk *stk);
/* ************************************************************************** */
bool	has_0_elem_only(t_ps **head);
bool	has_1_elem_only(t_ps **head);
bool	has_2_elem_only(t_ps **head);
/* ---------------------------------------- */
bool	has_1_elem_or_more(t_ps **head);
bool	has_2_elem_or_more(t_ps **head);
/* ---------------------------------------- */
bool	has_less_than_2_elem(t_ps **head);
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
#endif