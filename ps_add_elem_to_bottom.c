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
void	ps_add_elem_to_bottom(t_ps **ptr_top, t_ps *new_elem)
{
	t_ps	*elem;

	if(!ptr_top)
		return;

	elem = *ptr_top;
	if (elem == NULL)
	{
		*ptr_top = new_elem;
		return ;
	}
	while (elem->next != NULL)
		elem = elem->next;
	
	elem->next = new_elem;
	new_elem->prev = elem;
	return ;
}
