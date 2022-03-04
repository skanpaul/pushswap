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
void	swap_far_algo5(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_a_and_b_elem(elem_1, elem_2, d);
	calculate_coef_5_to_8(d->a_elem, d->b_elem, d);

	rotate_a_loop(d, d->coef_a);
	rotate_b_loop(d, d->coef_c);
	push_to_a(d);
	swap_a(d);
	push_to_b(d);
	rev_rot_a_loop(d, d->coef_a);
	rev_rot_b_loop(d, d->coef_c);
}

/* ************************************************************************** */
void	swap_far_algo6(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_a_and_b_elem(elem_1, elem_2, d);
	calculate_coef_5_to_8(d->a_elem, d->b_elem, d);

	rotate_a_loop(d, d->coef_a);
	rev_rot_b_loop(d, d->coef_d);
	push_to_a(d);
	swap_a(d);
	push_to_b(d);
	rev_rot_a_loop(d, d->coef_a);
	rotate_b_loop(d, d->coef_d);
}

/* ************************************************************************** */
void	swap_far_algo7(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_a_and_b_elem(elem_1, elem_2, d);
	calculate_coef_5_to_8(d->a_elem, d->b_elem, d);

	rev_rot_a_loop(d, d->coef_b);
	rotate_b_loop(d, d->coef_c);
	push_to_a(d);
	swap_a(d);
	push_to_b(d);
	rotate_a_loop(d, d->coef_b);
	rev_rot_b_loop(d, d->coef_c);
}

/* ************************************************************************** */
void	swap_far_algo8(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_a_and_b_elem(elem_1, elem_2, d);
	calculate_coef_5_to_8(d->a_elem, d->b_elem, d);

	rev_rot_a_loop(d, d->coef_b);
	rev_rot_b_loop(d, d->coef_d);
	push_to_a(d);
	swap_a(d);
	push_to_b(d);
	rotate_a_loop(d, d->coef_b);
	rotate_b_loop(d, d->coef_d);
}
/* ************************************************************************** */
