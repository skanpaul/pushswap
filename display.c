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
    if (FLAG_INFO)
	{
		display_2_list(d);
		printf("\n");
		display_size(d);
		display_stack_address(d);
		printf("------------------------------------------- CMD[%d]\n", d->cnt_cmd);
	}
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

    height_a = ps_size(d->a.head);
    height_b = ps_size(d->b.head);

    ptr_a = d->a.head;
    ptr_b = d->b.head;

    if (height_a >= height_b)
        height = height_a;
    else
        height = height_b;

    i = height;
    while (i > 0)
    {
        if ((height_a >= i) && (height_b >= i))
        {
            printf("\t[%d (i:%d)] chk:%d\t", ptr_a->val, ptr_a->index, ptr_a->chk_id);
            printf("[%d (i:%d)] chk:%d\n", ptr_b->val, ptr_b->index, ptr_b->chk_id);
            // printf("\t[%d (i:%d)] chke:%d chks:%d\t", ptr_a->val, ptr_a->index, ptr_a->chk_end, ptr_a->chk_start);
            // printf("[%d (i:%d)] chke:%d chks:%d\n", ptr_b->val, ptr_b->index, ptr_b->chk_end, ptr_b->chk_start);
            // printf("\t[%d (i:%d)]\t[%d (i:%d)]\n", ptr_a->val, ptr_a->index, ptr_b->val, ptr_b->index);
            // printf("\t%p:[%d (i:%d)]\t%p:[%d (i:%d)]\n", ptr_a, ptr_a->val, ptr_a->index, ptr_b, ptr_b->val, ptr_b->index);
            // printf("\t%p:[%d]\t%p:[%d]\n", ptr_a, ptr_a->val, ptr_b, ptr_b->val);
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }

        if ((height_a >= i) && (height_b < i))
        {
            printf("\t[%d (i:%d)] chk:%d\t   \n", ptr_a->val, ptr_a->index, ptr_a->chk_id);
            // printf("\t[%d (i:%d)] chke:%d chks:%d\t   \n", ptr_a->val, ptr_a->index, ptr_a->chk_end, ptr_a->chk_start);
            // printf("\t[%d (i:%d)]\t   \n", ptr_a->val, ptr_a->index);
            // printf("\t%p:[%d (i:%d)]\t   \n", ptr_a, ptr_a->val, ptr_a->index);
            // printf("\t%p:[%d]\t   \n", ptr_a, ptr_a->val);
            ptr_a = ptr_a->next;
        }

        if ((height_a < i) && (height_b >= i))
        {
            printf("\t\t\t\t[%d (i:%d)] chk:%d\n", ptr_b->val, ptr_b->index, ptr_b->chk_id);
            // printf("\t\t\t\t[%d (i:%d)] chke:%d chks:%d\n", ptr_b->val, ptr_b->index, ptr_b->chk_end, ptr_b->chk_start);
            // printf("\t\t\t\t[%d (i:%d)]\n", ptr_b->val, ptr_b->index);
            // printf("\t\t\t\t%p:[%d (i:%d)]\n", ptr_b, ptr_b->val, ptr_b->index);
            // printf("\t\t\t\t%p:[%d]\n", ptr_b, ptr_b->val);
            ptr_b = ptr_b->next;
        }
        i--;
    }

    return ;
}

/* ************************************************************************** */
void display_size(t_data *d)
{
    // d->a.size = ps_size(d->a.head);
	// d->b.size = ps_size(d->b.head);
	printf("Size\ta:[%d]\t\t\tb:[%d]\n", d->a.size, d->b.size);
}

/* ************************************************************************** */
void display_stack_address(t_data *d)
{
    if((*d).a.head == NULL)
        printf("HEAD_a\t[%p]\t\t\tHEAD_b\t[%p]\n", (*d).a.head, (*d).b.head);
    else
        printf("HEAD_a\t[%p]\tHEAD_b\t[%p]\n", (*d).a.head, (*d).b.head);
    
    if((*d).a.tail == NULL)
        printf("BOT_a\t[%p]\t\t\tBOT_b\t[%p]\n", (*d).a.tail, (*d).b.tail);
    else
        printf("BOT_a\t[%p]\tBOT_b\t[%p]\n", (*d).a.tail, (*d).b.tail);
}

/* ************************************************************************** */