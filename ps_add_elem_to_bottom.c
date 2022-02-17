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
void	ps_add_elem_to_bottom(t_ps **top_elem, t_ps *new_elem)
{
	t_ps	*ptr;

	if(!top_elem)
		return;

	ptr = *top_elem;
	if (ptr == NULL)
	{
		*top_elem = new_elem;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_elem;
	return ;
}
