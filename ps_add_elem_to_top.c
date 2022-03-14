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
void	ps_add_elem_to_top(t_ps *new, t_stk *stk)
{
	if ((!stk) || (new == NULL))
		return ;
	new->stk_id = stk->stk_id;
	stk->size++;
	new->prev = NULL;
	if (has_0_elem_only(&stk->head))
	{		
		new->next = NULL;
		stk->head = new;
		stk->tail = new;
	}
	else
	{
		stk->head->prev = new;
		new->next = stk->head;
		stk->head = new;
	}
}

/* ************************************************************************** */