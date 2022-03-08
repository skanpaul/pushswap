/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midsort_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:09:44 by ski               #+#    #+#             */
/*   Updated: 2022/03/08 15:09:46 by ski              ###   ########.fr       */
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
	int cnt_rot;

	cnt_rot = 0;
	cnt_push_b = 0;

	mid_a = (end - start)/2 + start;
	mid_b = (mid_a - start)/2 + start;

	chunk_b_size = mid_a - start + 1;

	// if (d->a.size <= 2)
	if (d->a.size == 0)
		return ;
	else
	{
		while (cnt_push_b < chunk_b_size)
		{
			/* ------------------------------------------------------ */
			if (d->a.head->index <= mid_a)
			{
				/* ---------------------------------------- */
				if (d->a.head->index <= mid_b)
					d->a.head->chk_n = mid_b;
				else
					d->a.head->chk_n = mid_a;
				/* ---------------------------------------- */
				push_to_b(d);
				cnt_push_b++;
				/* ---------------------------------------- */
				if (cnt_push_b == chunk_b_size)
					break;
				/* ---------------------------------------- */
				if (has_1_elem_or_more(&d->b.head) && (d->b.head->index > mid_b))
				{
					cnt_rot++;
					if ((has_2_elem_or_more(&d->b.head)) && (d->b.head->next->index <= mid_b))
						rotate_b(d);
				}
				/* ---------------------------------------- */
			}
			else
				rotate_a(d);
			/* ------------------------------------------------------ */

		}
		rev_rot_b_loop(d, cnt_rot);
		midsort_to_b_rec(d, mid_a + 1, end);
	}
}

