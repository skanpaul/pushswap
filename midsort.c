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
static int get_chunk_size(t_stk *stk);

/* ************************************************************************** */
void midsort(t_data *d)
{
	midsort_to_b(d);
	midsort_to_a(d);
}
/* ************************************************************************** */
void midsort_to_a(t_data *d)
{
	int chk_size;

	chk_size = get_chunk_size(&d->b);

	if(chk_size < 3)
		sort_3(d, chk_size);

	
	
	// check chunk size
	// size 1: just push_to_a
	// size 2; swap and push_to_a
	// size 3: sorting
	// size 5: sorting
	// size > 5; midsort_to_b
}

/* ************************************************************************** */
static int get_chunk_size(t_stk *stk)
{
	int		size;
	int		chk_n;
	t_ps	*temp;

	if (!stk || !stk->head)
		return (0);

	temp = stk->head;
	chk_n = temp->chk_n;

	size = 0;
	while ((temp != NULL) && (temp->chk_n == chk_n))
	{
		size++;
		temp = temp->next;
	}
	return (size);
}