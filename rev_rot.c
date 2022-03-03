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
void rev_rot(t_stk *stk)
{
	t_ps *extracted_elem;

	if ((!stk) || (!has_2_elem_or_more(&stk->head)))
		return ;

	if (has_2_elem_only(&stk->head))
		swap(stk);
	else
	{
		extracted_elem = ps_rem_elem_from_bottom(stk);
		ps_add_elem_to_top(extracted_elem, stk);		
	}
	return ;
}

/* ************************************************************************** */
void	rev_rot_a(t_data *d)
{
    rev_rot(&d->a);
	printf("rra\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
void	rev_rot_b(t_data *d)
{
    rev_rot(&d->b);
	printf("rrb\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
void	rev_rot_2(t_data *d)
{
    rev_rot(&d->a); 
    rev_rot(&d->b);
	printf("rrr\n");
	d->cnt_cmd++;
	display(d);
    return ;
}

/* ************************************************************************** */
void	rev_rot_a_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rev_rot_a(d);
		loop--;
	}
}
/* ************************************************************************** */
void	rev_rot_b_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rev_rot_b(d);
		loop--;
	}
}
/* ************************************************************************** */
void	rev_rot_2_loop(t_data *d, int loop)
{
	while (loop > 0)
	{
		rev_rot_2(d);
		loop--;
	}
}

// /* ************************************************************************** */
// /* PUSH the stack from the top to the bottom ******************************** */
// /* ************************************************************************** */
// void rev_rot(t_ps **stack, t_ps **stack_bottom)
// {
// 	t_ps *extracted_elem;

// 	if ((!stack) || (!has_2_elem_or_more(stack)))
// 		return ;

// 	if (has_2_elem_only(stack))
// 		swap(stack, stack_bottom);
// 	else
// 	{
// 		extracted_elem = ps_rem_elem_from_bottom(stack, stack_bottom);
// 		ps_add_elem_to_top(extracted_elem, stack, stack_bottom);		
// 	}
// 	return ;
// }

// /* ************************************************************************** */
// void	rev_rot_a(t_data *d)
// {
//     rev_rot(&d->a.head, &d->a.tail);
// 	printf("rra\n");
// 	d->cnt_cmd++;
// 	display(d);
//     return ;
// }

// /* ************************************************************************** */
// void	rev_rot_b(t_data *d)
// {
//     rev_rot(&d->b.head, &d->b.tail);
// 	printf("rrb\n");
// 	d->cnt_cmd++;
// 	display(d);
//     return ;
// }

// /* ************************************************************************** */
// void	rev_rot_2(t_data *d)
// {
//     rev_rot(&d->a.head, &d->a.tail); 
//     rev_rot(&d->b.head, &d->b.tail);
// 	printf("rrr\n");
// 	d->cnt_cmd++;
// 	display(d);
//     return ;
// }

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
