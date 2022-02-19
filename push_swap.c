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
	int i;
	int val;	
	
	init_push_swap(&d);

	val = 0;
	i = 1;

	/* ---------------------------------- */
	if (argc == 1)
		return 0;
	/* ---------------------------------- */
	while (i < argc)
	{
		if (!is_countable(argv[i]))
		{
			printf("argv[%d]: non countable: [%s]\n", i, argv[i]);
			return (1);
		}
		val = atoi(argv[i]);
		ps_new_elem_at_bottom(&d.stack_a, val);
		i++;
	}
	/* ---------------------------------- */
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

