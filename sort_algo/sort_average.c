/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:14:39 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/24 13:01:29 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//calculate the average of a list
float	count_average(t_list *stack)
{
	t_list	*curr;
	size_t	i;

	i = 0;
	curr = stack;
	while (curr != NULL)
	{
		i += curr->content;
		curr = curr->next;
	}
	if (i == 0 || ft_lstsize(stack) == 0)
		return (0);
	return (i / ft_lstsize(stack));
}

//sort list (minus 3 elements) according to average:
//lower > push to stack_b 
//(here again check if > | < average, place at beginning or rotate to end)
//bigger > rotate to end (to get highest numbers for beeing left) 
t_list	*sort_average(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*curr;

	stack_b = NULL;
	curr = *stack_a;
	while (ft_lstsize(curr) > 3)
	{
		if (curr->content < count_average(curr))
		{
			push_b(stack_a, &stack_b);
			if (stack_b->content < count_average(stack_b))
				rotate_b(&stack_b);
			curr = *stack_a;
		}
		else
		{
			rotate_a(stack_a);
			curr = *stack_a;
		}
	}
	push_3(stack_a);
	return (stack_b);
}
