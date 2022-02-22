/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* PUSH the stack from the top to the bottom ******************************** */
/* ************************************************************************** */
void rev_rot(t_ps **stack, t_ps **stack_bottom)
{
	t_ps *extracted_elem;

	if ((!stack) || (!has_2_elem_or_more(stack)))
		return ;

	if (has_2_elem_only(stack))
		swap(stack, stack_bottom);
	else
	{
		extracted_elem = ps_rem_elem_from_bottom(stack, stack_bottom);
		ps_add_elem_to_top(extracted_elem, stack, stack_bottom);		
	}
	return ;
}

/* ************************************************************************** */
void	rev_rot_a(t_data *d)
{
    rev_rot(&d->head_a, &d->tail_a);    
	printf("RRA\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
void	rev_rot_b(t_data *d)
{
    rev_rot(&d->head_b, &d->tail_b);
	printf("RRB\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
void	rev_rot_2(t_data *d)
{
    rev_rot(&d->head_a, &d->tail_a);    
    rev_rot(&d->head_b, &d->tail_b);
	printf("RRR\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
/* rra : reverse rotate a - shift down all elements of stack a by 1.          */
/* The last element becomes the first one.                                    */
/* ************************************************************************** */
/* rrb : reverse rotate b- shift down all elements of stack b by 1.           */
/* The last element becomes the first one.                                    */
/* ************************************************************************** */
/* rrr : rra and rrb at the same time.                                        */
/* ************************************************************************** */


// /* ************************************************************************** */
// /* PUSH the stack from the top to the bottom ******************************** */
// /* ************************************************************************** */
// void rev_rot(t_ps **ptr_top)
// {
// 	t_ps *top_elem;
//     t_ps *before_last_elem;   
//     t_ps *bot_elem;
	
// 	if ((ptr_top == NULL) || (*ptr_top == NULL) || ((*ptr_top)->next == NULL))
//         return ;

//     top_elem = *ptr_top;
//     bot_elem = ps_get_last_elem(ptr_top);
//     before_last_elem = bot_elem->prev;

//     *ptr_top = bot_elem;
//     bot_elem->prev = NULL;
//     bot_elem->next = top_elem;

//     top_elem->prev = bot_elem;
//     before_last_elem->next = NULL;

// 	return ; 
// }

// /* ************************************************************************** */
// void	rev_rot_a(t_data *d)
// {
//     rev_rot(&d->head_a);    
// 	printf("RRA\n");
//     return ;
// }

// /* ************************************************************************** */
// void	rev_rot_b(t_data *d)
// {
//     rev_rot(&d->head_b);
// 	printf("RRB\n");
//     return ;
// }

// /* ************************************************************************** */
// void	rev_rot_2(t_data *d)
// {
//     rev_rot(&d->head_a);
//     rev_rot(&d->head_b);
// 	printf("RRR\n");
//     return ;
// }
