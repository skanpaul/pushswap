/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg_parameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool manage_arg_parameter(char **argv, t_data *d)
{
    int i;
	int val;
	int split_c;
	char **split_v;

	split_v = ft_split(argv[1], ' ');
	split_c = ft_split_count(split_v);

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
		ps_new_elem_at_bottom(val, &d->a);
		i++;
	}
	ft_split_free(split_v);    
    return (EXIT_NO);
}
