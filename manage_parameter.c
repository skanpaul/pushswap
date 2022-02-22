/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_parameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool manage_parameter(int argc, char **argv, t_data *d)
{
    int i;
	int val;
    
	val = 0;
	i = 1;

    while (i < argc)
	{
	    /* --------------------------------------------- */
        if(!is_param_ok(argv[i], i))
			return (EXIT_YES);
	    /* --------------------------------------------- */
		val = atoi(argv[i]);
        if (is_duplicated(&d->head_a, val))
        {
            ps_del_list(&d->head_a);
            ps_del_list(&d->head_b);
            printf("argv[%d]: is duplicated [%d]\n", i, val);
            return (EXIT_YES);
        }
	    /* --------------------------------------------- */
		ps_new_elem_at_bottom(val, &d->head_a, &d->tail_a);
		i++;
	}     
    return (EXIT_NO);
}
