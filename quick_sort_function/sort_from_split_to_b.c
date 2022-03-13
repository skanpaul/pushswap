/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_from_split_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:36:42 by ski               #+#    #+#             */
/*   Updated: 2022/03/13 15:36:44 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
// #include "push_swap.h"

/* ************************************************************************** */
void sort_from_split_to_b(t_data *d)
{
	int group_b_id; 

	group_b_id = split_to_b(d);

	sort_small_chunk_a(d);

	sort_chunk_b_group(d, group_b_id);


}

/* ************************************************************************** */