/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* PULL the stack from the bottom to the top ******************************** */
/* ************************************************************************** */
void rotate(t_ps **stack, t_ps **stack_bottom)
{
	t_ps *extracted_elem;

	if ((!stack) || (!has_2_elem_or_more(stack)))
		return ;

	if (has_2_elem_only(stack))
		swap(stack, stack_bottom);
	else
	{
		extracted_elem = ps_rem_elem_from_top(stack, stack_bottom);
		ps_add_elem_to_bottom(extracted_elem, stack, stack_bottom);		
	}
	return ; 
}

/* ************************************************************************** */
void	rotate_a(t_data *d)
{
	rotate(&d->head_a, &d->tail_a);
	printf("ra\n");
	d->cnt_cmd++;
	display(d);
	return ;
}
/* ************************************************************************** */
void	rotate_b(t_data *d)
{
	rotate(&d->head_b, &d->tail_b);
	printf("rb\n");
	d->cnt_cmd++;
	display(d);
	return ;
}
/* ************************************************************************** */
void	rotate_2(t_data *d)
{
	rotate(&d->head_a, &d->tail_a);
	rotate(&d->head_b, &d->tail_b);
	printf("rr\n");
	d->cnt_cmd++;
	display(d);
	return ;
}

/* ************************************************************************** */
/* ra : rotate a - shift up all elements of stack a by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rb : rotate b - shift up all elements of stack b by 1.                     */
/* The first element becomes the last one.                                    */
/* ************************************************************************** */
/* rr : ra and rb at the same time.                                           */
/* ************************************************************************** */


// /* ************************************************************************** */
// /* PULL the stack from the bottom to the top ******************************** */
// /* ************************************************************************** */
// void rotate(t_ps **ptr_top)
// {
// 	t_ps *top_elem;
// 	t_ps *sec_elem;
//     t_ps *bot_elem;
	
// 	if ((ptr_top == NULL) || (*ptr_top == NULL) || ((*ptr_top)->next == NULL))
//         return ;

// 	top_elem = *ptr_top;
// 	sec_elem = top_elem->next;
// 	bot_elem = ps_get_last_elem(ptr_top);

// 	*ptr_top = sec_elem;
// 	sec_elem->prev = NULL;

// 	bot_elem->next = top_elem;
// 	top_elem->prev = bot_elem;
// 	top_elem->next = NULL;

// 	return ; 
// }

// /* ************************************************************************** */
// void	rotate_a(t_data *d)
// {
// 	rotate(&d->head_a);
// 	printf("RA\n");
// 	return ;
// }
// /* ************************************************************************** */
// void	rotate_b(t_data *d)
// {
// 	rotate(&d->head_b);
// 	printf("RB\n");
// 	return ;
// }
// /* ************************************************************************** */
// void	rotate_2(t_data *d)
// {
// 	rotate(&d->head_a);
// 	rotate(&d->head_b);
// 	printf("RR\n");
// 	return ;
// }
