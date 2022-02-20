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
// static void ps_rec_sort_insertion(t_ps **sub_bot_elem, t_data *d);
// static bool is_top_elem(t_ps *elem);

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
// static void ps_rec_sort_insertion(t_ps **sub_bot_elem, t_data *d)
// {
// 	t_ps *prev_elem;
// 	t_ps *bot_elem;

// 	bot_elem = *sub_bot_elem;
// 	prev_elem = bot_elem->prev;

// 	// if SUB-stack has 2 elements ONLY
// 	/* ------------------------------------------------ */
// 	if (is_top_elem(prev_elem) && (bot_elem->val < prev_elem->val))
// 	{
// 		swap_a(d);
// 	}
// 	/* if SUB-stack has MORE THAN 2 elements ---------- */
// 	else
// 	{
// 		ps_rec_sort_insertion(&prev_elem, d);

// 		if (bot_elem->val < prev_elem->val)
// 		{
// 			while (is_top_elem(prev_elem) == false)
// 				push_to_b(d);
// 			swap_a(d);
// 			prev_elem = bot_elem->prev;
// 		}



		
// 	}
// 	/* ------------------------------------------------ */

// 	return ;
// }
/* ************************************************************************** */

// static bool is_top_elem(t_ps *elem)
// {
// 	if (elem->prev == NULL)
// 		return (true);
// 	else
// 		return (fales);
// }





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
