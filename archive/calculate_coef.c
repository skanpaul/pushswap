/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluculate_coef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:22:13 by ski               #+#    #+#             */
/*   Updated: 2022/03/01 17:22:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
// void calculate_coef(t_ps *elem_1, t_ps *elem_2, t_data *d)
// {

// 	assign_high_and_low_elem(elem_1, elem_2, d);
// 	calculate_coef_1_or_2(d);
// 	calculate_coef_3_or_4(d);
// 	assign_a_and_b_elem(elem_1, elem_2, d);
// 	calculate_coef_5_to_8(d->a_elem, d->b_elem, d);
	
// 	if (elem_1->stk_id == elem_2->stk_id)
// 		d->cur_stk = elem_1->stk_id;

// }
void calculate_coef(t_ps *elem_1, t_ps *elem_2, t_data *d)
{

	if (elem_1->stk_id == elem_2->stk_id)
	{
		assign_high_and_low_elem(elem_1, elem_2, d);
		d->cur_stk = elem_1->stk_id;
		if(d->h_elem->next == d->l_elem)
			calculate_coef_9_or_10(d);
		else
		{
			calculate_coef_1_or_2(d);
			calculate_coef_3_or_4(d);
		}
	}
	else
	{
		assign_a_and_b_elem(elem_1, elem_2, d);
		calculate_coef_5_to_8(d->a_elem, d->b_elem, d);
	}
}

/* ************************************************************************** */
void calculate_coef_1_or_2(t_data *d)
{
	d->cur_stk_size = ps_size(d->a.head);
	if (d->cur_stk == STACK_ID_B)
		d->cur_stk_size = ps_size(d->b.head);

	d->coef_a = d->pos_h_elem + 1;
	d->coef_b = d->pos_l_elem - d->pos_h_elem - 1;
	d->coef_c = d->cur_stk_size - d->pos_l_elem;

	// d->algo_1.coef = d->coef_a + (2 * d->coef_b) + 3;
	// d->algo_2.coef = d->coef_a + (2 * d->coef_c) + 3;
	d->algo_1.coef = (2 * d->coef_a) + (2 * d->coef_b) + 3;
	d->algo_2.coef = (2 * d->coef_a) + (2 * d->coef_c) + 3;

	// d->algo_1.a = d->pos_h_elem + 1;
	// d->algo_1.b = d->pos_l_elem - d->pos_h_elem - 1;
	// d->algo_1.c = d->cur_stk_size - d->pos_l_elem;
	// d->algo_1.complexity = d->algo_1.a + (2 * d->algo_1.b) + 3;
	// d->algo_2.complexity = d->algo_1.a + (2 * d->algo_1.b) + 3;
	// d->algo_2 = d->algo_1;
	// d->algo_2.id = ALGO_2;
}

/* ************************************************************************** */
void calculate_coef_3_or_4(t_data *d)
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

/* for algo 5 to 8 ********************************************************** */
void calculate_coef_5_to_8(t_ps *elem_a, t_ps *elem_b,  t_data *d)
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

/* for algo 9 or 10 ********************************************************** */
void calculate_coef_9_or_10(t_data *d)
{
	d->cur_stk_size = ps_size(d->a.head);
	if (d->cur_stk == STACK_ID_B)
		d->cur_stk_size = ps_size(d->b.head);

	d->coef_a = d->pos_h_elem;
	d->coef_b = d->cur_stk_size - d->pos_h_elem;

	d->algo_9.coef = (2 * d->coef_a) + 1;
	d->algo_10.coef = (2 * d->coef_b) + 1;
}

