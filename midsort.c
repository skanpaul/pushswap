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
	if ((!is_in_order(d->a.head)) || (!has_0_elem_only(&d->b.head)))
		sort_a(d, 0);

}

/* ************************************************************************** */
// void sort_a(t_data *d)
void sort_a(t_data *d, int cnt_rev_rot_a)
{
	
	int chk_a_size;

	chk_a_size = get_chunk_size(&d->a);

	
	sort_chunk_a(d); 

	if (cnt_rev_rot_a != 0)
	{
		rev_rot_a_loop(d, cnt_rev_rot_a);
		cnt_rev_rot_a = 0;
		sort_a(d, 0);
		// sort_a(d, cnt_rev_rot_a);
	}

	if ((!is_in_order(d->a.head)) || (!has_0_elem_only(&d->b.head)))
		sort_b(d);

	
}

/* ************************************************************************** */
void sort_b(t_data *d)
{

	sort_chunk_b_to_a(d);	
	
	if ((!is_in_order(d->a.head)) || (!has_0_elem_only(&d->b.head)))
		sort_a(d, 0);
}