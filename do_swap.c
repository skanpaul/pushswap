/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* ************************************************************************** */
// void do_swap(t_data *d)
// {
//     t_ps **head_a;
//     t_ps **tail_a;
//     t_ps **head_b;
//     t_ps **tail_b;

//     head_a = &d->stack_a;
//     tail_a = &d->stack_a_tail;
//     head_b = &d->stack_b;
//     tail_b = &d->stack_b_tail;

// // cas_3: si head A > next A | alors swap(A)
// // cas_4: si head B < next b | alors swap(B)
// // si cas_3 et cas_4 | alors swap(2) 
//     while (((*head_a)->val > (*tail_a)->val) 
//         || ((*head_b)->val < (*tail_b)->val))
//     {
//         if (((*head_a)->val > (*tail_a)->val) 
//             && ((*head_b)->val < (*tail_b)->val))
//             rotate_2(d);
//         if ((*head_a)->val > (*tail_a)->val)
//             rotate_a(d);
//         if ((*head_b)->val < (*tail_b)->val)
//             rotate_b(d);
//     }
// }