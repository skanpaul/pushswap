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
	t_ps *new;

	d->vpi_size = argc - 1;
	d->vpi = vpi_create(d->vpi_size);	

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
		// ps_new_elem_at_bottom(val, &d->a);

		new = ps_new_elem(val);
		ps_add_elem_to_bottom(new, &d->a);
		(d->vpi)[i - 1].val = val;
		d->vpi[i - 1].ptr = new;
		d->vpi[i - 1].ptr->chk_id = argc - 2;
		i++;
	}     
    return (EXIT_NO);
}
