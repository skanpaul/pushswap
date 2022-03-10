/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:49 by ski               #+#    #+#             */
/*   Updated: 2022/03/07 15:49:51 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void midsort(t_data *d)
{
	// while ((!is_in_order(&d->a.head)) && (!has_0_elem_only(&d->b.head)))

	if ((!is_in_order(d->a.head)) || (!has_0_elem_only(&d->b.head)))
		sort_a(d);

}

/* ************************************************************************** */
void sort_a(t_data *d)
{
	int chk_a_size;

	/* SPLIT to B ------------------------------------ */
	chk_a_size = get_chunk_size(&d->a);
	if (chk_a_size > MAX_SIZE_OF_UNSORTED_CHUNK_A)
		split_to_b(d);

	/* SORT CHUNK A ---------------------------------- */
	chk_a_size = get_chunk_size(&d->a);
	sort_chunk_a(d, chk_a_size);
	/* ----------------------------------------------- */
	
	sort_chunk_b_to_a(d);


}