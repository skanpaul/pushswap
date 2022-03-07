/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vpi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:53:43 by ski               #+#    #+#             */
/*   Updated: 2022/03/07 10:53:45 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void do_vpi(t_data *d)
{
	quicksort_vpi(d->vpi, 0, d->vpi_size - 1);
	vpi_do_index(d->vpi, d->vpi_size);
}

/* ************************************************************************** */
t_vpi	*vpi_create(int size)
{
	t_vpi	*vpi;

	vpi = (t_vpi *)malloc(size * sizeof(t_vpi));
	return (vpi);
}
/* ************************************************************************** */
void	vpi_do_index(t_vpi *vpi, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		vpi[i].index = i;
		vpi[i].ptr->index = vpi[i].index;
		i++;
	}
}

/* ************************************************************************** */
void	vpi_display(t_vpi *vpi, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("i:%d\t", i);
		printf("val[%d]\t", vpi[i].val);
		printf("ptr[%p]\t", vpi[i].ptr);
		printf("index[%i]\n", vpi[i].index);
		i++;
	}
	printf("--------------------------------------------------------\n");
}

/* ************************************************************************** */
void	vpi_free(t_vpi **vpi)
{
	if(!*vpi)
		return ;
	free(*vpi);
	*vpi = NULL;
}
