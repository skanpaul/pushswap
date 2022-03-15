/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	display_1_list(t_ps *top_elem)
{
	t_ps	*ptr;

	ptr = top_elem;
	if (!ptr)
		return ;
	while (ptr->next != NULL)
	{
		ft_printf("[%d]\n", ptr->val);
		ptr = ptr->next;
	}
	ft_printf("[%d]\n", ptr->val);
	return ;
}

/* ************************************************************************** */
void	display_size(t_data *d)
{
	ft_printf("Size\ta:[%d]\t\t\tb:[%d]\n", d->a.size, d->b.size);
}

/* ************************************************************************** */
void	display_stack_address(t_data *d)
{
	if ((*d).a.head == NULL)
		ft_printf("HEAD_a\t[%p]\t\t\tHEAD_b\t[%p]\n", (*d).a.head, (*d).b.head);
	else
		ft_printf("HEAD_a\t[%p]\tHEAD_b\t[%p]\n", (*d).a.head, (*d).b.head);
	if ((*d).a.tail == NULL)
		ft_printf("BOT_a\t[%p]\t\t\tBOT_b\t[%p]\n", (*d).a.tail, (*d).b.tail);
	else
		ft_printf("BOT_a\t[%p]\tBOT_b\t[%p]\n", (*d).a.tail, (*d).b.tail);
}
