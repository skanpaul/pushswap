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
		// val = ft_atoi(argv[i]);
		val = atoi(argv[i]);
		// printf("Valeur[%d] = %d\n", i, val);
		ps_new_elem_at_bottom(&d.stack_a, val);
		i++;
	}
	/* ---------------------------------- */
	ps_display_1_list(d.stack_a);
	d.size_a = ps_size(d.stack_a);
	printf("Size of stack_a: [%d]\n", d.size_a);
	printf("Size of stack_b: [%d]\n\n", d.size_b);

	// swap_a(&d);
	rotate_a(&d);
	ps_display_1_list(d.stack_a);
	d.size_a = ps_size(d.stack_a);
	printf("Size of stack_a: [%d]\n", d.size_a);
	printf("Size of stack_b: [%d]\n\n", d.size_b);

	ps_del_list(d.stack_a);
	ps_del_list(d.stack_b);

	return 0;
}

/* ************************************************************************** */



// sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
// sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
// ss : sa and sb at the same time.


// pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.


// ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
// rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.


// rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
// rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.