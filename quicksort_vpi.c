/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_vpi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:40:02 by ski               #+#    #+#             */
/*   Updated: 2022/03/04 10:40:05 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static void	swap_vpi(t_vpi *x, t_vpi *y);
/* ************************************************************************** */
void quicksort_vpi(t_vpi *vpi, int start, int end)
{
	int big;
	int small;
	int pivot;

	if (start < end)
	{
		pivot = start;
		big = start;
		small = end;
		/* -------------------------------------------------- */
		while (big < small)
		{
			/* Go find big number than pivot ---------- */
			while (vpi[big].val <= vpi[pivot].val && big < end)
				big++;
			
			/* Go find small number than pivot -------- */
			while (vpi[small].val > vpi[pivot].val)
				small--;

			/* Then swap big and small number --------- */
			if (big < small)
				swap_vpi(&vpi[big], &vpi[small]);
		}
		/* -------------------------------------------------- */
		swap_vpi(&vpi[pivot], &vpi[small]);
		quicksort_vpi(vpi, start, small - 1);
		quicksort_vpi(vpi, small + 1, end);
		/* -------------------------------------------------- */
	}
}
/* ************************************************************************** */
static void swap_vpi(t_vpi *x, t_vpi *y)
{
	t_vpi temp;

	temp.val = x->val;
	temp.ptr = x->ptr;
	x->val = y->val;
	x->ptr = y->ptr;
	y->val = temp.val ;
	y->ptr = temp.ptr ;
}