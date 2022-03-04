/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_far_elem_part_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:55:40 by ski               #+#    #+#             */
/*   Updated: 2022/03/03 10:55:43 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	swap_far_algo9(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_high_and_low_elem(elem_1, elem_2, d);
	calculate_coef_9_or_10(d);
	assign_fct(elem_1, elem_2, d);
	d->rot(d, d->coef_a);
	d->s(d);
	d->rev(d, d->coef_a);
}

/* ************************************************************************** */
void	swap_far_algo10(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_high_and_low_elem(elem_1, elem_2, d);
	calculate_coef_9_or_10(d);
	assign_fct(elem_1, elem_2, d);
	d->rev(d, d->coef_b);
	d->s(d);
	d->rot(d, d->coef_b);
}

