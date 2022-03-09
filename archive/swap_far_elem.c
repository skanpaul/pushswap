/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_far_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:22:13 by ski               #+#    #+#             */
/*   Updated: 2022/03/01 17:22:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
t_algo	choose_algo(t_ps *elem_1, t_ps *elem_2, t_data *d);
void	do_swap_far_elem_algo(int algo, t_ps *elem_1, t_ps *elem_2, t_data *d);
/* ************************************************************************** */
void swap_far_elem(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	calculate_coef(elem_1, elem_2, d);
	d->algo = choose_algo( elem_1, elem_2, d);
	do_swap_far_elem_algo(d->algo.id, elem_1, elem_2, d);
}

/* ************************************************************************** */
t_algo choose_algo(t_ps *elem_1, t_ps *elem_2,t_data *d)
{
	t_algo temp;

	if ((elem_1->stk_id == elem_2->stk_id) && (d->h_elem->next != d->l_elem))
	{
		temp = d->algo_1;
		if (d->algo_2.coef < temp.coef)
			temp = d->algo_2;
		if (d->algo_3.coef < temp.coef)
			temp = d->algo_3;
		if (d->algo_4.coef < temp.coef)
			temp = d->algo_4;
	}
	else if ((elem_1->stk_id == elem_2->stk_id) && (d->h_elem->next == d->l_elem))
	{
		temp = d->algo_9;
		if (d->algo_10.coef < temp.coef)
			temp = d->algo_10;
	}
	else
	{
		temp = d->algo_5;
		if (d->algo_6.coef < temp.coef)
			temp = d->algo_6;
		if (d->algo_7.coef < temp.coef)
			temp = d->algo_7;
		if (d->algo_8.coef < temp.coef)
			temp = d->algo_8;
	}
	return (temp);
}

/* ************************************************************************** */
void do_swap_far_elem_algo(int algo, t_ps *elem_1, t_ps *elem_2, t_data *d)
{	
	if (elem_1->stk_id == elem_2->stk_id)
	{
		if (algo == ALGO_1)
			swap_far_algo1(elem_1, elem_2, d);
		else if (algo == ALGO_2)
			swap_far_algo2(elem_1, elem_2, d);
		else if (algo == ALGO_3)
			swap_far_algo3(elem_1, elem_2, d);
		else if (algo == ALGO_4)
			swap_far_algo4(elem_1, elem_2, d);
		else if (algo == ALGO_9)
			swap_far_algo9(elem_1, elem_2, d);
		else if (algo == ALGO_10)
			swap_far_algo10(elem_1, elem_2, d);
	}
	else
	{
		if (algo == ALGO_5)
			swap_far_algo5(elem_1, elem_2, d);
		else if (algo == ALGO_6)
			swap_far_algo6(elem_1, elem_2, d);
		else if (algo == ALGO_7)
			swap_far_algo7(elem_1, elem_2, d);
		else if (algo == ALGO_8)
			swap_far_algo8(elem_1, elem_2, d);
	}		
}
