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

	d->a.size = ps_size(d->a.head);
	d->b.size = ps_size(d->b.head);

	loop = d->a.size / 2;
	i = 0;
	// swap pivot with end_element

	while(i < loop - 1)
	{
		push_to_b(d);
		i++;
		// display_2_list(d);
	}

	rev_rot_a(d);
	swap_a(d);
	rotate_a(d);

	d->pivot = d->a.tail;
	d->smaller = d->pivot->prev;
	d->bigger	= d->b.tail;

	// find elem bigger than pivot








	
}