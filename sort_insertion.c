/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
t_ps *sort_insertion(t_ps *stack)
{
	t_ps *stack_sorted;
	t_ps *top_elem;
	t_ps **ppTrail;

	// zero or one element in list
	if (!stack || !stack->next)
		return stack;

	/* build up the sorted array from the empty list */
	stack_sorted = NULL;

	/* take items off the input list one by one until empty */
	while (stack != NULL)
	{
		/* remember the head */
		top_elem = stack;
		/* trailing pointer for efficient splice */
		ppTrail = &stack_sorted;

		/* pop head off list */
		stack = stack->next;

		/* splice head into sorted list at proper place */
		while (!(*ppTrail == NULL || top_elem->val < (*ppTrail)->val))
		{ /* does head belong here? */
			/* no - continue down the list */
			ppTrail = &(*ppTrail)->next;
		}

		top_elem->next = *ppTrail;
		*ppTrail = top_elem;
	}

	return stack_sorted;
}
