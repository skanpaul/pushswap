/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_add_elem_to_bottom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:00:08 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:00:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void ps_add_elem_to_bottom(t_ps *new, t_ps **stack, t_ps **stack_bottom)
{
	t_ps *buf;

	if (!stack)
		return;

	buf = *stack; // initialize buffer with top_elem

	if (buf == NULL) // IF there is NO top_elem
	{
		*stack = new; // then new become head_of_stack
		new->prev = NULL;
		new->next = NULL;
	}
	else // ELSE (if),  there is at least 1 element
	{
		while (buf->next != NULL) // find the bottom_elem
			buf = buf->next;
				  
		buf->next = new;	// add new UNDER actual bottom_elem
		new->prev = buf;
		new->next = NULL;
	}
	
	*stack_bottom = new; // then new become (also ) bottom_of_stack
	return;
}
