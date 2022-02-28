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

	i = 1;
    while (i < argc)
	{
	    /* --------------------------------------------- */
        if(!is_param_ok(argv[i], i))
		{
			printf("Error\n");	
			return (EXIT_YES);
		}
	    /* --------------------------------------------- */
		val = atoi(argv[i]);
        if (is_duplicated(&d->a.head, val))
        {
            ps_del_list(&d->a.head);
            ps_del_list(&d->b.head);

            if (FLAG_INFO)
				printf("argv[%d]: is duplicated [%d]\n", i, val);
			printf("Error\n");	
            return (EXIT_YES);
        }
	    /* --------------------------------------------- */
		ps_new_elem_at_bottom(val, &d->a.head, &d->a.tail);
		i++;
	}     
    return (EXIT_NO);
}
