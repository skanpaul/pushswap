/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_chunk_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:39:13 by ski               #+#    #+#             */
/*   Updated: 2022/03/13 14:39:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	sort_small_chunk_a_2_elem(t_data *d);
void	sort_small_chunk_a_3_elem(t_data *d);

/* ************************************************************************** */
void	sort_small_chunk_a(t_data *d)
{
	int	size_chunk_a;

	size_chunk_a = get_chunk_size(&d->a);
	if ((size_chunk_a == 1) || (is_chunk_a_in_order(d, size_chunk_a)))
		return ;
	if (size_chunk_a == 2)
		sort_small_chunk_a_2_elem(d);
	else if (size_chunk_a == 3)
		sort_small_chunk_a_3_elem(d);
}

/* ************************************************************************** */
void	sort_small_chunk_a_2_elem(t_data *d)
{
	if (d->a.head->next->index < d->a.head->index)
		swap_a(d);
}

/* ************************************************************************** */
void	sort_small_chunk_a_3_elem(t_data *d)
{
	// step 1: -------------------------------
	if (d->a.head->next->index < d->a.head->index)
		swap_a(d);
	push_to_b(d);
	// step 2: -------------------------------
	if (d->a.head->next->index < d->a.head->index)
		swap_a(d);
	push_to_a(d);
	// step 3: -------------------------------
	if (d->a.head->next->index < d->a.head->index)
		swap_a(d);
}

/* ************************************************************************** */