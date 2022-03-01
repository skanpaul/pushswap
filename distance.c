/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
int distance_to_top_upwards(t_ps *elem)
{
	int distance;

	if (!elem)
		return (0);

	distance = 0;
	while (elem->prev != NULL)
	{
		elem = elem->prev;
		distance++;
	}

	return (distance);
}

/* ************************************************************************** */
int distance_to_top_downwards(t_ps *elem)
{
	int distance;

	if (!elem)
		return (0);

	distance = 0;
	while (elem->next != NULL)
	{
		elem = elem->next;
		distance++;
	}
	distance++;

	return (distance);
}
