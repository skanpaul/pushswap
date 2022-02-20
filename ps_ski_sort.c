/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ski_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void ps_ski_sort(t_data *d)
{
    bool f_in_order; // 0: NOT in order - 1: IN-ORDER
    t_ps *top_a;
    t_ps *bottom_a;
    t_ps *top_b;
    t_ps *bottom_b;

    /* --------------------------------------------------------- */
    f_in_order = false;
    top_a = NULL;
    top_b = NULL;
    bottom_a = NULL;
    bottom_b = NULL;
    /* --------------------------------------------------------- */    
    if ((has_less_than_2_elem(d->stack_a)) || (is_in_order(d->stack_a)))
        return ;
    /* --------------------------------------------------------- */
    top_a = d->stack_a;
    top_b = d->stack_b;
    bottom_a = ps_get_last_elem(&d->stack_a);
    bottom_b = ps_get_last_elem(&d->stack_b);
    


    while (f_in_order == false)
    {
        while (top_a->val = bottom_a->val)
            rotate_a(d);

        if ()
            swap_a(d);



    }




    rotate_b(d);
    rotate_2(d);

    swap_b(d);
    swap_2(d);

    rev_rot_a(d);
    rev_rot_b(d);
    rev_rot_2(d);

    push_to_a(d);
    push_to_b(d);



}
