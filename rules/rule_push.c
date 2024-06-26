/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:42:30 by mstracke          #+#    #+#             */
/*   Updated: 2024/03/19 16:43:00 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION: */
/* pa (push a): Take the first element at the */
/* top of b and put it at the top of a. */
/* Do nothing if b is empty. */
/* pb (push b): Take the first element at the */
/* top of a and put it at the top of b. */
/* Do nothing if a is empty */
#include "../push_swap.h"

static void	ft_push(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp_2;

	if (*stack_2 == NULL)
		return ;
	temp_2 = *stack_2;
	*stack_2 = (*stack_2)->next;
	temp_2->next = *stack_1;
	*stack_1 = temp_2;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}
