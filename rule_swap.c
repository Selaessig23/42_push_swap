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

//maybe change error handling to 0, so that algorithm can run although one stack is empty
static void	ft_swap(t_list **list)
{
	t_list	*temp_0;
	t_list	*temp_1;
	
	if (*list == NULL || (*list)->next == NULL)
		return ; 
	temp_0 = *list;
	temp_1 = temp_0->next;
	temp_0->next = temp_1->next;
	temp_1->next = temp_0;
	*list = temp_1;
//	t_list	*temp;
//	t_list	*d;
//	c->content = NULL;
//	temp = a;
//	a->next = b->next;
//	b->next = a;
//	temp = b;
//	a->content = b->content;
//	*a = *b;
//	*a->next = c;
//	c->next = d->next;
}

void	swap_a(t_list **stack_a)
{
	ft_swap (stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	ft_swap (stack_b);
	ft_printf("sb\n");
}

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	ft_swap (stack_a);
	ft_swap (stack_b);
	ft_printf("ss\n");
}
