/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:09:44 by ski               #+#    #+#             */
/*   Updated: 2022/03/08 15:09:46 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static int	split_to_b_rec(t_data *d, int start, int end);
static void	optimize_rev_rot(t_data *d, int cnt_rot_a, int cnt_rot_b);
static int	push_to_b_rotate_b(t_data *d, t_stb *stb_d);
static void	init_split_to_b_rec(t_data *d, t_stb *stb_d, int start, int end);

/* ************************************************************************** */
// RETURN: group_b_id (from the lowest chunk_b of the chunk_b_group)
/* ************************************************************************** */
int	split_to_b(t_data *d)
{
	int	chunk_b_group_id;
	int	start;
	int	end;

	end = d->a.head->chk_id;
	start = end - get_chunk_size(&d->a) + 1;
	chunk_b_group_id = split_to_b_rec(d, start, end);
	return (chunk_b_group_id);
}

/* ************************************************************************** */
static int	split_to_b_rec(t_data *d, int start, int end)
{
	t_stb	stb_d;

	init_split_to_b_rec(d, &stb_d, start, end);
	if (stb_d.chunk_a_size <= MAX_SIZE_OF_UNSORTED_CHUNK)
		return (stb_d.mid_4);
	else
	{
		while (stb_d.cnt_push_b < stb_d.chunk_b_size)
		{
			if (d->a.head->index <= stb_d.mid_2)
			{
				if (push_to_b_rotate_b(d, &stb_d) == SHOULD_BREAK)
					break ;
			}
			else
			{
				rotate_a(d);
				stb_d.cnt_rot_a++;
			}
		}
		optimize_rev_rot(d, stb_d.cnt_rot_a, stb_d.cnt_rot_b);
		split_to_b_rec(d, stb_d.mid_2 + 1, end);
	}
	return (stb_d.mid_4);
}

/* ************************************************************************** */
static int	push_to_b_rotate_b(t_data *d, t_stb *stb_d)
{
	if (d->a.head->index <= stb_d->mid_4)
		d->a.head->chk_id = stb_d->mid_4;
	else
		d->a.head->chk_id = stb_d->mid_2;
	push_to_b(d);
	stb_d->cnt_push_b++;
	if (stb_d->cnt_push_b == stb_d->chunk_b_size)
		return (SHOULD_BREAK);
	if (has_1_elem_or_more(&d->b.head)
		&& (d->b.head->index > stb_d->mid_4))
	{
		stb_d->cnt_rot_b++;
		if ((has_2_elem_or_more(&d->b.head))
			&& (d->b.head->next->index <= stb_d->mid_4))
			rotate_b(d);
	}
	return (SHOULD_NOT_BREAK);
}

/* ************************************************************************** */
static void	init_split_to_b_rec(t_data *d, t_stb *stb_d, int start, int end)
{
	stb_d->cnt_rot_a = 0;
	stb_d->cnt_rot_b = 0;
	stb_d->cnt_push_b = 0;
	stb_d->mid_2 = (end - start) / 2 + start;
	stb_d->mid_4 = (stb_d->mid_2 - start) / 2 + start;
	stb_d->chunk_b_size = stb_d->mid_2 - start + 1;
	stb_d->chunk_a_size = get_chunk_size(&d->a);
}

/* ************************************************************************** */
static void	optimize_rev_rot(t_data *d, int cnt_rot_a, int cnt_rot_b)
{
	int	min_rev_rot_2;
	int	diff;

	if (is_same_chunk_id_whole_stack(&d->a))
		cnt_rot_a = 0;
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