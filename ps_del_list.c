/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:31:04 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:31:06 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	ps_del_list(t_ps **stack)
{
	t_ps	*top_elem;
	t_ps	*elem;

	top_elem = *stack;	
	elem = NULL;

	if (top_elem == NULL)
		return ;
	while (top_elem->next != NULL)
	{
		elem = top_elem->next;
		// ps_del_elem(top_elem);
		free(top_elem);
		top_elem = elem;
	}
	// ps_del_elem(top_elem);
	free(top_elem);
	*stack = NULL;
	// top_elem = NULL;
	return ;
}
/* ************************************************************************** */
// void	ps_del_list(t_ps *top_elem)
// {
// 	t_ps	*ptr;

// 	ptr = NULL;
// 	if (top_elem == NULL)
// 		return ;
// 	while (top_elem->next != NULL)
// 	{
// 		ptr = top_elem->next;
// 		// ps_del_elem(top_elem);
// 		free(top_elem);
// 		top_elem = ptr;
// 	}
// 	// ps_del_elem(top_elem);
// 	free(top_elem);
// 	top_elem = NULL;
// 	return ;
// }
