/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void swap(t_ps **ptr_top)
{
    t_ps *elem_1;    
    t_ps *elem_2;
    t_ps *elem_3;

    if ((ptr_top == NULL) 
        || (*ptr_top == NULL) 
        || ((*ptr_top)->next == NULL))
        return ;

    elem_1 = *ptr_top;
    elem_2 = elem_1->next;
    elem_3 = elem_2->next;

    *ptr_top = elem_2;
    elem_2->next = elem_1;
    elem_1->next = elem_3;
    return ;
}

/* ************************************************************************** */
void	swap_a(t_data *d)
{
    swap(&d->stack_a);
    return ;
}

/* ************************************************************************** */
void	swap_b(t_data *d)
{
    swap(&d->stack_b);
    return ;
}

/* ************************************************************************** */
void	swap_2(t_data *d)
{
    swap(&d->stack_a);
    swap(&d->stack_b);
    return ;
}