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
static int	manage_is_param_ok(t_madq *madq_d);
static int	manage_is_duplicated(t_data *d, t_madq *madq_d);
static void	init_vpi(t_data *d, t_madq *madq_d);

/* ************************************************************************** */
bool	manage_arg_doublequote(char **argv, t_data *d)
{
	t_madq	madq_d;

	madq_d.split_v = ft_split(argv[1], ' ');
	madq_d.split_c = ft_split_count(madq_d.split_v);
	d->vpi_size = madq_d.split_c;
	d->vpi = vpi_create(d->vpi_size);
	madq_d.i = 0;
	while (madq_d.i < madq_d.split_c)
	{
		if (manage_is_param_ok(&madq_d) == EXIT_YES)
			return (EXIT_YES);
		madq_d.val = atoi(madq_d.split_v[madq_d.i]);
		if (manage_is_duplicated(d, &madq_d) == EXIT_YES)
			return (EXIT_YES);
		madq_d.new = ps_new_elem(madq_d.val);
		ps_add_elem_to_bottom(madq_d.new, &d->a);
		init_vpi(d, &madq_d);
		madq_d.i++;
	}
	ft_split_free(madq_d.split_v);
	return (EXIT_NO);
}

/* ************************************************************************** */
static int	manage_is_param_ok(t_madq *madq_d)
{	
	if (!is_param_ok(madq_d->split_v[madq_d->i], madq_d->i))
	{
		ft_printf_error("Error\n");
		ft_split_free(madq_d->split_v);
		return (EXIT_YES);
	}
	return (EXIT_NO);
}

/* ************************************************************************** */
static int	manage_is_duplicated(t_data *d, t_madq *madq_d)
{
	int	i;
	int	val;

	i = madq_d->i;
	val = madq_d->val;
	if (is_duplicated(&d->a.head, madq_d->val))
	{
		ps_del_list(&d->a.head);
		ps_del_list(&d->b.head);
		if (FLAG_INFO)
			ft_printf("split_v[%d]: is duplicated [%d]\n", i, val);
		ft_printf_error("Error\n");
		ft_split_free(madq_d->split_v);
		return (EXIT_YES);
	}
	return (EXIT_NO);
}

/* ************************************************************************** */
static void	init_vpi(t_data *d, t_madq *madq_d)
{
	d->vpi[madq_d->i].val = madq_d->val;
	d->vpi[madq_d->i].ptr = madq_d->new;
	d->vpi[madq_d->i].ptr->chk_id = madq_d->split_c - 1;
}
