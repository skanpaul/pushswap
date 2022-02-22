/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	push_to(t_stk *src, t_stk *dst)
{
    t_ps *elem_extracted;

    elem_extracted = ps_rem_elem_from_top(src->head, src->tail);
    
    ps_add_elem_to_top(elem_extracted, dst->head, dst->tail);
    
    return ;
}

/* ************************************************************************** */
/* pa : push a                                                                */
/* - take the first element at the top of b and put it at the top of a.       */
/* - Do nothing if b is empty.                                                */
/* ************************************************************************** */
void	push_to_a(t_data *d)
{
    t_stk a;
    t_stk b;

    a.head = &(d->head_a);
    a.tail = &(d->tail_a);
    b.head = &(d->head_b);
    b.tail = &(d->tail_b);
    
    push_to(&b, &a);
	printf("pa\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
/* pb : push b                                                                */
/* - take the first element at the top of a and put it at the top of b.       */
/* - Do nothing if a is empty.                                                */
/* ************************************************************************** */
void	push_to_b(t_data *d)
{
    t_stk a;
    t_stk b;

    a.head = &(d->head_a);
    a.tail = &(d->tail_a);
    b.head = &(d->head_b);
    b.tail = &(d->tail_b);
    
    push_to(&a, &b);
	printf("pb\n");
	d->cnt_cmd++;
	display(d);
    return ;
}






// /* ************************************************************************** */
// void	push_to(t_ps **stack_src, t_ps **stack_dst)
// {
// 	t_ps *top_elem_src;
// 	t_ps *top_elem_dst;
    
//     t_ps *sec_elem_src;

//     top_elem_src = *stack_src;
//     top_elem_dst = *stack_dst;

//     if (!top_elem_src)
//         return ;

//     // soustrait top_elem_a de head_a
//     sec_elem_src = top_elem_src->next;
//     *stack_src = sec_elem_src;
//     if(sec_elem_src != NULL)
//         sec_elem_src->prev = NULL;
//     // mettre top_elem_a au dessus de top_elem_b
//     *stack_dst = top_elem_src;
//     top_elem_src->prev = NULL;
//     top_elem_src->next = top_elem_dst;

//     if (top_elem_dst != NULL)
//         top_elem_dst->prev = top_elem_src;
//     return ;
// }
// /* ************************************************************************** */
// /* pa : push a                                                                */
// /* - take the first element at the top of b and put it at the top of a.       */
// /* - Do nothing if b is empty.                                                */
// /* ************************************************************************** */
// void	push_to_a(t_data *d)
// {
//     push_to(&d->head_b, &d->head_a);
// 	printf("PA\n");
//     return ;
// }

// /* ************************************************************************** */
// /* pb : push b                                                                */
// /* - take the first element at the top of a and put it at the top of b.       */
// /* - Do nothing if a is empty.                                                */
// /* ************************************************************************** */
// void	push_to_b(t_data *d)
// {
//     push_to(&d->head_a, &d->head_b);
// 	printf("PB\n");
//     return ;
// }