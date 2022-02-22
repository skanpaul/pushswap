/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
// cas_1: boucle tant que head A > fond A | alors rot(A)
// cas_2: boucle tant que head B < fond B | alors rot(B)
// si cas_1 et cas_2 | alors rot(2) 
/* ************************************************************************** */
void do_rotation(t_data* d)
{
	while (
			(
				(has_2_elem_or_more(&d->head_a))
				&&
				(d->head_a->val > d->tail_a->val)
			)
			||
			(
				(has_2_elem_or_more(&d->head_b))
				&&
				(d->head_b->val < d->tail_b->val)
			)
		)
	{
		if (
			(has_2_elem_or_more(&d->head_a))
			&&
			(has_2_elem_or_more(&d->head_b))
			&&
			(d->head_a->val > d->tail_a->val)
			&&
			(d->head_b->val < d->tail_b->val)
			)
			rotate_2(d);

		if ((has_2_elem_or_more(&d->head_a))
			&& (d->head_a->val > d->tail_a->val))
			rotate_a(d);

		if ((has_2_elem_or_more(&d->head_b))
			&& (d->head_b->val < d->tail_b->val))
			rotate_b(d);
	}
}
/* ************************************************************************** */

// void do_rotation(t_data *d)
// {
//     while ((d->head_a->val > d->tail_a->val) 
//         || (d->head_b->val < d->tail_b->val))
//     {
//         if ((d->head_a->val > d->tail_a->val) 
//             && (d->head_b->val < d->tail_b->val))
//             rotate_2(d);

//         if (d->head_a->val > d->tail_a->val)
//             rotate_a(d);

//         if (d->head_b->val < d->tail_b->val)
//             rotate_b(d);
//     }
// }