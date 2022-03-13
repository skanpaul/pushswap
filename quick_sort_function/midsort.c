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
#include "../push_swap.h"
// #include "push_swap.h"

/* ************************************************************************** */
void midsort(t_data *d)
{
	if ((!is_in_order(d->a.head)) || (!has_0_elem_only(&d->b.head)))
		sort_a(d, 0);

}

/* ************************************************************************** */
// void sort_a(t_data *d)
void sort_a(t_data *d, int cnt_rev_rot_a)
{
	int chk_a_size;

	chk_a_size = get_chunk_size(&d->a);
	sort_chunk_a(d, chk_a_size); // inclu split_to_b

	rev_rot_a_loop(d, cnt_rev_rot_a);

	chk_a_size = get_chunk_size(&d->a);
	sort_chunk_a(d, chk_a_size);

	sort_chunk_b_to_a(d);
	

	if ((!is_in_order(d->a.head)) || (!has_0_elem_only(&d->b.head)))
		split_to_a(d);
}

/* ************************************************************************** */
// void sort_a(t_data *d)
// {
// 	int chk_a_size;

// 	/* SPLIT to B ------------------------------------ */
// 	chk_a_size = get_chunk_size(&d->a);
// 	if (chk_a_size > MAX_SIZE_OF_UNSORTED_CHUNK)
// 		split_to_b(d);

// 	/* SORT CHUNK A ---------------------------------- */
// 	chk_a_size = get_chunk_size(&d->a);
// 	sort_chunk_a(d, chk_a_size);

// 	/* SORT CHUNK B to A ----------------------------- */	
// 	sort_chunk_b_to_a(d);

// 	/* SPLIT to A ------------------------------------ */

// 	if ((!is_in_order(d->a.head)) || (!has_0_elem_only(&d->b.head)))
// 		split_to_a(d);

// }