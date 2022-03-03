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
t_algo	choose_algo(t_data *d);
void	do_swap_far_elem_algo(int algo, t_ps *elem_1, t_ps *elem_2, t_data *d);
/* ************************************************************************** */
void swap_far_elem(t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	t_algo algo;
	
	calculate_coef(elem_1, elem_2, d);
	algo = choose_algo(d);
	do_swap_far_elem_algo(algo.id, elem_1, elem_2, d);
}

/* ************************************************************************** */
t_algo choose_algo(t_data *d)
{
	t_algo temp;

	temp = d->algo_1;
	if (d->algo_2.coef < temp.coef)
		temp = d->algo_2;
	if (d->algo_3.coef < temp.coef)
		temp = d->algo_3;
	if (d->algo_4.coef < temp.coef)
		temp = d->algo_4;
	if (d->algo_5.coef < temp.coef)
		temp = d->algo_5;
	if (d->algo_6.coef < temp.coef)
		temp = d->algo_6;
	if (d->algo_7.coef < temp.coef)
		temp = d->algo_7;
	if (d->algo_8.coef < temp.coef)
		temp = d->algo_8;

	return (temp);
}

/* ************************************************************************** */
void do_swap_far_elem_algo(int algo, t_ps *elem_1, t_ps *elem_2, t_data *d)
{
	if (algo == ALGO_1)
		swap_far_algo1(elem_1, elem_2, d);
	else if (algo == ALGO_2)
		swap_far_algo2(elem_1, elem_2, d);
	else if (algo == ALGO_3)
		swap_far_algo3(elem_1, elem_2, d);
	else if (algo == ALGO_4)
		swap_far_algo4(elem_1, elem_2, d);
	else if (algo == ALGO_5)
		swap_far_algo5(elem_1, elem_2, d);
	else if (algo == ALGO_6)
		swap_far_algo6(elem_1, elem_2, d);
	else if (algo == ALGO_7)
		swap_far_algo7(elem_1, elem_2, d);
	else if (algo == ALGO_8)
		swap_far_algo8(elem_1, elem_2, d);
}
