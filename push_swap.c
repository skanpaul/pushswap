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
int main (int argc, char **argv)
{
	t_data	d;
	bool	flag_exit;

	flag_exit = false;	
	/* INITIALISATION ------------------------------ */
	init_push_swap(&d);
	/* CHECK ARG-C --------------------------------- */
	if (argc == 1)
		return 0;
	/* SAVE PARAMETERS ----------------------------- */
	if (argc == 2)
	{
		flag_exit = manage_arg_doublequote(argv, &d);
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

	do_vpi(&d);
	display(&d);
	/* --------------------------- */
	midsort(&d);


	/* --------------------------- */
	display(&d);
	vpi_display(d.vpi, d.vpi_size);
	/* ********************************************* */
	ps_del_list(&d.a.head);
	ps_del_list(&d.b.head);
	vpi_free(&d.vpi);
	return 0;
}

/* ************************************************************************** */

	// push_to_b_loop(&d, 8);
	// /* --------------------------- */
	
	// elem_1 = ps_get_elem(&d.a, 3);
	// elem_2 = ps_get_elem(&d.b, 6);
	// // elem_1 = ps_get_elem(&d.b, 6);
	// // elem_2 = ps_get_elem(&d.b, 4);

	// swap_far_elem(elem_1, elem_2, &d);