/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
static void	display_stack_double(t_ps **ptr_a, t_ps **ptr_b);
static void	display_stack_a_only(t_ps **ptr_a);
static void	display_stack_b_only(t_ps **ptr_b);

/* ************************************************************************** */
void	display(t_data *d)
{
	if (FLAG_INFO)
	{
		display_2_list(d);
		ft_printf("\n");
		display_size(d);
		display_stack_address(d);
		ft_printf("-------------------------------");
		ft_printf("------------ CMD[%d]\n", d->cnt_cmd);
	}
	return ;
}

/* ************************************************************************** */
void	display_2_list(t_data *d)
{
	int		height;
	int		i;
	t_ps	*ptr_a;
	t_ps	*ptr_b;

	ptr_a = d->a.head;
	ptr_b = d->b.head;
	if (d->a.size >= d->b.size)
		height = d->a.size;
	else
		height = d->b.size;
	i = height;
	while (i > 0)
	{
		if ((d->a.size >= i) && (d->b.size >= i))
			display_stack_double(&ptr_a, &ptr_b);
		if ((d->a.size >= i) && (d->b.size < i))
			display_stack_a_only(&ptr_a);
		if ((d->a.size < i) && (d->b.size >= i))
			display_stack_b_only(&ptr_b);
		i--;
	}
	return ;
}

/* ************************************************************************** */
static void	display_stack_double(t_ps **ptr_a, t_ps **ptr_b)
{
	ft_printf("\t[%d (i:%d)] chk:%d\t",
		(*ptr_a)->val, (*ptr_a)->index, (*ptr_a)->chk_id);
	ft_printf("[%d (i:%d)] chk:%d\n",
		(*ptr_b)->val, (*ptr_b)->index, (*ptr_b)->chk_id);
	(*ptr_a) = (*ptr_a)->next;
	(*ptr_b) = (*ptr_b)->next;
}

/* ************************************************************************** */
static void	display_stack_a_only(t_ps **ptr_a)
{
	ft_printf("\t[%d (i:%d)] chk:%d\t   \n",
		(*ptr_a)->val, (*ptr_a)->index, (*ptr_a)->chk_id);
	(*ptr_a) = (*ptr_a)->next;
}

/* ************************************************************************** */
static void	display_stack_b_only(t_ps **ptr_b)
{
	ft_printf("\t\t\t\t[%d (i:%d)] chk:%d\n",
		(*ptr_b)->val, (*ptr_b)->index, (*ptr_b)->chk_id);
	(*ptr_b) = (*ptr_b)->next;
}

/* ************************************************************************** */
// 	while (i > 0)
// 	{
// 		if ((height_a >= i) && (height_b >= i))
// 		{
// /* ----------------------------------------------------------------------- */
// ft_printf("\t[%d (i:%d)] chk:%d\t", ptr_a->val, ptr_a->index, ptr_a->chk_id);
// ft_printf("[%d (i:%d)] chk:%d\n", ptr_b->val, ptr_b->index, ptr_b->chk_id);
// /* ----------------------------------------------------------------------- */
// // ft_printf("\t[%d (i:%d)] chke:%d chks:%d\t", 
// ptr_a->val, ptr_a->index, ptr_a->chk_end, ptr_a->chk_start);
// // ft_printf("[%d (i:%d)] chke:%d chks:%d\n", 
// ptr_b->val, ptr_b->index, ptr_b->chk_end, ptr_b->chk_start);
// // ft_printf("\t[%d (i:%d)]\t[%d (i:%d)]\n", 
// ptr_a->val, ptr_a->index, ptr_b->val, ptr_b->index);
// // ft_printf("\t%p:[%d (i:%d)]\t%p:[%d (i:%d)]\n", 
// ptr_a, ptr_a->val, ptr_a->index, ptr_b, ptr_b->val, ptr_b->index);
// /* ----------------------------------------------------------------------- */
// ft_printf("\t%p:[%d]\t%p:[%d]\n", ptr_a, ptr_a->val, ptr_b, ptr_b->val);
// /* ----------------------------------------------------------------------- */
// ptr_a = ptr_a->next;
// ptr_b = ptr_b->next;
// 		}

// 		if ((height_a >= i) && (height_b < i))
// 		{
// /* ----------------------------------------------------------------------- */
// ft_printf("\t[%d (i:%d)] chk:%d\t   \n", 
// ptr_a->val, ptr_a->index, ptr_a->chk_id);
// /* ----------------------------------------------------------------------- */
// // ft_printf("\t[%d (i:%d)] chke:%d chks:%d\t   \n", 
// ptr_a->val, ptr_a->index, ptr_a->chk_end, ptr_a->chk_start);
// // ft_printf("\t[%d (i:%d)]\t   \n", ptr_a->val, ptr_a->index);
// // ft_printf("\t%p:[%d (i:%d)]\t   \n", ptr_a, ptr_a->val, ptr_a->index);
// /* ----------------------------------------------------------------------- */
// // ft_printf("\t%p:[%d]\t   \n", ptr_a, ptr_a->val);
// /* ----------------------------------------------------------------------- */
// ptr_a = ptr_a->next;
// 		}
// 		if ((height_a < i) && (height_b >= i))
// 		{

// /* ----------------------------------------------------------------------- */
// ft_printf("\t\t\t\t[%d (i:%d)] chk:%d\n", 
// ptr_b->val, ptr_b->index, ptr_b->chk_id);
// /* ----------------------------------------------------------------------- */
// // ft_printf("\t\t\t\t[%d (i:%d)] chke:%d chks:%d\n", 
// ptr_b->val, ptr_b->index, ptr_b->chk_end, ptr_b->chk_start);
// // ft_printf("\t\t\t\t[%d (i:%d)]\n", ptr_b->val, ptr_b->index);
// // ft_printf("\t\t\t\t%p:[%d (i:%d)]\n", ptr_b, ptr_b->val, ptr_b->index);
// /* ----------------------------------------------------------------------- */
// // ft_printf("\t\t\t\t%p:[%d]\n", ptr_b, ptr_b->val);
// /* ----------------------------------------------------------------------- */
// ptr_b = ptr_b->next;

// 		}
// 		i--;
// 	}