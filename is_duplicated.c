/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_duplicated (t_ps **stack, int val)
{
    t_ps *elem;

    if ((!stack) || (!(*stack)))
        return (false);

    elem = *stack;
    while (1)
    {
        if (elem->val == val)
            return (true);
        if (elem->next == NULL)
            break ;
        elem = elem->next;
    }    
    return (false);
}
