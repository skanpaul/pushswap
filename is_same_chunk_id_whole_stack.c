/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_chunk_id_whole_stack.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:39:48 by ski               #+#    #+#             */
/*   Updated: 2022/03/10 18:39:50 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_same_chunk_id_whole_stack(t_stk *stk)
{
	t_ps *temp;
	int chunk_id;
	int i;

	if(!has_2_elem_or_more(&stk->head))
		return (false);

	temp = stk->head;
	chunk_id = temp->chk_id;

	i = 0;
	while (i < stk->size)
	{
		if (temp->chk_id != chunk_id)
			return (false); 
		
		temp = temp->next;
		i++;
	}

	return (true);
}

