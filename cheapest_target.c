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
//OR if no smaller number: max value
int	find_target(t_list **stack, int num)
{
	t_list	*curr;
//	t_list	*target_node;
	int	target_num;
	int	i;

	//what happens if I return 0 here, better would be an error code
	if (*stack == NULL)
		return (0);
		//what happens if return is NULL
		//return (NULL);
	target_num = check_biggest(*stack);
	curr = (*stack);
	i = 0;
	while (i < target_num)
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
		if (curr->content < num)
		{
//			target = curr;
			target_num = curr->content;
		}
		curr = curr->next;
	}
	return (target_num);
}

//search for the moves that have to been make 
//to push input number on top
//and corresponding target number on top
//on that basis: 
//search for the operations that have to be executed for input number
int	calc_operations(t_list **stack_current, t_list **stack_other, int num)
{
	int	moves_curr;
	int	moves_other;
	int	operations;

	moves_curr = find_index(stack_current, num);
	moves_other = find_index(stack_other, find_target(stack_other, num));
	operations = 0;
//	ft_printf("test_A-1\n");
	if (moves_curr > 0 && moves_other > 0 && num > (ft_lstsize(*stack_current) / 2) && (find_target(stack_other, num) > ft_lstsize(*stack_current)))
	{
		while (moves_curr == 0 || moves_other == 0)
		{
			operations++;
			moves_curr--;
			moves_other--;
		}
		operations = operations + moves_curr + moves_other;
	}
	else if (moves_curr > 0 && moves_other > 0 && num < (ft_lstsize(*stack_current) / 2) && (find_target(stack_other, num) < ft_lstsize(*stack_current)))
	{
		while (moves_curr == 0 || moves_other == 0)
		{
			operations++;
			moves_curr--;
			moves_other--;
		}
		operations = operations + moves_curr + moves_other;
	}
	else
		operations = moves_curr + moves_other;
//	ft_printf("test_A-2\n");
	return (operations);
}

//find number the cheapest target node 
//(commented out: index of the cheapest target node)
int	find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*cheapest;
	
	cheapest = (*stack_b);
	curr = cheapest->next;
//	ft_printf("test_A\n");
	while (curr != NULL)
	{
		
		if (calc_operations(stack_b, stack_a, cheapest->content) > calc_operations(stack_b, stack_a, curr->content))
			cheapest = curr;
		curr = curr->next;
	}
//	return (find_index(stack_b, cheapest->content);
	return (cheapest->content);
}
