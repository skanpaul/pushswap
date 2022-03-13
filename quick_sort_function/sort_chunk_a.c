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
#include "../push_swap.h"
// #include "push_swap.h"

/* ************************************************************************** */
void sort_chunk_a(t_data *d)
{
	int size_chunk_a;

	size_chunk_a = get_chunk_size(&d->a);

	if (size_chunk_a <= MAX_SIZE_OF_UNSORTED_CHUNK)
		sort_small_chunk_a(d);
	else
		sort_from_split_to_b(d);
}
