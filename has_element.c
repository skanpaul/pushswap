/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
bool has_0_elem_only(t_ps **stack)
{
    t_ps *elem_1;

    if (stack == NULL)
        return (true);
        
    elem_1 = *stack;
    if (elem_1 == NULL)
        return (true);

    return (false);
}

/* ************************************************************************** */
bool has_1_elem_only(t_ps **stack)
{
    t_ps    *elem_1;
  
    if (stack == NULL)
        return (false);
    
    elem_1 = *stack;
    if ((elem_1 != NULL) && (elem_1->next == NULL))
        return (true);

     return (false);
}

/* ************************************************************************** */
bool has_2_elem_only(t_ps **stack)
{
    t_ps    *elem_1;
    t_ps    *elem_2;
  
    if(stack == NULL)
        return (false);
    
    if (has_1_elem_only(stack))
        return false;

    elem_1 = *stack;
    elem_2 = elem_1->next;

    if ((elem_2 != NULL) && (elem_2->next == NULL))
        return (true);

     return (false);
}

/* ************************************************************************** */
bool has_2_elem_or_more(t_ps **stack)
{
    t_ps *top_elem;

    if(stack == NULL)
        return (false);

    top_elem = *stack;
    if (top_elem == NULL)
        return (false);

    if (top_elem->next == NULL)
        return (false);

    return (true);
}

/* ************************************************************************** */
bool has_1_elem_or_more(t_ps **stack)
{
    t_ps *top_elem;

    if(stack == NULL)
        return (false);
        
    top_elem = *stack;
    if (top_elem == NULL)
        return (false);

    return (true);
}



/* ************************************************************************** */
bool has_less_than_2_elem(t_ps *top_elem)
{
    t_ps *elem;
	t_ps *next_elem;

	/* test si 0 ou 1 element --> pas besoin de controller */
	elem = top_elem;
	if (elem == NULL)
		return (true);
	next_elem = elem->next;
	if (next_elem == NULL)
		return (true);
    
    return (false);
}