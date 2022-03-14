/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:08:57 by ski               #+#    #+#             */
/*   Updated: 2022/03/14 10:09:03 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void sort_2_elem(t_data *d)
{
	swap_a(d);
}

/* ************************************************************************** */
void sort_3_elem(t_data *d)
{
	if((d->a.head->index == 2) && (d->a.head->next->index == 1) 
		&& (d->a.head->next->next->index == 0))
	{
		swap_a(d);
		rev_rot_a(d);
	}
	else if ((d->a.head->index == 1) && (d->a.head->next->index == 0) 
		&& (d->a.head->next->next->index == 2))
			swap_a(d);
	else
	{
		if (d->a.head->index > d->a.head->next->index)
			swap_a(d);	
		rotate_a(d);
		if (d->a.head->index > d->a.head->next->index)
			swap_a(d);
		rev_rot_a(d);
	}
}
