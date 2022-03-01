/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* 1st elem of a stack has: position = 0 (like an array) 							  */
/* ************************************************************************** */
t_ps *ps_get_elem(t_stk *stk, int position)
{
	int i;
	t_ps *elem;

	if (position > stk->size)
		return (stk->tail);

	elem = stk->head;
	i = 0;

	while (i != position)
	{
		elem = elem->next;
		i++;
	}

	return (elem);
}