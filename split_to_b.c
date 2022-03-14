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
// #include "../push_swap.h"
#include "push_swap.h"

/* ************************************************************************** */
static int split_to_b_rec(t_data *d, int start, int end);
static void optimize_rev_rot(t_data *d, int cnt_rot_a, int cnt_rot_b);
// static void optimize_rot(t_data *d, int *buf_rot_a, int *buf_rot_b);

/* ************************************************************************** */
// RETURN: group_b_id (from the lowest chunk_b of the chunk_b_group)
/* ************************************************************************** */
int split_to_b(t_data *d)
{
	int chunk_b_group_id;
	int start;
	int end;


	end = d->a.head->chk_id;
	start = end - get_chunk_size(&d->a) + 1;
	chunk_b_group_id = split_to_b_rec(d, start, end);

	return (chunk_b_group_id);

}

/* ************************************************************************** */
static int split_to_b_rec(t_data *d, int start, int end)
{
	int mid_2;
	int mid_4;
	int chunk_a_size;
	int chunk_b_size;
	int cnt_push_b;
	int cnt_rot_a;
	int cnt_rot_b;

	cnt_rot_a = 0;
	cnt_rot_b = 0;
	cnt_push_b = 0;

	mid_2 = (end - start)/2 + start;
	mid_4 = (mid_2 - start)/2 + start;

	chunk_b_size = mid_2 - start + 1;
	chunk_a_size = get_chunk_size(&d->a);

	if (chunk_a_size <= MAX_SIZE_OF_UNSORTED_CHUNK)
		return (mid_4);
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
					cnt_rot_b++;
					if ((has_2_elem_or_more(&d->b.head)) && (d->b.head->next->index <= mid_4))
						rotate_b(d);
				}
				/* ---------------------------------------- */
			}
			else
			{
				rotate_a(d);
				cnt_rot_a++;
			}
			/* ------------------------------------------------------ */

		}

		if (is_same_chunk_id_whole_stack(&d->a))
			cnt_rot_a = 0;
		optimize_rev_rot(d, cnt_rot_a, cnt_rot_b);
		/* ------------------------------------------------------ */
		split_to_b_rec(d, mid_2 + 1, end);
	}
	return (mid_4);
}

/* ************************************************************************** */
static void optimize_rev_rot(t_data *d, int cnt_rot_a, int cnt_rot_b)
{
	int min_rev_rot_2;
	int diff;

	if (cnt_rot_a <= cnt_rot_b)
	{
		min_rev_rot_2 = cnt_rot_a;
		rev_rot_2_loop(d, min_rev_rot_2);

		diff = cnt_rot_b - cnt_rot_a;
		rev_rot_b_loop(d, diff);
	}
	else
	{
		min_rev_rot_2 = cnt_rot_b;
		rev_rot_2_loop(d, min_rev_rot_2);

		diff = cnt_rot_a - cnt_rot_b;
		rev_rot_a_loop(d, diff);
	}
}

/* ************************************************************************** */
// static void optimize_rot(t_data *d, int *buf_rot_a, int *buf_rot_b)
// {
// 	int min_rot_2;
// 	int diff;
		
// 	if (*buf_rot_a <= *buf_rot_b)
// 	{
// 		min_rot_2 = *buf_rot_a;
// 		rotate_2_loop(d, min_rot_2);

// 		diff = *buf_rot_b - *buf_rot_a;
// 		rotate_b_loop(d, diff);
// 	}
// 	else
// 	{
// 		min_rot_2 = *buf_rot_b;
// 		rotate_2_loop(d, min_rot_2);

// 		diff = *buf_rot_a - *buf_rot_b;
// 		rotate_a_loop(d, diff);
// 	}

// 	*buf_rot_a = 0;
// 	*buf_rot_b = 0;
// 	/* ------------------------------------------------------ */

// }