/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:16:14 by mstracke          #+#    #+#             */
/*   Updated: 2024/03/19 15:35:31 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
	return (c);
}

void	swap_a(int *stack_a)
{
	ft_swap (&stack_a[0], &stack_a[1]);
	ft_printf("sa\n");
}

void	swap_b(int *stack_b)
{
	ft_swap (&stack_b[0], &stack_b[1]);
	ft_printf("sb\n");
}

void	swap_ab(int *stack_a, int *stack_b)
{
	ft_swap (&stack_a[0], &stack_a[1]);
	ft_swap (&stack_b[0], &stack_b[1]);
	ft_printf("ss\n");
}
