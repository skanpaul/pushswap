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
static void midsort_to_b_rec(t_data *d, int start, int end);
/* ************************************************************************** */
void midsort_to_b(t_data *d)
{
	midsort_to_b_rec(d, 0, d->a.size - 1);
}
/* ************************************************************************** */
static void midsort_to_b_rec(t_data *d, int start, int end)
{
	int mid_a;
	int mid_b;
	int chunk_b_size;
	int cnt_push_b;

	cnt_push_b = 0;

	mid_a = (end - start)/2 + start;
	mid_b = (mid_a - start)/2 + start;

	chunk_b_size = mid_a - start;

	if (d->a.size <= 2)
		return ;
	else
	{
		while (cnt_push_b < chunk_b_size)
		{
			/* ------------------------------------------------------ */
			if (d->a.head->index < mid_a)
			{
				push_to_b(d);
				cnt_push_b++;
			}
			else
				rotate_a(d);
			/* ------------------------------------------------------ */
			if (has_2_elem_or_more(&d->b.head) && (d->b.head->index < mid_b))
				rotate_b(d);
			/* ------------------------------------------------------ */
		}
		midsort_to_b_rec(d, mid_a, end);

	}

}

