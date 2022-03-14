/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool	is_in_order(t_ps *top_elem)
{
	t_ps	*elem;
	t_ps	*next_elem;

	elem = top_elem;
	if (elem == NULL)
		return (true);
	next_elem = elem->next;
	if (next_elem == NULL)
		return (true);
	while (1)
	{
		if (elem->val > next_elem->val)
			return (false);
		elem = elem->next;
		next_elem = next_elem->next;
		if (next_elem == NULL)
			break ;
	}
	return (true);
}

/* ************************************************************************** */