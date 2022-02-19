/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
int main (int argc, char **argv)
{
	t_data	d;
	bool	flag_exit;

	flag_exit = false;	
	/* --------------------------------------------- */
	init_push_swap(&d);
	/* --------------------------------------------- */
	if (argc == 1)
		return 0;
	/* --------------------------------------------- */
	flag_exit = manage_parameter(argc, argv, &d);
	if (flag_exit == EXIT_YES)
		return (EXIT_YES);
	/* --------------------------------------------- */


	ps_display_2_list(&d);
	d.size_a = ps_size(d.stack_a);
	d.size_b = ps_size(d.stack_b);
	printf("Size a:[%d] b:[%d]\n\n", d.size_a, d.size_b);

	push_to_b(&d);
	push_to_b(&d);
	push_to_b(&d);
	ps_display_2_list(&d);
	d.size_a = ps_size(d.stack_a);
	d.size_b = ps_size(d.stack_b);
	printf("Size a:[%d] b:[%d]\n\n", d.size_a, d.size_b);

	swap_2(&d);
	ps_display_2_list(&d);
	d.size_a = ps_size(d.stack_a);
	d.size_b = ps_size(d.stack_b);
	printf("Size a:[%d] b:[%d]\n\n", d.size_a, d.size_b);
	
	push_to_b(&d);
	push_to_b(&d);
	push_to_a(&d);
	ps_display_2_list(&d);
	d.size_a = ps_size(d.stack_a);
	d.size_b = ps_size(d.stack_b);
	printf("Size a:[%d] b:[%d]\n\n", d.size_a, d.size_b);

	ps_del_list(d.stack_a);
	ps_del_list(d.stack_b);

	return 0;
}

/* ************************************************************************** */

