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

/* Smallest number on the top *********************************************** */
/* ************************************************************************** */
int main (int argc, char **argv)
{
	t_data	d; // data
	bool	flag_exit;
	// t_ps	*temp;
	t_ps	*elem_1;
	t_ps	*elem_2;
	// int		pos;
	// int		distance;

	flag_exit = false;	
	/* INITIALISATION ------------------------------ */
	init_push_swap(&d);
	/* CHECK ARG-C --------------------------------- */
if (argc == 1)
		return 0;
	/* SAVE PARAMETERS ----------------------------- */
	if (argc == 2)
	{
		flag_exit = manage_arg_parameter(argv, &d);
		if (flag_exit == EXIT_YES)
			return (EXIT_YES);
	}
	else
	{
		flag_exit = manage_parameter(argc, argv, &d);
		if (flag_exit == EXIT_YES)
			return (EXIT_YES);
	}

	/* ********************************************* */

	display(&d);
	push_to_b_loop(&d, 8);
	/* --------------------------- */
	
	elem_1 = ps_get_elem(&d.a, 6);
	elem_2 = ps_get_elem(&d.a, 7);
	// elem_1 = ps_get_elem(&d.b, 6);
	// elem_2 = ps_get_elem(&d.b, 4);

	swap_far_elem(elem_1, elem_2, &d);
	/* --------------------------- */

	/* ********************************************* */
	ps_del_list(&d.a.head);
	ps_del_list(&d.b.head);
	return 0;
}

	// // quick_sort(&d);
	// temp = ps_get_elem(&d.a, 3);
	// distance = distance_to_top_upwards(temp);
	// distance = distance_to_top_downwards(temp);
	// pos = ps_get_position(&d, temp);

	// temp = ps_get_elem(&d.a, 0);
	// distance = distance_to_top_upwards(temp);
	// distance = distance_to_top_downwards(temp);
	// pos = ps_get_position(&d, temp);	

	// temp = ps_get_elem(&d.a, 7);
	// distance = distance_to_top_upwards(temp);
	// distance = distance_to_top_downwards(temp);
	// pos = ps_get_position(&d, temp);

	// temp = ps_get_elem(&d.a, 100);
	// distance = distance_to_top_upwards(temp);
	// distance = distance_to_top_downwards(temp);
	// pos = ps_get_position(&d, temp);