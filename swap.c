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
    t_ps *top_elem;    
    t_ps *sec_elem;
    t_ps *trd_elem;

    if ((ptr_top == NULL) 
        || (*ptr_top == NULL) 
        || ((*ptr_top)->next == NULL))
        return ;

    top_elem = *ptr_top;
    sec_elem = top_elem->next;
    trd_elem = sec_elem->next;

    *ptr_top = sec_elem;
    sec_elem->prev = NULL;
    sec_elem->next = top_elem;
    
    top_elem->prev = sec_elem;
    top_elem->next = trd_elem;
    return ;
}

/* ************************************************************************** */
void	swap_a(t_data *d)
{
    swap(&d->stack_a);
    printf("SA\n");
    return ;
}

/* ************************************************************************** */
void	swap_b(t_data *d)
{
    swap(&d->stack_b);
    printf("SB\n");
    return ;
}

/* ************************************************************************** */
void	swap_2(t_data *d)
{
    swap(&d->stack_a);
    swap(&d->stack_b);
    printf("SS\n");
    return ;
}

/* ************************************************************************** */
/* sa : swap a - swap the first 2 elements at the top of stack a.             */
/* Do nothing if there is only one or no elements).                           */
/* ************************************************************************** */
/* sb : swap b - swap the first 2 elements at the top of stack b.             */
/* Do nothing if there is only one or no elements).                           */
/* ************************************************************************** */
/* ss : sa and sb at the same time.                                           */
/* ************************************************************************** */