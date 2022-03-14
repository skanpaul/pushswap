/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ready_push_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_ready_push_b(t_data *d)
{
    if (has_2_elem_or_more(&d->a.head))
    {
        // [A]: le plus GRAND disque devrait etre au FOND
        if (d->a.head->val > d->a.tail->val)
            return (false);
        // [A]: le plus PETIT disque devrait eter au SOMMET
        if (d->a.head->val > d->a.head->next->val)
            return (false);
    }

    if (has_2_elem_or_more(&d->b.head))
    {
        // [B]: le plus PETIT disque devrait etre au FOND
        if (d->b.head->val < d->b.tail->val)
            return (false);
        // [B]: le plus GRAND disque devrait etre au SOMMET
        if (d->b.head->val < d->b.head->next->val)
            return (false);
    }
    return (true);
}

// /* ************************************************************************** */
// bool is_ready_push_b(t_data *d)
// {
//     if (
        
//         (d->a.head->val < d->a.tail->val)
//         && (d->a.head->val < d->a.tail->next->val)
//         && (d->b.head->val > d->b.tail->val)
//         && (d->b.head->val > d->b.tail->next->val)

//         )
//         return (true);

//     return (false);
// }
