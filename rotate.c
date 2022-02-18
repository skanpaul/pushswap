/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void rotate(t_ps **ptr_top)
{
	t_ps *elem;   
    t_ps *bottom_elem;
	
	if ((ptr_top == NULL) || (*ptr_top == NULL) || ((*ptr_top)->next == NULL))
        return ;

	elem = *ptr_top;
	*ptr_top = elem->next;

	bottom_elem = ps_get_last_elem(ptr_top);

	bottom_elem->next = elem;
	elem->next = NULL;

	return ; 
}

/* ************************************************************************** */
void	rotate_a(t_data *d)
{
	rotate(&d->stack_a);
	return ;
}
/* ************************************************************************** */
void	rotate_b(t_data *d)
{
	rotate(&d->stack_b);
	return ;
}
/* ************************************************************************** */
void	rotate_2(t_data *d)
{
	rotate(&d->stack_a);
	rotate(&d->stack_b);
	return ;
}