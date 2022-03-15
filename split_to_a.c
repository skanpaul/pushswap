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
#include "push_swap.h"

/* ************************************************************************** */
static t_sta	split_to_a_rec(t_data *d, int start, int end);
static void		push_to_a_rotate_a(t_data *d, t_sta *sta_d, int end);
static void		init_sta_rec(t_data *d, t_sta *sta_d, int start, int end);

/* ************************************************************************** */
t_sta	split_to_a(t_data *d)
{
	t_sta	sta_d;
	int		start;
	int		end;

	end = d->b.head->chk_id;
	start = end - get_chunk_size(&d->b) + 1;
	sta_d = split_to_a_rec(d, start, end);
	return (sta_d);
}

/* ************************************************************************** */
static t_sta	split_to_a_rec(t_data *d, int start, int end)
{
	t_sta	sta_d;

	init_sta_rec(d, &sta_d, start, end);
	while (sta_d.i < sta_d.chunk_b_size)
	{
		if (d->b.head->index >= sta_d.mid_2)
			push_to_a_rotate_a(d, &sta_d, end);
		else
		{
			d->b.head->chk_id = sta_d.mid_2 - 1;
			rotate_b(d);
			sta_d.cnt_rot_b++;
		}
		sta_d.i++;
	}
	rev_rot_b_loop(d, sta_d.cnt_rot_b);
	sta_d.cnt_rev_rot = sta_d.cnt_rot_a;
	sta_d.sub_group_b_id = sta_d.mid_2 - 1;
	return (sta_d);
}

/* ************************************************************************** */
static void	push_to_a_rotate_a(t_data *d, t_sta *sta_d, int end)
{
	if (sta_d->mid_4 == sta_d->mid_2)
		d->b.head->chk_id = end;
	else if (d->b.head->index >= sta_d->mid_4)
		d->b.head->chk_id = end;
	else if (d->b.head->index < sta_d->mid_4)
		d->b.head->chk_id = sta_d->mid_4 - 1;
	push_to_a(d);
	sta_d->cnt_push_a++;
	if (has_1_elem_or_more(&d->a.head) && (d->a.head->index < sta_d->mid_4))
	{
		sta_d->cnt_rot_a++;
		rotate_a(d);
	}
}

/* ************************************************************************** */
static void	init_sta_rec(t_data *d, t_sta *sta_d, int start, int end)
{
	sta_d->cnt_rot_a = 0;
	sta_d->cnt_rot_b = 0;
	sta_d->cnt_push_a = 0;
	sta_d->mid_2 = end - (end - start) / 2;
	sta_d->mid_4 = end - (sta_d->mid_2 - start) / 2;
	sta_d->chunk_b_size = get_chunk_size(&d->b);
	sta_d->i = 0;
}

/* ************************************************************************** */