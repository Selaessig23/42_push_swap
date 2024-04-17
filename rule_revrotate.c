/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:05:08 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/17 14:05:45 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//what should happen if list is empty?
static void	ft_revrotate(t_list **list)
{
	t_list	*temp_new_first;
	t_list	*temp_new_end;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp_new_first = ft_lstlast(*list);
//	temp_new_end = ft_lstlast((*list)->next);
	temp_new_end = *list;
	while (temp_new_end->next->next != NULL)
		temp_new_end = temp_new_end->next;
	temp_new_end->next = NULL;
	temp_new_first->next = *list;
	*list = temp_new_first;
}

void	revrotate_a(t_list **stack_a)
{
	ft_revrotate(stack_a);
	ft_printf("rra\n");
}

void	revrotate_b(t_list **stack_b)
{
	ft_revrotate(stack_b);
	ft_printf("rrb\n");
}

void	revrotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
	ft_printf("rrr\n");
}
