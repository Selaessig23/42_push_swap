/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:31:06 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/24 13:00:19 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//search the index of the smallest int
int	check_smallest(t_list *stack)
{
	t_list	*curr;
	t_list	*small;
	int		i;
	int		j;

	small = stack;
	curr = small->next;
	i = 0;
	j = 1;
	if (stack == NULL || (stack)->next == NULL)
		return (0);
	while (curr)
	{
		if (small->content >= curr->content)
		{
			small = curr;
			i = j;
		}
		curr = curr->next;
		j++;
	}
	return (i);
}

//search the index of the biggest int
int    check_biggest(t_list *stack)
{
    t_list  *curr;
    t_list  *big;
    int i;
    int j;

	big = stack;
    	curr = big->next;
	i = 0;
	j = 1;
	if (stack == NULL || (stack)->next == NULL)
		return (0);
	while (curr)
	{
		if (big->content <= curr->content)
		{
			big = curr;
			i = j;
		}
		curr = curr->next;
		j++;
	}
	return (i);
}
