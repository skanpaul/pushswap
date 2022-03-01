/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
int ps_get_position(t_data *d, t_ps *elem)
{
	int		i;
	t_ps	*temp;
	int		stk_size;

	if (elem->stk_id == STACK_ID_A)
	{
		temp = d->a.head;
		stk_size = d->a.size;
	}
	else
	{
		temp = d->b.head;
		stk_size = d->b.size;		
	}

	i = 0;
	while ((temp != elem) && (i < stk_size))
	{
		temp = temp->next;
		i++;
	}

	if ((temp != elem) && (i >= stk_size))
		return (-1);

	return (i);	

}