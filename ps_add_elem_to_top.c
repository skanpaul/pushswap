/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add_elem_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:00:08 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:00:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void ps_add_elem_to_top(t_ps *new, t_stk *stk)
{
	
	if ((!stk) || (new == NULL))
		return;

	new->stk_id = stk->stk_id;
	new->prev = NULL;

	if (has_0_elem_only(&stk->head)) // IF there is NO top_elem
	{		
		new->next = NULL;
		stk->head = new;
		stk->tail= new;
	}
	else //if (has_1_elem_or_more)
	{
		stk->head->prev = new;
		new->next = stk->head;
		stk->head = new;
	}
}

// /* ************************************************************************** */
// void ps_add_elem_to_top(t_ps *new, t_ps **stack, t_ps **stack_bottom)
// {
	
// 	if ((!stack) || (new == NULL))
// 		return;

// 	new->prev = NULL;

// 	if (has_0_elem_only(stack)) // IF there is NO top_elem
// 	{		
// 		new->next = NULL;
// 		*stack = new;
// 		*stack_bottom = new;
// 	}
// 	else //if (has_1_elem_or_more)
// 	{
// 		(*stack)->prev = new;
// 		new->next = *stack;
// 		*stack = new;
// 	}
// }



// /* ************************************************************************** */
// void ps_add_elem_to_top(t_ps *new, t_ps **stack, t_ps **stack_bottom)
// {
// 	t_ps *top_elem;
// 	t_ps *bot_elem;
	
// 	if ((!stack) || (new == NULL))
// 		return;

// 	if (has_0_elem_only(stack)) // IF there is NO top_elem
// 	{
// 		*stack = new; // then new become head_of_stack
// 		new->prev = NULL;
// 		new->next = NULL;
// 		*stack_bottom = new; // then new become (also ) bottom_of_stack
// 	}
// 	else if (has_1_elem_only(stack))
// 	{
// 		bot_elem = *stack_bottom;
// 		bot_elem->prev = new;		
// 		new->prev = NULL;
// 		new->next = *stack_bottom;
// 		*stack = new;
// 	}
// 	else  // if (has_2_elem_or_more)
// 	{
// 		top_elem = *stack;
// 		top_elem->prev = new;
// 		new->prev = NULL;
// 		new->next = top_elem;
// 		*stack = new;	
// 	}
// }



// /* ************************************************************************** */
// void ps_add_elem_to_top(t_ps *new, t_ps **stack, t_ps **stack_bottom)
// {
// 	t_ps *top_elem;
	
// 	if ((!stack) || (new == NULL))
// 		return;

// 	if (has_0_elem_only(stack)) // IF there is NO top_elem
// 	{
// 		*stack = new; // then new become head_of_stack
// 		new->prev = NULL;
// 		new->next = NULL;
// 		*stack_bottom = new; // then new become (also ) bottom_of_stack
// 	}
// 	else
// 	{
// 		top_elem = *stack;
// 		*stack = new; // then new become (also ) top_of_stack
// 		new->prev = NULL;
// 		new->next = top_elem;
// 		top_elem->prev = new;
// 	}

// 	return;
// }