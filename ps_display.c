/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	ps_display(t_ps *top_elem)
{
	t_ps	*ptr;

	ptr = top_elem;
	if (!ptr)
		return ;

	while (ptr->next != NULL)
	{
		// ft_printf("[%d]\n", ptr->val);
		printf("[%d]\n", ptr->val);
		ptr = ptr->next;
	}
	// ft_printf("[%d]\n", ptr->val);
	printf("[%d]\n", ptr->val);
	return ;
}
