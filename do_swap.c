/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
// cas_3: si head A > next A | alors swap(A)
// cas_4: si head B < next b | alors swap(B)
// si cas_3 et cas_4 | alors swap(2) 
/* ************************************************************************** */
void do_swap(t_data *d)
{
    while (
			(
				(has_2_elem_or_more(&d->head_a))
				&&
				(d->head_a->val > d->head_a->next->val)
			)
        	||
			(
				(has_2_elem_or_more(&d->head_b))
				&&
				(d->head_b->val < d->head_b->next->val)
			)	
		)
    {
        if (
			(has_2_elem_or_more(&d->head_a))
			&&
			(has_2_elem_or_more(&d->head_b))
			&&
			(d->head_a->val > d->head_a->next->val) 
        	&& 
			(d->head_b->val < d->head_b->next->val)
			)
            swap_2(d);

        if ((has_2_elem_or_more(&d->head_a))
			&& (d->head_a->val > d->head_a->next->val))
            swap_a(d);

        if ((has_2_elem_or_more(&d->head_b))
			&& (d->head_b->val < d->head_b->next->val))
            swap_b(d);        
    }
}
/* ************************************************************************** */
