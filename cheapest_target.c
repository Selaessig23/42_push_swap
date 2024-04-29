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

#include "push_swap.h"

//calculate index of certain number
int	find_index(t_list **stack, int num)
{
	t_list	*curr;
	int	index;
	
	//what happens if I return 0 here, better would be an error code
	if (*stack == NULL)
		return (0);
	curr = (*stack);
	index = 0;
	while (curr && (curr->content != num))
	{
		index++;
		curr = curr->next;
	}
	return (index);
}

//check if you need a target node (currently commented out)
//or better use int
//check for target: closest small number in other stack
//OR if no smaller number: (max) min value 
int	find_target(t_list **stack, int num)
{
	t_list	*curr;
//	t_list	*target_node;
	int	target_num;
	int	target_index;
	int	i;

	//what happens if I return 0 here, better would be an error code
	if (*stack == NULL)
		return (0);
		//what happens if return is NULL
		//return (NULL);
	target_index = check_smallest(*stack);
//	target_num = check_biggest(*stack);
	curr = (*stack);
	i = 0;
	while (i < target_index)
	{
		curr = curr->next;
		i++;
	}
//	target_node = curr;
	target_num = curr->content;
//	ft_printf("test\n");
	curr = (*stack);
	while (curr)
	{
//		if (curr->content < num)
		if (curr->content > num)
		{
//			target = curr;
			target_num = curr->content;
			while (curr)
			{
				if (curr->content > num && curr->content < target_num)
//				if (curr->content < num && curr->content > target_num)
					target_num = curr->content;
				curr = curr->next;					
			}
			break ;
		}
		curr = curr->next;
	}
	return (target_num);
}

//helper variable to calculate the number of operations
//for target_operations
static int	calc_operations(int *moves_curr, int *moves_other)
{
	int	operations; 
	
	operations = 0;
	while (*moves_curr == 0 || *moves_other == 0)
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
//on that basis: 
//search for the operations that have to be executed for input number
//be careful! stack_a and stack_b have a different orden
//(stack_a from smallest to biggest and stack_b from biggest to smallest)
int	target_operations(t_list **stack_current, t_list **stack_other, int num, bool exe)
{
	int	moves_curr;
	int	moves_other;
	int	operations;
	
	//check how many moves are necessary, 
	//consider median(!) as it is allowed to rotate up AND down
	moves_curr = find_index(stack_current, num);
	if (moves_curr > (ft_lstsize(*stack_current) / 2))
		moves_curr = ft_lstsize(*stack_current) - moves_curr;
	moves_other = find_index(stack_other, find_target(stack_other, num));
	if (moves_other > (ft_lstsize(*stack_other) / 2))
		moves_other = ft_lstsize(*stack_other) - moves_other;
	operations = 0;
//	ft_printf("test_A-1\n");
//	if ((moves_curr > 0) && (moves_other > 0) && (num > count_average(*stack_current)) && (find_target(stack_other, num) > count_average(*stack_other)))
	if ((moves_curr > 0) && (moves_other > 0) && (find_index(stack_other, find_target(stack_other, num)) < (ft_lstsize(*stack_other) / 2)) && (find_index(stack_current, num) > (ft_lstsize(*stack_current) / 2)))
	
	{
		if (exe == false)
			operations = calc_operations(&moves_curr, &moves_other);
		else
			exe_operations_up(stack_current, stack_other, &moves_curr, &moves_other, num);
//		while (moves_curr == 0 || moves_other == 0)
//		{
//			operations++;
//			moves_curr--;
//			moves_other--;
//		}
//		operations = operations + moves_curr + moves_other;
	}
//	else if ((moves_curr > 0 && moves_other > 0 && num < count_average(*stack_current)) && (find_target(stack_other, num) < count_average(*stack_other)))
	else if ((moves_curr > 0) && (moves_other > 0) && (find_index(stack_other, find_target(stack_other, num)) > (ft_lstsize(*stack_other) / 2)) && (find_index(stack_current, num) < (ft_lstsize(*stack_current) / 2)))
	{
		if (exe == false)
			operations = calc_operations(&moves_curr, &moves_other);
//		while (moves_curr == 0 || moves_other == 0)
//		{
//			operations++;
//			moves_curr--;
//			moves_other--;
//		}
//		operations = operations + moves_curr + moves_other;
		else
			exe_operations_down(stack_current, stack_other, &moves_curr, &moves_other, num);
	}
	else
	{
		if (exe == false)
			operations = moves_curr + moves_other;
		else
		{
			ft_printf("Curr moves: %i, other moves: %i\n", moves_curr, moves_other);
			exe_operations_single(stack_current, stack_other, &moves_curr, &moves_other, num);
			
		}
	}
//	ft_printf("test_A-2\n");
	return (operations);
}

//find number of the cheapest target node 
//(commented out: index of the cheapest target node)
int	find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*cheapest;
	bool	exe;
	
	exe = false;
	cheapest = (*stack_b);
	curr = cheapest->next;
//	ft_printf("test_A\n");
	while (curr != NULL)
	{
		cheapest = (*stack_b);
		if (target_operations(stack_b, stack_a, cheapest->content, exe) > target_operations(stack_b, stack_a, curr->content, exe))
			cheapest = curr;
		curr = curr->next;
	}
//	return (find_index(stack_b, cheapest->content);
	return (cheapest->content);
}
