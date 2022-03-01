/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void quick_sort(t_data *d)
{
	int loop;
	int i;

	// 1) CHOOSE THE PIVOT -----------------------
	loop = d->a.size / 2;
	i = 0;

	// 2) swap pivot with end_element ------------
	while(i < loop - 1)
	{
		push_to_b(d);
		i++;
		// display_2_list(d);
	}

	rev_rot_a(d);
	swap_a(d);
	rotate_a(d);

	// 3) Positioning p_small and p_big ----------
	d->pivot = d->a.tail;
	d->smaller = d->pivot->prev;
	d->bigger	= d->b.tail;

	// 4) find elem bigger than pivot ------------
	find_bigger_than_pivot(d);
	find_smaller_than_pivot(d);

	
	
}