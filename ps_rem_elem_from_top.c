/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rem_elem_from_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:00:08 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:00:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
t_ps *ps_rem_elem_from_top(t_ps **stack, t_ps **stack_bottom)
{
	t_ps *elem_extracted;
	t_ps *next_elem;
	
	if ((!stack) || (has_0_elem_only(stack)))
		return (NULL);   

    elem_extracted = *stack;
    next_elem = elem_extracted->next;

    if (has_1_elem_only(stack))
    {
        *stack = NULL;
        *stack_bottom = NULL;
    }  
	else
    {
        *stack = next_elem;
        next_elem->prev = NULL;
        if (has_2_elem_only(stack))
            (*stack_bottom)->prev = NULL;
	}
    elem_extracted->prev = NULL;
    elem_extracted->next = NULL;
	return (elem_extracted);
}