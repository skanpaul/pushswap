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
void	ps_add_elem_to_bottom(t_ps *new, t_stk *stk)
{
	if ((!stk) || (new == NULL))
		return ;
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
	else
	{
		stk->tail->next = new;
		new->prev = stk->tail;
		stk->tail = new;
	}
}

/* ************************************************************************** */
