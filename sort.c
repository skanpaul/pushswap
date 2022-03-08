/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:34:13 by ski               #+#    #+#             */
/*   Updated: 2022/03/08 15:34:18 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static bool is_chunk_b_in_order(t_data *d, int chk_size);
/* ************************************************************************** */
void sort_3_elem(t_data *d, int chk_size)
{
	if (is_chunk_b_in_order(d, chk_size))
	{
		push_to_a_loop(d, chk_size);
		return ;
	}

	if (chk_size == 1)
		sort_1_to_a(d, chk_size);
	else if (chk_size == 2)
		sort_2_to_a(d, chk_size);
	else if (chk_size == 3)
		sort_3_to_a(d, chk_size);

}

/* ************************************************************************** */
void sort_1_to_a(t_data *d, int chk_size)
{
	push_to_a_loop(d, chk_size);
}

/* ************************************************************************** */
void sort_2_to_a(t_data *d, int chk_size)
{
	if (d->b.head->next->index > d->b.head->index)
		swap_b(d);
	
	push_to_b_loop(d, chk_size);
}

/* ************************************************************************** */
void sort_3_to_a(t_data *d, int chk_size)
{

}



/* ************************************************************************** */
static bool is_chunk_b_in_order(t_data *d, int chk_size)
{
	int i;
	t_ps *temp;

	temp = d->b.head;

	if (!has_2_elem_or_more(&temp))
		return (false);

	i = 0;
	while (i < chk_size - 1)
	{
		if (temp->index < temp->next->index)
			return (false);
		i++;
	}
	return (true);
}

