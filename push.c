/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	push_to(t_stk *src, t_stk *dst)
{
	t_ps	*elem_extracted;

	elem_extracted = ps_rem_elem_from_top(src);
	ps_add_elem_to_top(elem_extracted, dst);
	return ;
}

/* ************************************************************************** */
/* pa : push a                                                                */
/* - take the first element at the top of b and put it at the top of a.       */
/* - Do nothing if b is empty.                                                */
/* ************************************************************************** */
void	push_to_a(t_data *d)
{
	push_to(&d->b, &d->a);
	ft_printf("pa\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
/* pb : push b                                                                */
/* - take the first element at the top of a and put it at the top of b.       */
/* - Do nothing if a is empty.                                                */
/* ************************************************************************** */
void	push_to_b(t_data *d)
{
	push_to(&d->a, &d->b);
	ft_printf("pb\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
void	push_to_a_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		push_to_a(d);
		loop--;
	}
}

/* ************************************************************************** */
void	push_to_b_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		push_to_b(d);
		loop--;
	}
}

/* ************************************************************************** */