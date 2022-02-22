/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
// cas_1: boucle tant que head A > fond A | alors rot(A)
// cas_2: boucle tant que head B < fond B | alors rot(B)
// si cas_1 et cas_2 | alors rot(2) 
/* ************************************************************************** */
// void do_rotation(t_data *d)
// {
//     t_ps **head_a;
//     t_ps **tail_a;
//     t_ps **head_b;
//     t_ps **tail_b;

//     head_a = &d->stack_a;
//     tail_a = &d->stack_a_tail;
//     head_b = &d->stack_b;
//     tail_b = &d->stack_b_tail;
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
/* ************************************************************************** */

    // while ((d->stack_a->val > d->stack_a_tail->val) 
    //     || (d->stack_b->val < d->stack_b_tail->val))
    // {
    //     if ((d->stack_a->val > d->stack_a_tail->val) 
    //         && (d->stack_b->val < d->stack_b_tail->val))
    //         rotate_2(d);

    //     if (d->stack_a->val > d->stack_a_tail->val)
    //         rotate_a(d);

    //     if (d->stack_b.b < d->stack_b_tail->val)
    //         rotate_b(d);
    // }
