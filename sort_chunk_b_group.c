/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_b_group.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:03:01 by ski               #+#    #+#             */
/*   Updated: 2022/03/13 16:03:03 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static bool	is_chunk_b_group_sorted(t_data *d, int chunk_b_group_id);

/* ************************************************************************** */
// INPUT:	group_b_id (........)
// RETURN:	(-)
/* ************************************************************************** */
void	sort_chunk_b_group(t_data *d, int chunk_b_group_id)
{
	int	size_chunk_b;

	while (!is_chunk_b_group_sorted(d, chunk_b_group_id))
	{
		size_chunk_b = get_chunk_size(&d->b);
		if (size_chunk_b <= 3)
			sort_small_chunk_b_to_a(d);
		else
			sort_from_split_to_a(d);
	}
}

/* ************************************************************************** */
static bool	is_chunk_b_group_sorted(t_data *d, int chunk_b_group_id)
{
	if (has_0_elem_only(&d->b.head))
		return (true);
	if (d->b.head->chk_id < chunk_b_group_id)
		return (true);
	return (false);
}

/* ************************************************************************** */