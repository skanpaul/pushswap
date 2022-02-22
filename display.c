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
	printf("\n");
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

    height_a = ps_size(d->head_a);
    height_b = ps_size(d->head_b);

    ptr_a = d->head_a;
    ptr_b = d->head_b;

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
            printf("\t\t\t\t%p:[%d]\n", ptr_b, ptr_b->val);
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
    d->size_a = ps_size(d->head_a);
	d->size_b = ps_size(d->head_b);
	printf("Size\ta:[%d]\t\t\tb:[%d]\n", d->size_a, d->size_b);
}

/* ************************************************************************** */
void display_stack_address(t_data *d)
{
    if((*d).head_a == NULL)
        printf("HEAD_a\t[%p]\t\t\tHEAD_b\t[%p]\n", (*d).head_a, (*d).head_b);
    else
        printf("HEAD_a\t[%p]\tHEAD_b\t[%p]\n", (*d).head_a, (*d).head_b);
    
    if((*d).tail_a == NULL)
        printf("BOT_a\t[%p]\t\t\tBOT_b\t[%p]\n", (*d).tail_a, (*d).tail_b);
    else
        printf("BOT_a\t[%p]\tBOT_b\t[%p]\n", (*d).tail_a, (*d).tail_b);
}
