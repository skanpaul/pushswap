/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_element_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool	has_1_elem_or_more(t_ps **head)
{
	t_ps	*top_elem;

	if (head == NULL)
		return (false);
	top_elem = *head;
	if (top_elem == NULL)
		return (false);
	return (true);
}

/* ************************************************************************** */
bool	has_2_elem_or_more(t_ps **head)
{
	t_ps	*top_elem;

	if (head == NULL)
		return (false);
	top_elem = *head;
	if (top_elem == NULL)
		return (false);
	if (top_elem->next == NULL)
		return (false);
	return (true);
}

/* ************************************************************************** */
bool	has_less_than_2_elem(t_ps **head)
{
	t_ps	*elem_1;
	t_ps	*elem_2;

	if (!head)
		return (true);
	elem_1 = *head;
	if (elem_1 == NULL)
		return (true);
	elem_2 = elem_1->next;
	if (elem_2 == NULL)
		return (true);
	return (false);
}

/* ************************************************************************** */