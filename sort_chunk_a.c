/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:18:21 by ski               #+#    #+#             */
/*   Updated: 2022/03/09 18:18:23 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void sort_chunk_a_2_elem(t_data *d);
void sort_chunk_a_3_elem(t_data *d);

/* ************************************************************************** */
void sort_chunk_a(t_data *d, int chk_a_size)
{
	if ((chk_a_size == 1) || (is_chunk_a_in_order(d, chk_a_size)))
		return ;	
	
	if (chk_a_size == 2)
		sort_chunk_a_2_elem(d);
	else // if (chk_a_size == 3)
		sort_chunk_a_3_elem(d);	
}
/* ************************************************************************** */
void sort_chunk_a_2_elem(t_data *d)
{
	if (d->a.head->next->index < d->a.head->index)
		swap_a(d);
}
/* ************************************************************************** */
void sort_chunk_a_3_elem(t_data *d)
{
	// step 1: -------------------------------
	if(d->a.head->next->index < d->a.head->index)
		swap_a(d);	
	push_to_b(d);

	// step 2: -------------------------------
	if(d->a.head->next->index < d->a.head->index)
		swap_a(d);	
	push_to_a(d);

	// step 3: -------------------------------
	if(d->a.head->next->index < d->a.head->index)
		swap_a(d);
}

// /* ************************************************************************** */
// void sort_chunk_a_4_elem(t_data *d, int chk_a_size)
// {

// }
// /* ************************************************************************** */
// void sort_chunk_a_5_elem(t_data *d, int chk_a_size)
// {

// }


