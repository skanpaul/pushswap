/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:40:02 by ski               #+#    #+#             */
/*   Updated: 2022/03/04 10:40:05 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void quick_sort(t_stk *stk, t_ps *start, t_ps *end, t_data *d)
{
	t_ps *big;
	t_ps *small;
	t_ps *pivot;
	t_ps *temp;
	t_ps *temp_start;
	t_ps *temp_end;


	if (ps_get_position(d, start) < ps_get_position(d, end))
	{
		pivot = start;
		big = start;
		small = end;
		/* -------------------------------------------------- */
		while (ps_get_position(d, big) < ps_get_position(d, small))
		{
			/* Go find big number than pivot ---------- */
			while (big->val <= pivot->val && ps_get_position(d, big) < ps_get_position(d, end))
				big = big->next;
			
			/* Go find small number than pivot -------- */
			while (small->val > pivot->val)
				small = small->prev;

			/* Then swap big and small number --------- */
			if (ps_get_position(d, big) < ps_get_position(d, small))
			{
				temp_start = NULL;
				temp_end = NULL;

				if (big == start)
					temp_start = small;
				if (small == start)
					temp_start = big;

				if (big == end)
					temp_end = small;
				if (small == end)
					temp_end = big;
			
				swap_far_elem(big, small, d);
				temp = big;
				big = small;
				small = temp;
				if (temp_start)
					start = temp_start;
				if (temp_end)
					end = temp_end;
				// end = ps_get_last_elem(&d->a.head);
			}
		}
		/* -------------------------------------------------- */
		temp_start = NULL;
		temp_end = NULL;

		if (pivot == start)
			temp_start = small;
		if (small == start)
			temp_start = pivot;

		if (pivot == end)
			temp_end = small;
		if (small == end)
			temp_end = pivot;
		
		swap_far_elem(pivot, small, d);
		temp = pivot;
		pivot = small;
		small = temp;
		if (temp_start)
			start = temp_start;
		if (temp_end)
			end = temp_end;
		// end = ps_get_last_elem(&d->a.head); 

		quick_sort(stk, start, small->prev, d);
		// if (small->next == NULL)
		// 	quick_sort(stk, small, end, d);
		// else
			quick_sort(stk, small->next, end, d);
		/* -------------------------------------------------- */
	}
}


/* ************************************************************************** */

// void quick_sort(int n[25], int start, int end)
// {
// 	int big;
// 	int small;
// 	int pivot;
// 	int temp;

// 	if (start < end)
// 	{
// 		pivot = start;
// 		big = start;
// 		small = end;
// 		/* -------------------------------------------------- */
// 		while (big < small)
// 		{
// 			/* Go find big number than pivot ---------- */
// 			while (n[big] <= n[pivot] && big < end)
// 				big++;
			
// 			/* Go find small number than pivot -------- */
// 			while (n[small] > n[pivot])
// 				small--;

// 			/* Then swap big and small number --------- */
// 			if (big < small)
// 			{
// 				temp = n[big];
// 				n[big] = n[small];
// 				n[small] = temp;
// 			}
// 		}
// 		/* -------------------------------------------------- */
// 		temp = n[pivot];
// 		n[pivot] = n[small];
// 		n[small] = temp;
// 		quicksort(n, start, small - 1);
// 		quicksort(n, small + 1, end);
// 		/* -------------------------------------------------- */
// 	}
// }