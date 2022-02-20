/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_display_2_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	ps_display_2_list(t_data *d)
{
    int height;
    int height_a;
    int height_b;
    int i;
    t_ps *ptr_a;
    t_ps *ptr_b;

    height_a = ps_size(d->stack_a);
    height_b = ps_size(d->stack_b);

    ptr_a = d->stack_a;
    ptr_b = d->stack_b;

    if (height_a >= height_b)
        height = height_a;
    else
        height = height_b;

    i = height;
    while (i > 0)
    {
        if ((height_a >= i) && (height_b >= i))
        {
            printf("\t[%d]\t[%d]\n", ptr_a->val, ptr_b->val);
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }

        if ((height_a >= i) && (height_b < i))
        {
            printf("\t[%d]\t   \n", ptr_a->val);
            ptr_a = ptr_a->next;
        }

        if ((height_a < i) && (height_b >= i))
        {
            printf("\t   \t[%d]\n", ptr_b->val);
            ptr_b = ptr_b->next;
        }
        i--;
    }

    return ;
}
