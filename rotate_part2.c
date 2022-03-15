/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	rotate_a_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rotate_a(d);
		loop--;
	}
}

/* ************************************************************************** */
void	rotate_b_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rotate_b(d);
		loop--;
	}
}

/* ************************************************************************** */
void	rotate_2_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rotate_2(d);
		loop--;
	}
}

/* ************************************************************************** */
/* ra : rotate a - shift up all elements of stack a by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rb : rotate b - shift up all elements of stack b by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rr : ra and rb at the same time.                                           */
/* ************************************************************************** */