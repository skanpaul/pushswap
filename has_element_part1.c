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
bool	has_0_elem_only(t_ps **head)
{
	t_ps	*elem_1;

	if (head == NULL)
		return (true);
	elem_1 = *head;
	if (elem_1 == NULL)
		return (true);
	return (false);
}

/* ************************************************************************** */
bool	has_1_elem_only(t_ps **head)
{
	t_ps	*elem_1;

	if (head == NULL)
		return (false);
	elem_1 = *head;
	if ((elem_1 != NULL) && (elem_1->next == NULL))
		return (true);
	return (false);
}

/* ************************************************************************** */
bool	has_2_elem_only(t_ps **head)
{
	t_ps	*elem_1;
	t_ps	*elem_2;

	if (head == NULL)
		return (false);
	if (has_1_elem_only(head))
		return (false);
	elem_1 = *head;
	elem_2 = elem_1->next;
	if ((elem_2 != NULL) && (elem_2->next == NULL))
		return (true);
	return (false);
}

/* ************************************************************************** */