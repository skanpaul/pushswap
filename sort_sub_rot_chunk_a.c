/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sub_rot_chunk_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:08:03 by ski               #+#    #+#             */
/*   Updated: 2022/03/13 16:09:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	sort_sub_rot_chunk_a(t_data *d, int cnt_rot_a)
{
	rev_rot_a_loop(d, cnt_rot_a);
	sort_chunk_a(d);
}

/* ************************************************************************** */