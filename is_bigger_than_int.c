/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bigger_than_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool is_bigger_than_int(char *str)
{
    long value;
    int i;

    if (!str)
        return (false);

    i = 0;
    while (str[i] != '\0')
        i++;

    if (i > 11)
        return (true);    

    value = ft_atoil(str);

    if ((value < -2147483648) || ( value > 2147483647))
        return (true);

    return (false);
}
