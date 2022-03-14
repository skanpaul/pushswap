/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool	is_param_ok(char *str, int pos)
{
	if (!is_countable(str))
	{
		if (FLAG_INFO)
			ft_printf("argv[%d]: not countable: [%s]\n", pos, str);
		return (false);
	}
	if (is_bigger_than_int(str))
	{
		if (FLAG_INFO)
			ft_printf("argv[%d]: bigger than int: [%s]\n", pos, str);
		return (false);
	}
	return (true);
}

/* ************************************************************************** */
// print error with "\n" on standard error
// error: non integer parameters            --> DONE
// error: parameters bigger than integer    --> DONE
// error: parameters are duplicated