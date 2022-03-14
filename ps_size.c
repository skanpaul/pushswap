/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:26:24 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:26:26 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
int	ps_size(t_ps *top_elem)
{
	int		size;
	t_ps	*ptr;

	ptr = top_elem;
	if (!ptr)
		return (0);
	size = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}

/* ************************************************************************** */
int	ps_size_range(t_ps *start_elem, t_ps *end_elem)
{
	int		size;
	t_ps	*ptr;

	if ((!start_elem) || (!end_elem))
		return (0);
	ptr = start_elem;
	size = 0;
	while (ptr != end_elem)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}
