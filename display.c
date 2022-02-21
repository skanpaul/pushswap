/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void display(t_data *d)
{
    display_2_list(d);
    display_size(d);
    display_stack_address(d);
	printf("-----------------------------------------------------\n");
    return ;
}

/* ************************************************************************** */
void	display_1_list(t_ps *top_elem)
{
	t_ps	*ptr;

	ptr = top_elem;
	if (!ptr)
		return ;

	while (ptr->next != NULL)
	{
		// ft_printf("[%d]\n", ptr->val);
		printf("[%d]\n", ptr->val);
		ptr = ptr->next;
	}
	// ft_printf("[%d]\n", ptr->val);
	printf("[%d]\n", ptr->val);
	return ;
}

/* ************************************************************************** */
void	display_2_list(t_data *d)
{
    int height;
    int height_a;
    int height_b;
    int i;
    t_ps *ptr_a;
    t_ps *ptr_b;

    height_a = ps_size(d->stack_a);
    height_b = ps_size(d->stack_b);

    ptr_a = d->stack_a;
    ptr_b = d->stack_b;

    if (height_a >= height_b)
        height = height_a;
    else
        height = height_b;

    i = height;
    while (i > 0)
    {
        if ((height_a >= i) && (height_b >= i))
        {
            printf("\t%p:[%d]\t%p:[%d]\n", ptr_a, ptr_a->val, ptr_b, ptr_b->val);
            // printf("\t[%d]\t[%d]\n", ptr_a->val, ptr_b->val);
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }

        if ((height_a >= i) && (height_b < i))
        {
            printf("\t%p:[%d]\t   \n", ptr_a, ptr_a->val);
            // printf("\t[%d]\t   \n", ptr_a->val);
            ptr_a = ptr_a->next;
        }

        if ((height_a < i) && (height_b >= i))
        {
            printf("\t   \t%p:[%d]\n", ptr_b, ptr_b->val);
            // printf("\t   \t[%d]\n", ptr_b->val);
            ptr_b = ptr_b->next;
        }
        i--;
    }

    return ;
}

/* ************************************************************************** */
void display_size(t_data *d)
{
    d->size_a = ps_size(d->stack_a);
	d->size_b = ps_size(d->stack_b);
	printf("Size\t\ta:[%d]\t\t\tb:[%d]\n\n", d->size_a, d->size_b);
}

/* ************************************************************************** */
void display_stack_address(t_data *d)
{
    printf("HEAD_a\t[%p]\t[%p]\tHEAD_b\n", (*d).stack_a, (*d).stack_b);
    printf("BOT_a\t[%p]\t[%p]\tBOT_b\n", (*d).stack_a_bottom, (*d).stack_b_bottom);
}
