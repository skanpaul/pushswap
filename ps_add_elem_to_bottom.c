/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add_elem_to_bottom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:00:08 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:00:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void ps_add_elem_to_bottom(t_ps *new, t_stk *stk)
{

	if ((!stk) || (new == NULL))
		return;

	new->stk_id = stk->stk_id;
	new->is_pivot = false;
	new->next = NULL;
	new->chk_start = false;
	new->chk_end = false;
	stk->size++;

	if (has_0_elem_only(&stk->head)) 
	{
		new->prev = NULL;
		stk->head = new;
		stk->tail = new;
	}
	else // if (has_1_elem_or_more())
	{
		stk->tail->next = new;
		new->prev = stk->tail;
		stk->tail = new;
	}
}

// /* ************************************************************************** */
// void ps_add_elem_to_bottom(t_ps *new, t_ps **stack, t_ps **stack_bottom)
// {
	
// 	if ((!stack) || (new == NULL))
// 		return;

// 	new->next = NULL;

// 	if (has_0_elem_only(stack)) 
// 	{
// 		new->prev = NULL;
// 		*stack = new;
// 		*stack_bottom = new;
// 	}
// 	else // if (has_1_elem_or_more())
// 	{
// 		(*stack_bottom)->next = new;
// 		new->prev = *stack_bottom;
// 		*stack_bottom = new;
// 	}
// }




// /* ************************************************************************** */
// void ps_add_elem_to_bottom(t_ps *new, t_ps **stack, t_ps **stack_bottom)
// {
// 	t_ps *top_elem;
// 	t_ps *bot_elem;
	
// 	if ((!stack) || (new == NULL))
// 		return;
// 	if (has_0_elem_only(stack)) 
// 	{
// 		*stack = new;
// 		new->prev = NULL;
// 	}
// 	else if (has_1_elem_only(stack))
// 	{
// 		top_elem = *stack;
// 		top_elem->next = new;
// 		new->prev = top_elem;
// 	}
// 	else // if (has_2_elem_or_more)
// 	{
// 		bot_elem = *stack_bottom;
// 		bot_elem->next = new;
// 		new->prev = bot_elem;
// 	}
// 	new->next = NULL;
// 	*stack_bottom = new;
// }



// /* ************************************************************************** */
// void ps_add_elem_to_bottom(t_ps *new, t_ps **stack, t_ps **stack_bottom)
// {
// 	t_ps *buf;

// 	if (!stack)
// 		return;

// 	buf = *stack; // initialize buffer with top_elem

// 	if (buf == NULL) // IF there is NO top_elem
// 	{
// 		*stack = new; // then new become head_of_stack
// 		new->prev = NULL;
// 		new->next = NULL;
// 		*stack_bottom = new; // then new become (also ) bottom_of_stack
// 	}
// 	else // ELSE (if),  there is at least 1 element
// 	{
// 		while (buf->next != NULL) // find the bottom_elem
// 			buf = buf->next;
				  
// 		buf->next = new;	// add new UNDER actual bottom_elem
// 		new->prev = buf;
// 		new->next = NULL;
// 		*stack_bottom = new; // then new become (also ) bottom_of_stack
// 	}

// 	return;
// }
