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
static void	main_part2(t_data *d);

/* ************************************************************************** */
int	main(int argc, char **argv)
{
	t_data	d;
	bool	flag_exit;

	flag_exit = false;
	init_push_swap(&d);
	if (argc == 1)
		return (0);
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
	main_part2(&d);
	return (0);
}

/* ************************************************************************** */
static void	main_part2(t_data *d)
{
	do_vpi(d);
	display(d);
	if (!is_in_order(d->a.head))
	{
		if (d->a.size == 3)
			sort_3_elem(d);
		else
			sort_chunk_a(d);
	}
	if (FLAG_INFO)
	{
		if (is_in_order(d->a.head))
			ft_printf("\nStack A is in ORDER\n\n");
		else
			ft_printf("\nStack A is NOT SORTED\n\n");
	}
	ps_del_list(&d->a.head);
	ps_del_list(&d->b.head);
	vpi_free(&d->vpi);
}

/* ************************************************************************** */