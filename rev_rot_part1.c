/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* PUSH the stack from the top to the bottom ******************************** */
/* ************************************************************************** */
void	rev_rot(t_stk *stk)
{
	t_ps	*extracted_elem;

	if ((!stk) || (!has_2_elem_or_more(&stk->head)))
		return ;
	if (has_2_elem_only(&stk->head))
		swap(stk);
	else
	{
		extracted_elem = ps_rem_elem_from_bottom(stk);
		ps_add_elem_to_top(extracted_elem, stk);
	}
	return ;
}

/* ************************************************************************** */
void	rev_rot_a(t_data *d)
{
	rev_rot(&d->a);
	ft_printf("rra\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
void	rev_rot_b(t_data *d)
{
	rev_rot(&d->b);
	ft_printf("rrb\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
void	rev_rot_2(t_data *d)
{
	rev_rot(&d->a);
	rev_rot(&d->b);
	ft_printf("rrr\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */