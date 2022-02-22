/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void init_push_swap(t_data *d)
{
    
    /* ---------------------------- */
    d->head_a = NULL;
    d->tail_a = NULL;
    d->size_a = 0;
    /* ---------------------------- */
    d->head_b = NULL;
    d->tail_b = NULL;   
    d->size_b = 0;
    /* ---------------------------- */
	d->cnt_cmd = 0;
    return ;
}
    // /* ---------------------------- */
    // a->head = NULL;
    // a->tail = NULL;
    // a->size = 0;
    // /* ---------------------------- */
    // b->head = NULL;
    // b->tail = NULL;
    // b->size = 0;  