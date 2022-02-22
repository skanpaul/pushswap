/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ready_push_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_ready_push_a(t_data *d)
{
	if ((has_1_elem_or_more(&d->head_a))
		&& (has_2_elem_or_more(&d->head_b)) 
		&& (d->head_b->val < d->head_b->next->val))
		return (false);

	if ((has_1_elem_or_more(&d->head_a))
		&& (has_1_elem_or_more(&d->head_b))
		&& (d->head_a->val < d->head_b->val)
		)
		return (false);


    return (true);
}

// /* ************************************************************************** */

// bool is_ready_push_a(t_data *d)
// {
//     if (has_2_elem_or_more(&d->head_a))
//     {
//         // [A]: le plus GRAND disque devrait etre au FOND
//         if (d->head_a->val > d->tail_a->val)
//             return (false);
//         // [A]: le plus PETIT disque devrait eter au SOMMET
//         if (d->head_a->val > d->head_a->next->val)
//             return (false);
//     }

//     if (has_2_elem_or_more(&d->head_b))
//     {
//         // [B]: le plus PETIT disque devrait etre au FOND
//         if (d->head_b->val < d->tail_b->val)
//             return (false);
//         // [B]: le plus GRAND disque devrait etre au SOMMET
//         if (d->head_b->val < d->head_b->next->val)
//             return (false);
//     }
//     return (true);
// }
