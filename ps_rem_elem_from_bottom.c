/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rem_elem_from_bottom.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:00:08 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:00:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
t_ps *ps_rem_elem_from_bottom(t_stk *stk)
{
	t_ps *elem_extracted;
	
	if ((!stk) || (has_0_elem_only(&stk->head)))
		return (NULL);       

    elem_extracted = stk->tail;
	stk->size--;
	elem_extracted->stk_id = 0;

    if (has_1_elem_only(&stk->head))
    {
        stk->head = NULL;
        stk->tail = NULL;         
    }  
	else // if (has_2_elem_or_more)
    {
        stk->tail = stk->tail->prev;
        stk->tail->next = NULL;
    }
    elem_extracted->prev = NULL;
    elem_extracted->next = NULL;  
	return (elem_extracted);
}

// /* ************************************************************************** */
// t_ps *ps_rem_elem_from_bottom(t_stk *stk)
// {
// 	t_ps *elem_extracted;
	
// 	if ((!stk) || (has_0_elem_only(&stk->head)))
// 		return (NULL);       

//     elem_extracted = stk->tail;
// 	stk->size--;
// 	elem_extracted->stk_id = 0;

//     if (has_1_elem_only(&stk->head))
//     {
//         stk->head = NULL;
//         stk->tail = NULL;         
//     }  
// 	else // if (has_2_elem_or_more)
//     {
//         stk->tail = stk->tail->prev;
//         stk->tail->next = NULL;
//     }
//     elem_extracted->prev = NULL;
//     elem_extracted->next = NULL;  
// 	return (elem_extracted);
// }


// /* ************************************************************************** */
// t_ps *ps_rem_elem_from_bottom(t_ps **stack, t_ps **stack_bottom)
// {
// 	t_ps *elem_extracted;
// 	t_ps *prev_elem;
	
// 	if ((!stack) || (has_0_elem_only(stack)))
// 		return (NULL);   

//     elem_extracted = *stack_bottom;
//     prev_elem = elem_extracted->prev;

//     if (has_1_elem_only(stack))
//     {
//         *stack = NULL;
//         *stack_bottom = NULL;
//     }  
// 	else
//     {
//         *stack_bottom = prev_elem;
//         prev_elem->next = NULL;

//         if (has_2_elem_only(stack))
//             (*stack)->next = NULL;
// 	}
//     elem_extracted->prev = NULL;
//     elem_extracted->next = NULL;
// 	return (elem_extracted);
// }