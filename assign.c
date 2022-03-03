/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:17:22 by ski               #+#    #+#             */
/*   Updated: 2022/03/03 13:17:24 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* for algo 1 to 4 ********************************************************** */
void	assign_high_and_low_elem(t_ps *elem_1, t_ps *elem_2, t_data *d)
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
		d->pos_h_elem = temp;
	}
}

/* for algo 5 to 8 ********************************************************** */
void	assign_a_and_b_elem(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	d->a_elem = elem_1;
	d->b_elem = elem_2;
	d->algo_direction = DIR_A_TO_B;

	if (elem_1->stk_id == STACK_ID_B)
	{
		d->a_elem = elem_2;
		d->b_elem = elem_1;
		d->algo_direction = DIR_B_TO_A;
	}
}

/* ************************************************************************** */
void assign_fct(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	/* if stack A ----------------- */
	d->p = &push_to_b_loop;
	d->p_back = &push_to_a_loop;
	d->rot = &rotate_a_loop;
	d->rev = &rev_rot_a_loop;
	d->s = &swap_a;
	if ((elem_1->stk_id == STACK_ID_B) && (elem_2->stk_id == STACK_ID_B))
	{
		/* if stack B ----------------- */
		d->p = &push_to_a_loop;
		d->p_back = &push_to_b_loop;
		d->rot = &rotate_b_loop;
		d->rev = &rev_rot_b_loop;
		d->s = &swap_b;
	}
}

/* ************************************************************************** */