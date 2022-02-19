/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_countable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_countable(char *str)
{
	int i;

    if (!str)
        return (false);
    i = 0;    
    if ((str[i] == '+') || (str[i] == '-'))
        i++;
    if (!isdigit(str[i]))
        return (false);
    while ((str[i] != '\0') && (isdigit(str[i])))
        i++;
    if (str[i] == '\0')
		return (true);
    if (!isdigit(str[i]))
        return (false);
    return (true);
}
