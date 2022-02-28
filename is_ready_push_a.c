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
	if ((has_1_elem_or_more(&d->a.head))
		&& (has_2_elem_or_more(&d->b.head)) 
		&& (d->b.head->val < d->b.head->next->val))
		return (false);

	if ((has_1_elem_or_more(&d->a.head))
		&& (has_1_elem_or_more(&d->b.head))
		&& (d->a.head->val < d->b.head->val)
		)
		return (false);
	
	if (
		has_1_elem_or_more(&d->a.head)
		&&
		has_1_elem_or_more(&d->b.head)
		&&
		(d->tail_ref != d->a.tail) 
		&& 
		(d->b.head->val < d->a.tail->val))
		return (false);


    return (true);
}

// /* ************************************************************************** */


		// if((has_1_elem_or_more(&d->b.head)) &&(
		// 		((d->a.tail != tail_ref) && (d->b.head->val > d->a.tail->val))
		// 		||
		// 		(d->a.tail == tail_ref)))

