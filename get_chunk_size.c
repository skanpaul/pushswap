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

// /* ************************************************************************** */
// int get_chunk_size(t_stk *stk, int chk_id)
// {
// 	int		size;
// 	int		chk_id;
// 	t_ps	*temp;

// 	if (!stk || !stk->head)
// 		return (0);

// 	temp = stk->head;

// 	size = 0;
// 	while ((temp != NULL) && (temp->chk_id == chk_id))
// 	{
// 		size++;
// 		temp = temp->next;
// 	}
// 	return (size);
// }

/* ************************************************************************** */
int get_chunk_size(t_stk *stk)
{
	int		size;
	int		chk_id;
	t_ps	*temp;

	if (!stk || !stk->head)
		return (0);

	temp = stk->head;
	chk_id = temp->chk_id;

	size = 0;
	while ((temp != NULL) && (temp->chk_id == chk_id))
	{
		size++;
		temp = temp->next;
	}
	return (size);
}