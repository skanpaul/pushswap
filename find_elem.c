/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void find_bigger_than_pivot(t_data *d)
{
	while (d->bigger->val < d->pivot->val)
	{
		// in B: p_big move UP -------------------------------
		if(d->bigger->stk_id == STACK_ID_B)
		{
			if (d->bigger->prev == NULL)
				d->bigger = d->a.head;
			else
				d->bigger = d->bigger->prev;
		}
		// in A: p_big move DOWN -------------------------------
		else
		{
			if (d->bigger->next == NULL)
				break;
			d->bigger = d->bigger->next;
		}
	}
}

/* ************************************************************************** */
void find_smaller_than_pivot(t_data *d)
{
	while (d->smaller->val >= d->pivot->val)
	{
		// in A: p_small move UP -------------------------------
		if(d->smaller->stk_id == STACK_ID_A)
		{
			if (d->smaller->prev == NULL)
				d->smaller = d->b.head;
			else
				d->smaller = d->smaller->prev;
		}
		// in B: p_small move DOWN -----------------------------
		else
		{
			if (d->smaller->next == NULL)
				break ;
			d->smaller = d->smaller->next;
		}
	}
}
