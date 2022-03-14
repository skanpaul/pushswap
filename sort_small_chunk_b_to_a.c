/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_chunk_b_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:49 by ski               #+#    #+#             */
/*   Updated: 2022/03/07 15:49:51 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static void	sort_small_chunk_b_to_a_2_elem(t_data *d);
static void	sort_small_chunk_b_to_a_3_elem(t_data *d);

/* ************************************************************************** */
void	sort_small_chunk_b_to_a(t_data *d)
{
	int	chk_b_size;

	chk_b_size = get_chunk_size(&d->b);
	if ((chk_b_size == 1) || (is_chunk_b_in_order(d, chk_b_size)))
	{
		push_to_a_loop(d, chk_b_size);
		return ;
	}
	if (chk_b_size == 2)
		sort_small_chunk_b_to_a_2_elem(d);
	else if (chk_b_size == 3)
		sort_small_chunk_b_to_a_3_elem(d);
}

/* ************************************************************************** */
static void	sort_small_chunk_b_to_a_2_elem(t_data *d)
{
	if (d->b.head->next->index > d->b.head->index)
		swap_b(d);
	push_to_a_loop(d, 2);
}

/* ************************************************************************** */
static void	sort_small_chunk_b_to_a_3_elem(t_data *d)
{
	// step 1: -------------------------------
	if (d->b.head->next->index > d->b.head->index)
		swap_b(d);
	push_to_a(d);
	// step 2: -------------------------------
	if (d->b.head->next->index > d->b.head->index)
		swap_b(d);
	push_to_a(d);
	// step 3: -------------------------------
	if (d->a.head->next->index < d->a.head->index)
		swap_a(d);
	push_to_a(d);
}

/* ************************************************************************** */