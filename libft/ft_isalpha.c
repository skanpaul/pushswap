/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:06:04 by ski               #+#    #+#             */
/*   Updated: 2021/10/28 10:06:28 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((('A' <= c) & (c <= 'Z')) | (('a' <= c) & (c <= 'z')))
		return (1);
	else
		return (0);
}