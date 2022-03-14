/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* PULL the stack from the bottom to the top ******************************** */
/* ************************************************************************** */
void	rotate(t_stk *stk)
{
	t_ps	*extracted_elem;

	if ((!stk) || (!has_2_elem_or_more(&stk->head)))
		return ;
	if (has_2_elem_only(&stk->head))
		swap(stk);
	else
	{
		extracted_elem = ps_rem_elem_from_top(stk);
		ps_add_elem_to_bottom(extracted_elem, stk);
	}
	return ;
}

/* ************************************************************************** */
void	rotate_a(t_data *d)
{
	rotate(&d->a);
	ft_printf("ra\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
void	rotate_b(t_data *d)
{
	rotate(&d->b);
	ft_printf("rb\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
void	rotate_2(t_data *d)
{
	rotate(&d->a);
	rotate(&d->b);
	ft_printf("rr\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
void	rotate_a_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rotate_a(d);
		loop--;
	}
}

/* ************************************************************************** */
void	rotate_b_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rotate_b(d);
		loop--;
	}
}

/* ************************************************************************** */
void	rotate_2_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rotate_2(d);
		loop--;
	}
}

/* ************************************************************************** */
/* ra : rotate a - shift up all elements of stack a by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rb : rotate b - shift up all elements of stack b by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rr : ra and rb at the same time.                                           */
/* ************************************************************************** */