/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:43:49 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/17 18:11:26 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION: 
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time. */
#include "../push_swap.h"

//what should happen if list is empty?
static void	ft_rotate(t_list **list)
{
	t_list	*temp1;
	t_list	*temp_end;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp1 = *list;
	*list = temp1->next;
	temp_end = ft_lstlast(*list);
	temp_end->next = temp1;
	temp1->next = NULL;
}

void	rotate_a(t_list **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
