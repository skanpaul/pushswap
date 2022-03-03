/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_far_elem_part_12.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:55:52 by ski               #+#    #+#             */
/*   Updated: 2022/03/03 10:55:57 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void swap_far_algo1(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_high_and_low_elem(elem_1, elem_2, d);
	calculate_coef_1_or_2(d);
	assign_fct(elem_1, elem_2, d);
	d->p(d, d->coef_a);
	d->rot(d, d->coef_b);
	d->p_back(d, 1);
	d->s(d);
	d->p(d, 1);
	d->rev(d, d->coef_b);
}

/* ************************************************************************** */
void swap_far_algo2(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	assign_high_and_low_elem(elem_1, elem_2, d);
	calculate_coef_1_or_2(d);
	assign_fct(elem_1, elem_2, d);
	d->p(d, d->coef_a);
	d->rev(d, d->coef_c);
	d->p_back(d, 1);
	d->s(d);
	d->p(d, 1);
	d->rot(d, d->coef_c);
}

/* ************************************************************************** */
	// void (*p)(t_data *d, int loop);
	// void (*p_back)(t_data *d, int loop);
	// void (*rot)(t_data *d, int loop);
	// void (*rev)(t_data *d, int loop);
	// void (*s)(t_data *d);
	

	// assign_high_and_low_elem(elem_1, elem_2, d);
	// /* if stack A ----------------- */
	// p = &push_to_b_loop;
	// p_back = &push_to_a_loop;
	// rot = &rotate_a_loop;
	// rev = &rev_rot_a_loop;
	// s = &swap_a;
	// if (elem_1->stk_id == STACK_ID_B)
	// {
	// 	/* if stack B ----------------- */
	// 	p = &push_to_a_loop;
	// 	p_back = &push_to_b_loop;
	// 	rot = &rotate_b_loop;
	// 	rev = &rev_rot_b_loop;
	// 	s = &swap_b;
	// }
