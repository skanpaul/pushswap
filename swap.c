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
void swap(t_ps **stack, t_ps **stack_tail)
{
    t_ps *elem_1;    
    t_ps *elem_2;
    t_ps *elem_3;

    if ((!stack) || (!stack_tail) || (has_less_than_2_elem(stack)))
        return;
   
    elem_1 = *stack;
    elem_2 = elem_1->next;
    elem_3 = elem_2->next;

    *stack = elem_2;
    elem_2->prev = NULL;
    elem_2->next = elem_1;
    
    elem_1->prev = elem_2;
    elem_1->next = elem_3;

    if (has_2_elem_only(stack))
        *stack_tail = elem_1;  

    return ;
}

/* ************************************************************************** */
void	swap_a(t_data *d)
{
    swap(&d->head_a, &d->tail_a);
    printf("SA\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
void	swap_b(t_data *d)
{
    swap(&d->head_b, &d->tail_b);
    printf("SB\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
void	swap_2(t_data *d)
{
    swap(&d->head_a, &d->tail_a);
    swap(&d->head_b, &d->tail_b);
    printf("SS\n");
	d->cnt_cmd++;
	display(d);
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

