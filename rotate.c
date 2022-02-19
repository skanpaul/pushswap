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
/* PULL the stack from the bottom to the top ******************************** */
/* ************************************************************************** */
void rotate(t_ps **ptr_top)
{
	t_ps *top_elem;
	t_ps *sec_elem;
    t_ps *bot_elem;
	
	if ((ptr_top == NULL) || (*ptr_top == NULL) || ((*ptr_top)->next == NULL))
        return ;

	top_elem = *ptr_top;
	sec_elem = top_elem->next;
	bot_elem = ps_get_last_elem(ptr_top);

	*ptr_top = sec_elem;
	sec_elem->prev = NULL;

	bot_elem->next = top_elem;
	top_elem->prev = bot_elem;
	top_elem->next = NULL;

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

/* ************************************************************************** */
/* ra : rotate a - shift up all elements of stack a by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rb : rotate b - shift up all elements of stack b by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rr : ra and rb at the same time.                                           */
/* ************************************************************************** */