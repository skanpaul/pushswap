/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_new_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:43:01 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 09:43:03 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
t_ps	*ps_new_elem(int val)
{
	t_ps	*elem;

	elem = (t_ps *)malloc(1 * sizeof(t_ps));
	if (!elem)
		return (NULL);
	elem->val = val;
	elem->prev = NULL;
	elem->next = NULL;
	elem->is_pivot = false;
	elem->sorted = false;
	return (elem);
}
