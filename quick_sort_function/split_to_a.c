/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:49 by ski               #+#    #+#             */
/*   Updated: 2022/03/07 15:49:51 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
// #include "push_swap.h"

/* ************************************************************************** */
static t_sta split_to_a_rec(t_data *d, int start, int end);

/* ************************************************************************** */
t_sta split_to_a(t_data *d)
{
	t_sta sta_data;
	int start;
	int end;

	end = d->b.head->chk_id;
	start = end - get_chunk_size(&d->b) + 1;
	
	sta_data = split_to_a_rec(d, start, end);

	return (sta_data);
}

/* ************************************************************************** */
static t_sta split_to_a_rec(t_data *d, int start, int end)
{
	t_sta sta_data;
	
	int mid_2;
	int mid_4;
	// int chunk_a_size;
	int chunk_b_size;
	int cnt_push_a;
	int cnt_rot_a;
	int cnt_rot_b;
	int i;

	cnt_rot_a = 0;
	cnt_rot_b = 0;
	cnt_push_a = 0;

	mid_2 = end - (end - start)/2;
	mid_4 = end - (mid_2 - start)/2;

	// chunk_a_size = end - mid_2 + 1;

	// while (cnt_push_a < chunk_a_size)
	chunk_b_size = get_chunk_size(&d->b);
	i = 0;
	while (i < chunk_b_size)
	{
		/* ------------------------------------------------------ */
		if (d->b.head->index >= mid_2)
		{
			/* ---------------------------------------- */
			if (mid_4 == mid_2)
				d->b.head->chk_id = end;
			else if (d->b.head->index >= mid_4)
				d->b.head->chk_id = end;
			else if (d->b.head->index < mid_4)
				d->b.head->chk_id = mid_4 - 1;
			/* ---------------------------------------- */
			push_to_a(d);
			cnt_push_a++;
			/* ---------------------------------------- */
			if (has_1_elem_or_more(&d->a.head) && (d->a.head->index < mid_4))
			{
				cnt_rot_a++;
				// if ((has_2_elem_or_more(&d->a.head)) && (d->a.head->next->index <= mid_4))
				rotate_a(d);
			}
			/* ---------------------------------------- */
		}
		else
		{
			d->b.head->chk_id = mid_2 - 1;
			rotate_b(d);
			cnt_rot_b++;
		}
		/* ------------------------------------------------------ */
		i++;
	}
	rev_rot_b_loop(d, cnt_rot_b);
	sta_data.cnt_rev_rot = cnt_rot_a;
	sta_data.sub_group_b_id = 56;

	return (sta_data);

}
/* ************************************************************************** */
