/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:01:25 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/26 21:47:32 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//helper function to find_target

//check for target: closest small number in other stack
//OR if no smaller number: (max) min value
//what happens if I return 0 here, better would be an error code
//	if (*stack == NULL)
//		return (0);
int	find_target(t_list **stack, int num)
{
	t_list	*curr;
	int		target_num;

	target_num = find_number((*stack), check_smallest(*stack));
	curr = (*stack);
	while (curr)
	{
		if (curr->content > num)
		{
			target_num = curr->content;
			while (curr)
			{
				if (curr->content > num && curr->content < target_num)
					target_num = curr->content;
				curr = curr->next;
			}
			break ;
		}
		curr = curr->next;
	}
	return (target_num);
}

//helper variable to calculate the number of moves
//to bring number and his target on top (equal to index)
//consider median(!) as it is allowed to rotate up AND down
int	calc_moves(t_list **stack, int num)
{
	int	moves;

	moves = find_index(stack, num);
	if (moves > (ft_lstsize(*stack) / 2))
		moves = ft_lstsize(*stack) - moves;
	return (moves);
}

//helper variable to calculate the number of operations
//for target_operations
static int	calc_operations(int *moves_curr, int *moves_other)
{
	int	operations; 

	operations = 0;
	while (*moves_curr != 0 && *moves_other != 0)
	{
		operations++;
		*moves_curr = *moves_curr - 1;
		*moves_other = *moves_other - 1;
	}
	operations = operations + *moves_curr + *moves_other;
	return (operations);
}

//search for the moves that have to been make 
//to push input number on top
//and corresponding target number on top
//(==index of both numbers)
//on that basis: 
//search for the operations that have to be executed for input number
//be careful! stack_a and stack_b have a different orden
//(stack_a from smallest to biggest and stack_b from biggest to smallest)
int	count_t_operations(t_list **stack_current, t_list **stack_other, int num)
{
	int	moves_curr;
	int	moves_other;
	int	operations;

	moves_curr = calc_moves(stack_current, num);
	moves_other = calc_moves(stack_other, find_target(stack_other, num));
	operations = 0;
	if ((moves_curr > 0) && (moves_other > 0) 
		&& (find_index(stack_other, find_target(stack_other, num)) 
			< (ft_lstsize(*stack_other) / 2)) 
		&& (find_index(stack_current, num) 
			< (ft_lstsize(*stack_current) / 2)))
		operations = calc_operations(&moves_curr, &moves_other);
	else if ((moves_curr > 0) && (moves_other > 0) 
		&& (find_index(stack_other, find_target(stack_other, num)) 
			> (ft_lstsize(*stack_other) / 2)) 
		&& (find_index(stack_current, num) 
			> (ft_lstsize(*stack_current) / 2)))
		operations = calc_operations(&moves_curr, &moves_other);
	else
		operations = moves_curr + moves_other;
	return (operations);
}

//find number of the cheapest target node 
int	find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*cheapest;

	cheapest = (*stack_b);
	curr = cheapest->next;
	while (curr != NULL)
	{
		if (count_t_operations(stack_b, stack_a, cheapest->content) 
			> count_t_operations(stack_b, stack_a, curr->content))
			cheapest = curr;
		curr = curr->next;
	}
	return (cheapest->content);
}
