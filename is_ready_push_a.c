/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ready_push_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_ready_push_a(t_data *d)
{
	if ((has_1_elem_or_more(&d->head_a))
		&& (has_2_elem_or_more(&d->head_b)) 
		&& (d->head_b->val < d->head_b->next->val))
		return (false);

	if ((has_1_elem_or_more(&d->head_a))
		&& (has_1_elem_or_more(&d->head_b))
		&& (d->head_a->val < d->head_b->val)
		)
		return (false);
	
	if (
		has_1_elem_or_more(&d->head_a)
		&&
		has_1_elem_or_more(&d->head_b)
		&&
		(d->tail_ref != d->tail_a) 
		&& 
		(d->head_b->val < d->tail_a->val))
		return (false);


    return (true);
}

// /* ************************************************************************** */


		// if((has_1_elem_or_more(&d->head_b)) &&(
		// 		((d->tail_a != tail_ref) && (d->head_b->val > d->tail_a->val))
		// 		||
		// 		(d->tail_a == tail_ref)))

