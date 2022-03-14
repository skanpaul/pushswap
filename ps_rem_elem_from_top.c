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
t_ps	*ps_rem_elem_from_top(t_stk *stk)
{
	t_ps	*elem_extracted;

	if ((!stk) || (has_0_elem_only(&stk->head)))
		return (NULL);
	elem_extracted = stk->head;
	stk->size--;
	elem_extracted->stk_id = 0;
	if (has_1_elem_only(&stk->head))
	{
		stk->head = NULL;
		stk->tail = NULL;
	}
	else
	{
		stk->head = stk->head->next;
		stk->head->prev = NULL;
	}
	elem_extracted->prev = NULL;
	elem_extracted->next = NULL;
	return (elem_extracted);
}

/* ************************************************************************** */
