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
// void ps_sort_insertion(t_data *d)
// {
// 	t_ps	*temp;
// 	t_ps	*temp_next;
// 	t_ps	*top_elem;

// 	top_elem = d->stack_a;

// 	if ((top_elem == NULL) || (top_elem->next == NULL))
// 		return ;







// 	temp = d->stack_a



// 	return ;
// }

/* ************************************************************************** */
/* ps_sort_insertion_rec()                                                    */
/* -----------------------                                                    */
/* input:	bot_elem of SUB-stack (BEFORE SORTING)                            */
/* output:	new_bot_elem of SORTED SUB-stack (AFTER SORTING)                  */
/* ************************************************************************** */
static t_ps *ps_sort_insertion_rec(t_ps *sub_bot, t_data *d)
{
	t_ps *sub_top;

	sub_top = sub_bot->prev;

	if (sub_top->prev == NULL)
		if (sub_top->val > sub_bot->val)
			swap_a(d);
	else
	{
		// recusrion
	}


	return (null);
}






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
