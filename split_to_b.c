/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:09:44 by ski               #+#    #+#             */
/*   Updated: 2022/03/08 15:09:46 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static void split_to_b_rec(t_data *d, int start, int end);
/* ************************************************************************** */
void split_to_b(t_data *d)
{
	int chk_a_size;

	chk_a_size = get_chunk_size(&d->a);

	split_to_b_rec(d, 0, chk_a_size - 1);
}
/* ************************************************************************** */
static void split_to_b_rec(t_data *d, int start, int end)
{
	int mid_2;
	int mid_4;
	int chunk_b_size;
	int cnt_push_b;
	int cnt_rot;

	cnt_rot = 0;
	cnt_push_b = 0;

	mid_2 = (end - start)/2 + start;
	mid_4 = (mid_2 - start)/2 + start;

	chunk_b_size = mid_2 - start + 1;

	if (d->a.size <= MAX_SIZE_OF_UNSORTED_CHUNK_A)
		return ;
	else
	{
		while (cnt_push_b < chunk_b_size)
		{
			/* ------------------------------------------------------ */
			if (d->a.head->index <= mid_2)
			{
				/* ---------------------------------------- */
				if (d->a.head->index <= mid_4)
					d->a.head->chk_id = mid_4;
				else
					d->a.head->chk_id = mid_2;
				/* ---------------------------------------- */
				push_to_b(d);
				cnt_push_b++;
				/* ---------------------------------------- */
				if (cnt_push_b == chunk_b_size)
					break;
				/* ---------------------------------------- */
				if (has_1_elem_or_more(&d->b.head) && (d->b.head->index > mid_4))
				{
					cnt_rot++;
					if ((has_2_elem_or_more(&d->b.head)) && (d->b.head->next->index <= mid_4))
						rotate_b(d);
				}
				/* ---------------------------------------- */
			}
			else
				rotate_a(d);
			/* ------------------------------------------------------ */

		}
		rev_rot_b_loop(d, cnt_rot);
		split_to_b_rec(d, mid_2 + 1, end);
	}
}

/* ************************************************************************** */
// void split_to_b(t_data *d, int chk_a_id)
// {
	
// 	split_to_b_rec(d, 0, d->a.size - 1);
// }
// /* ************************************************************************** */
// static void split_to_b_rec(t_data *d, int start, int end)
// {
// 	int mid_2;
// 	int mid_4;
// 	int chunk_b_size;
// 	int cnt_push_b;
// 	int cnt_rot;

// 	cnt_rot = 0;
// 	cnt_push_b = 0;

// 	mid_2 = (end - start)/2 + start;
// 	mid_4 = (mid_2 - start)/2 + start;

// 	chunk_b_size = mid_2 - start + 1;

// 	// if (d->a.size <= 2)
// 	if (d->a.size == 0)
// 		return ;
// 	else
// 	{
// 		while (cnt_push_b < chunk_b_size)
// 		{
// 			/* ------------------------------------------------------ */
// 			if (d->a.head->index <= mid_2)
// 			{
// 				/* ---------------------------------------- */
// 				if (d->a.head->index <= mid_4)
// 					d->a.head->chk_id = mid_4;
// 				else
// 					d->a.head->chk_id = mid_2;
// 				/* ---------------------------------------- */
// 				push_to_b(d);
// 				cnt_push_b++;
// 				/* ---------------------------------------- */
// 				if (cnt_push_b == chunk_b_size)
// 					break;
// 				/* ---------------------------------------- */
// 				if (has_1_elem_or_more(&d->b.head) && (d->b.head->index > mid_4))
// 				{
// 					cnt_rot++;
// 					if ((has_2_elem_or_more(&d->b.head)) && (d->b.head->next->index <= mid_4))
// 						rotate_b(d);
// 				}
// 				/* ---------------------------------------- */
// 			}
// 			else
// 				rotate_a(d);
// 			/* ------------------------------------------------------ */

// 		}
// 		rev_rot_b_loop(d, cnt_rot);
// 		split_to_b_rec(d, mid_2 + 1, end);
// 	}
// }