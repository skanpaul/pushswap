/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

/* ************************************************************************** */
int main (int argc, char **argv)
{
	t_ps *stack_a;
	t_ps *stack_b;
	int i;
	int val;

	stack_a = NULL;
	stack_b = NULL;


	val = 0;
	i = 1;

	/* ---------------------------------- */
	if (argc == 1)
		return 0;
	/* ---------------------------------- */
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		ft_printf("Valeur[%d] = %d\n", i, val);
		ps_new_elem_at_bottom(&stack_a, val);
		i++;
	}
	/* ---------------------------------- */
	ps_display(stack_a);


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