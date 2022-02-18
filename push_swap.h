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
// # include "libft.h"
# include "stdio.h"
# include "stdlib.h"
/* ************************************************************************** */
typedef struct s_ps
{
	int			val;
	struct s_ps	*next;
	struct s_ps	*previous;
}	t_ps;

/* ************************************************************************** */
typedef struct s_data
{
	t_ps	*stack_a;
	t_ps	*stack_b;

	int	size_a;
	int	size_b;
} t_data;

/* ************************************************************************** */

void	init_push_swap(t_data *d);
t_ps	*ps_new_elem(int val);
void	ps_add_elem_to_bottom(t_ps **top_elem, t_ps *new_elem);
void	ps_new_elem_at_bottom(t_ps **top_elem, int val);
void	ps_display(t_ps *top_elem);
void	ps_del_list(t_ps *top_elem);
void	ps_del_elem(t_ps *elem);
int		ps_size(t_ps *top_elem);

void swap_a();
void swap_b();
void swap_2();
void push_to_a();
void push_to_b();
void rotate_a();
void rotate_b();
void rotate_2();
void rev_rot_a();
void rev_rot_b();
void rev_rot_2();

/* ************************************************************************** */
#endif