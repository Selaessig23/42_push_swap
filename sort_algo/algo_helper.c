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

//calculate index of a certain number
//if stack = NULLthe return is 0, better would be an error code???
//	if (*stack == NULL)
//		return (1);
int	find_index(t_list **stack, int num)
{
	t_list	*curr;
	int		index;

	curr = (*stack);
	index = 0;
	while (curr && (curr->content != num))
	{
		index++;
		curr = curr->next;
	}
	return (index);
}

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
int	check_biggest(t_list *stack)
{
	t_list	*curr;
	t_list	*big;
	int		i;
	int		j;

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

//find the number of a specifiic index on the stack
int	find_number(t_list *stack, int index)
{
	int	num;

	num = 0;
	while (num < index)
	{
		stack = stack->next;
		num++;
	}
	num = stack->content;
	return (num);
}
