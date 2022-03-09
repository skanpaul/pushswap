/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg_doublequote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool manage_arg_doublequote(char **argv, t_data *d)
{
    int i;
	int val;
	int split_c;
	char **split_v;
	t_ps *new;

	split_v = ft_split(argv[1], ' ');
	split_c = ft_split_count(split_v);
	d->vpi_size = split_c;
	d->vpi = vpi_create(d->vpi_size );	

	i = 0;
    while (i < split_c)
	{
	    /* --------------------------------------------- */
        if(!is_param_ok(split_v[i], i))
		{
			printf("Error\n");	
			ft_split_free(split_v);
			return (EXIT_YES);
		}
	    /* --------------------------------------------- */
		val = atoi(split_v[i]);
        if (is_duplicated(&d->a.head, val))
        {
            ps_del_list(&d->a.head);
            ps_del_list(&d->b.head);

            if (FLAG_INFO)
				printf("split_v[%d]: is duplicated [%d]\n", i, val);
			printf("Error\n");
			ft_split_free(split_v);	
            return (EXIT_YES);
        }
	    /* --------------------------------------------- */
		// ps_new_elem_at_bottom(val, &d->a);
		new = ps_new_elem(val);
		ps_add_elem_to_bottom(new, &d->a);
		(d->vpi)[i].val = val;
		d->vpi[i].ptr = new;
		d->vpi[i].ptr->chk_id = 0;
		i++;
	}
	ft_split_free(split_v);    
    return (EXIT_NO);
}
