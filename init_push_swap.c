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
	d->a.head = NULL;
	d->a.tail = NULL;
	d->a.size = 0;
	d->a.stk_id = STACK_ID_A;
    /* ---------------------------- */
	d->b.head = NULL;
	d->b.tail = NULL;
	d->b.size = 0;
	d->b.stk_id = STACK_ID_B;
    /* ---------------------------- */
	d->algo_direction = DIR_A_TO_B;
	d->algo_choosed = ALGO_1;
    /* ---------------------------- */
	d->algo_1.id = ALGO_1;
	d->algo_2.id = ALGO_2;
	d->algo_3.id = ALGO_3;
	d->algo_4.id = ALGO_4;
	d->algo_5.id = ALGO_5;
	d->algo_6.id = ALGO_6;
	d->algo_7.id = ALGO_7;
	d->algo_8.id = ALGO_8;
    /* ---------------------------- */
	d->cnt_cmd = 0;
    /* ---------------------------- */
    return ;
}
