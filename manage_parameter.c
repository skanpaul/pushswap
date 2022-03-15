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
static int	manage_is_param_ok(char **argv, int *i);
static int	manage_is_duplicated(t_data *d, int *val, int *i);

/* ************************************************************************** */
bool	manage_parameter(int argc, char **argv, t_data *d)
{
	int		i;
	int		val;	
	t_ps	*new;

	d->vpi_size = argc - 1;
	d->vpi = vpi_create(d->vpi_size);
	i = 1;
	while (i < argc)
	{
		if (manage_is_param_ok(argv, &i) == EXIT_YES)
			return (EXIT_YES);
		val = ft_atoi(argv[i]);
		if (manage_is_duplicated(d, &val, &i) == EXIT_YES)
			return (EXIT_YES);
		new = ps_new_elem(val);
		ps_add_elem_to_bottom(new, &d->a);
		(d->vpi)[i - 1].val = val;
		d->vpi[i - 1].ptr = new;
		d->vpi[i - 1].ptr->chk_id = argc - 2;
		i++;
	}
	return (EXIT_NO);
}

/* ************************************************************************** */
static int	manage_is_param_ok(char **argv, int *i)
{	
	if (!is_param_ok(argv[*i], *i))
	{
		ft_printf_error("Error\n");
		return (EXIT_YES);
	}
	return (EXIT_NO);
}

/* ************************************************************************** */
static int	manage_is_duplicated(t_data *d, int *val, int *i)
{
	if (is_duplicated(&d->a.head, *val))
	{
		ps_del_list(&d->a.head);
		ps_del_list(&d->b.head);
		if (FLAG_INFO)
			ft_printf("argv[%d]: is duplicated [%d]\n", *i, *val);
		ft_printf_error("Error\n");
		return (EXIT_YES);
	}
	return (EXIT_NO);
}
