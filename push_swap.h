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
// # include "libft.h"
# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"
/* ************************************************************************** */
typedef struct s_data t_data;
typedef struct s_ps t_ps;
/* ************************************************************************** */
typedef struct s_data
{
	t_ps	*stack_a;
	t_ps	*stack_b;

	int	size_a;
	int	size_b;
} t_data;
/* ************************************************************************** */
typedef struct s_ps
{
	int			val;
	struct s_ps	*prev;
	struct s_ps	*next;
}	t_ps;
/* ************************************************************************** */
void	init_push_swap(t_data *d);



bool	is_countable(char *str);
/* ---------------------------------------- */
t_ps	*ps_new_elem(int val);
void	ps_add_elem_to_bottom(t_ps **ptr_top, t_ps *new_elem);
void	ps_new_elem_at_bottom(t_ps **ptr_top, int val);
/* ---------------------------------------- */
void	ps_display_1_list(t_ps *top_elem);
void	ps_display_2_list(t_data *d);
/* ---------------------------------------- */
void	ps_del_list(t_ps *top_elem);
void	ps_del_elem(t_ps *elem);
int		ps_size(t_ps *top_elem);
t_ps	*ps_get_last_elem(t_ps **ptr_top);
/* ************************************************************************** */
void	swap(t_ps **ptr_top);
void	swap_a(t_data *d);
void	swap_b(t_data *d);
void	swap_2(t_data *d);
/* ---------------------------------------- */
void	push_to(t_ps **stack_src, t_ps **stack_dst);
void	push_to_a(t_data *d);
void	push_to_b(t_data *d);
/* ---------------------------------------- */
void	rotate(t_ps **ptr_top);
void	rotate_a(t_data *d);
void	rotate_b(t_data *d);
void	rotate_2(t_data *d);
/* ---------------------------------------- */
void	rev_rot(t_ps **ptr_top);
void	rev_rot_a(t_data *d);
void	rev_rot_b(t_data *d);
void	rev_rot_2(t_data *d);
/* ---------------------------------------- */

/* ************************************************************************** */
#endif