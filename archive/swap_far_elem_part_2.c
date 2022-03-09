/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_far_elem_part_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:55:40 by ski               #+#    #+#             */
/*   Updated: 2022/03/03 10:55:43 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void swap_far_algo3(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_high_and_low_elem(elem_1, elem_2, d);
	calculate_coef_3_or_4(d);
	assign_fct(elem_1, elem_2, d);

	d->rev(d, d->coef_a);
	d->p(d, 1);
	d->rot(d, d->coef_b);
	d->p_back(d, 1);
	d->s(d);
	d->p(d, 1);
	d->rev(d, d->coef_b);
	d->p_back(d, 1);
	d->rot(d, d->coef_a);
}

/* ************************************************************************** */
void swap_far_algo4(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_high_and_low_elem(elem_1, elem_2, d);
	calculate_coef_3_or_4(d);
	assign_fct(elem_1, elem_2, d);

	d->rev(d, d->coef_a);
	d->p(d, 1);
	d->rev(d, d->coef_c);
	d->p_back(d, 1);
	d->s(d);
	d->p(d, 1);
	d->rot(d, d->coef_c);
	d->p_back(d, 1);
	d->rot(d, d->coef_a);
}

/* ************************************************************************** */
