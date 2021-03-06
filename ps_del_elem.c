/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_del_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:48:27 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 09:48:29 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void	ps_del_elem(t_ps *elem)
{
	if (elem == NULL)
		return ;
	free(elem);
	elem = NULL;
	return ;
}
