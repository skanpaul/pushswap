/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_more_than_1_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool has_less_than_2_elem(t_ps *top_elem)
{
    t_ps *elem;
	t_ps *next_elem;

	/* test si 0 ou 1 element --> pas besoin de controller */
	elem = top_elem;
	if (elem == NULL)
		return (true);
	next_elem = elem->next;
	if (next_elem == NULL)
		return (true);
    
    return (false);
}