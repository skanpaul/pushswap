/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:26:24 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:26:26 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
int	ll_size(t_elem *top_elem)
{
	int		size;
	t_elem	*ptr;

	ptr = top_elem;
	if (!ptr)
		return (0);
	size = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}


