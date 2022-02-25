/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:21:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 15:21:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void printf_red() 
{
  printf("\033[1;31m");
}

/* ************************************************************************** */
void printf_yellow()
{
  printf("\033[1;33m");
}

/* ************************************************************************** */
void printf_reset () 
{
  printf("\033[0m");
}

/* ************************************************************************** */
