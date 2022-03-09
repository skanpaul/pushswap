/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_chunk_in_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:34:13 by ski               #+#    #+#             */
/*   Updated: 2022/03/08 15:34:18 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_chunk_a_in_order(t_data *d, int chk_size)
{
	int i;
	t_ps *temp;

	temp = d->b.head;

	if (!has_2_elem_or_more(&temp))
		return (false);

	i = 0;
	while (i < chk_size - 1)
	{
		if (temp->index > temp->next->index)
			return (false);
		i++;
	}
	return (true);
}

/* ************************************************************************** */
bool is_chunk_b_in_order(t_data *d, int chk_size)
{
	int i;
	t_ps *temp;

	temp = d->b.head;

	if (!has_2_elem_or_more(&temp))
		return (false);

	i = 0;
	while (i < chk_size - 1)
	{
		if (temp->index < temp->next->index)
			return (false);
		i++;
	}
	return (true);
}