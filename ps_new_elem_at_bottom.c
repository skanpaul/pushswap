/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new_elem_at_bottom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:05:33 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:05:38 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
// void	ps_new_elem_at_bottom(int val, t_ps **stack, t_ps **stack_bottom)
void	ps_new_elem_at_bottom(int val, t_data *d, int stk_id)
{
	t_ps	*new;

	new = ps_new_elem(val);
	ps_add_elem_to_bottom(new, d, STACK_A);
}
