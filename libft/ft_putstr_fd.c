/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:20:17 by ski               #+#    #+#             */
/*   Updated: 2021/11/21 09:20:20 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
// RETURN 0 IF THERE IS AN ERROR LIKE:
//		s == NULL
//		fd == -1
//		write() return -1
/* ************************************************************************** */
size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	if ((!s) | (fd == -1))
		return (0);
	if (write(fd, s, len) == -1)
		return (0);
	return (len);
}