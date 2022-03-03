/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluculate_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:22:13 by ski               #+#    #+#             */
/*   Updated: 2022/03/01 17:22:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static void	assign_high_and_low_elem(t_ps *elem_1, t_ps *elem_2, t_data *d);
static void	assign_a_and_b_elem(t_ps *elem_1, t_ps *elem_2, t_data *d);
static void caluculate_algo_1_or_2(t_data *d);
static void caluculate_algo_3_or_4(t_data *d);
static void caluculate_algo_5_to_8(t_ps *elem_a, t_ps *elem_b,  t_data *d);
/* ************************************************************************** */
int caluculate_algo_coef(t_ps *elem_1, t_ps *elem_2, t_data *d)
{

	if (elem_1->stk_id != elem_2->stk_id)
	{
		assign_a_and_b_elem(elem_1, elem_2, d);
		caluculate_algo_5_to_8(d->a_elem, d->b_elem, d);
	}
	else
	{
		assign_high_and_low_elem(elem_1, elem_2, d);
		d->cur_stk = elem_1->stk_id;
		caluculate_algo_1_or_2(d);
		caluculate_algo_3_or_4(d);
	}
	return (0);
}
// /* ************************************************************************** */
static void	assign_high_and_low_elem(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	int temp;
	
	d->h_elem = elem_1;
	d->l_elem = elem_2;
	d->pos_h_elem = ps_get_position(d, elem_1);
	d->pos_l_elem = ps_get_position(d, elem_2);
	if ( d->pos_l_elem < d->pos_h_elem)
	{
		d->h_elem = elem_2;
		d->l_elem = elem_1;

		temp = d->pos_l_elem;
		d->pos_l_elem = d->pos_h_elem;
		d->pos_l_elem = temp;
	}
}

// /* ************************************************************************** */
static void	assign_a_and_b_elem(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	d->a_elem = elem_1;
	d->b_elem = elem_2;

	if (elem_1->stk_id == STACK_ID_B)
		d->a_elem = elem_2;
		d->b_elem = elem_1;
}
// /* ************************************************************************** */
static void caluculate_algo_1_or_2(t_data *d)
{
	d->cur_stk_size = ps_size(d->a.head);
	if (d->cur_stk == STACK_ID_B)
		d->cur_stk_size = ps_size(d->b.head);

	d->coef_a = d->pos_h_elem + 1;
	d->coef_b = d->pos_l_elem - d->pos_h_elem - 1;
	d->coef_c = d->cur_stk_size - d->pos_l_elem;

	d->algo_1.coef = d->coef_a + (2 * d->coef_b) + 3;
	d->algo_2.coef = d->coef_a + (2 * d->coef_c) + 3;
}

// /* ************************************************************************** */
static void caluculate_algo_3_or_4(t_data *d)
{
	d->cur_stk_size = ps_size(d->a.head);
	if (d->cur_stk == STACK_ID_B)
		d->cur_stk_size = ps_size(d->b.head);

	d->coef_a = d->cur_stk_size - d->pos_l_elem;
	d->coef_b = d->pos_h_elem;
	d->coef_c = d->pos_l_elem - d->pos_h_elem;

	d->algo_3.coef = (2 * d->coef_a) + (2* d->coef_b) + 5;
	d->algo_4.coef = (2 * d->coef_a) + (2* d->coef_c) + 5;
}

// /* ************************************************************************** */
static void caluculate_algo_5_to_8(t_ps *elem_a, t_ps *elem_b,  t_data *d)
{
	d->coef_a = ps_get_position(d, elem_a);
	d->coef_b = d->a.size - d->coef_a;
	d->coef_c = ps_get_position(d, elem_b);
	d->coef_d = d->b.size - d->coef_c;

	d->algo_5.coef = (2 * d->coef_a) + (2 * d->coef_c) + 3;
	d->algo_6.coef = (2 * d->coef_a) + (2 * d->coef_d) + 3;
	d->algo_7.coef = (2 * d->coef_b) + (2 * d->coef_c) + 3;
	d->algo_8.coef = (2 * d->coef_b) + (2 * d->coef_d) + 3;
}

