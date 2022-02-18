/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* PUSH the stack from the top to the bottom ******************************** */
/* ************************************************************************** */
void rev_rot(t_ps **ptr_top)
{
	t_ps *top_elem;
    t_ps *before_last_elem;   
    t_ps *bot_elem;
	
	if ((ptr_top == NULL) || (*ptr_top == NULL) || ((*ptr_top)->next == NULL))
        return ;

    top_elem = *ptr_top;
    bot_elem = ps_get_last_elem(ptr_top);
    before_last_elem = bot_elem->prev;

    *ptr_top = bot_elem;
    bot_elem->prev = NULL;
    bot_elem->next = top_elem;

    top_elem->prev = bot_elem;
    before_last_elem->next = NULL;

	return ; 
}

/* ************************************************************************** */
void	rev_rot_a(t_data *d)
{
    rev_rot(&d->stack_a);
    return ;
}
/* ************************************************************************** */
void	rev_rot_b(t_data *d)
{
    rev_rot(&d->stack_b);
    return ;
}
/* ************************************************************************** */
void	rev_rot_2(t_data *d)
{
    rev_rot(&d->stack_a);
    rev_rot(&d->stack_b);
    return ;
}