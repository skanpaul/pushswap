/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:34:13 by ski               #+#    #+#             */
/*   Updated: 2022/03/08 15:34:18 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
// void sort_4_elem_or_more(t_data *d, int chk_size)
// {

// }

/* ************************************************************************** */
void sort_3_elem_or_less(t_data *d, int chk_size)
{
	if (is_chunk_b_in_order(d, chk_size))
		push_to_a_loop(d, chk_size);
	else
	{
		if (chk_size == 1)
			sort_1_to_a(d);
		else if (chk_size == 2)
			sort_2_to_a(d);
		else if (chk_size == 3)
			sort_3_to_a(d);
	}
}

/* ************************************************************************** */
void sort_1_to_a(t_data *d)
{
	push_to_a(d);
}

/* ************************************************************************** */
void sort_2_to_a(t_data *d)
{
	if (d->b.head->next->index > d->b.head->index)
		swap_b(d);
	
	push_to_a_loop(d, 2);
}

/* ************************************************************************** */
void sort_3_to_a (t_data *d)
{
	// step 1: -------------------------------
	if(d->b.head->next->index > d->b.head->index)
		swap_b(d);	
	push_to_a(d);

	// step 2: -------------------------------
	if(d->b.head->next->index > d->b.head->index)
		swap_b(d);	
	push_to_a(d);

	// step 3: -------------------------------
	if(d->a.head->next->index < d->a.head->index)
		swap_a(d);
	push_to_a(d);
}
