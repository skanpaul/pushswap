/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:49 by ski               #+#    #+#             */
/*   Updated: 2022/03/07 15:49:51 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void sort_small_to_a(t_data *d)
{
	int chk_size;

	chk_size = get_chunk_size(&d->b);

	while (d->b.size > 0)
	{
		if (is_chunk_b_in_order(d, chk_size))
			push_to_a_loop(d, chk_size);
		else if (chk_size <= 3)
			sort_3_elem_or_less(d, chk_size);
			

		chk_size = get_chunk_size(&d->b);

		if (chk_size > 3)
			break;
	}

}
/* ************************************************************************** */
	// check chunk size
	// size 1: just push_to_a
	// size 2; swap and push_to_a
	// size 3: sorting
	// size 5: sorting
	// size > 5; midsort_to_b
