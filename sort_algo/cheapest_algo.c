/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:17:17 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/26 22:47:12 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//mearly same function as count_t_operations (to simple count operations)
//on basis of the moves of the cheapest: 
//search for smallest no of operations that have to be executed for input number
//(==cheapest) and redirect to execution
//be careful! stack_a and stack_b have a different orden
//(stack_a from smallest to biggest and stack_b from biggest to smallest)
void	exe_t_operations(t_list **stack_current, t_list **stack_other, int num)
{
	int	moves_curr;
	int	moves_other;

	moves_curr = calc_moves(stack_current, num);
	moves_other = calc_moves(stack_other, find_target(stack_other, num));
	if ((moves_curr > 0) && (moves_other > 0) 
		&& (find_index(stack_other, find_target(stack_other, num)) 
			< (ft_lstsize(*stack_other) / 2)) 
		&& (find_index(stack_current, num) 
			< (ft_lstsize(*stack_current) / 2)))
		exe_operations_up(stack_current, stack_other, num);
	else if ((moves_curr > 0) && (moves_other > 0) 
		&& (find_index(stack_other, find_target(stack_other, num)) 
			> (ft_lstsize(*stack_other) / 2)) 
		&& (find_index(stack_current, num) 
			> (ft_lstsize(*stack_current) / 2)))
		exe_operations_down(stack_current, stack_other, num);
	else
		exe_operations_single(stack_current, stack_other, num);
}

//be careful! stack_a and stack_b have a different orden
//(stack_a from smallest to biggest and stack_b from biggest to smallest)
void	exe_operations_single(t_list **stack_current, 
		t_list **stack_other, int num)
{
	int	moves_curr;
	int	moves_other;

	moves_curr = calc_moves(stack_current, num);
	moves_other = calc_moves(stack_other, find_target(stack_other, num));
	while (moves_curr > 0)
	{
		if (find_index(stack_current, num) <= 
			(ft_lstsize(*stack_current) / 2))
			rotate_b(stack_current);
		else
			revrotate_b(stack_current);
		moves_curr = moves_curr - 1;
	}
	while (moves_other > 0)
	{
		if (find_index(stack_other, find_target(stack_other, num)) 
			<= (ft_lstsize(*stack_other) / 2))
			rotate_a(stack_other);
		else
			revrotate_a(stack_other);
		moves_other = moves_other - 1;
	}
}

void	exe_operations_down(t_list **stack_curr, t_list **stack_oth, int num)
{
	int	moves_curr;
	int	moves_other;

	moves_curr = calc_moves(stack_curr, num);
	moves_other = calc_moves(stack_oth, find_target(stack_oth, num));
	while (moves_curr != 0 && moves_other != 0)
	{
		revrotate_ab(stack_curr, stack_oth);
		moves_curr = moves_curr - 1;
		moves_other = moves_other - 1;
	}
	if (moves_curr != 0 || moves_other != 0)
		exe_operations_single(stack_curr, stack_oth, num);
}

void	exe_operations_up(t_list **stack_current, t_list **stack_other, int num)
{
	int	moves_curr;
	int	moves_other;

	moves_curr = calc_moves(stack_current, num);
	moves_other = calc_moves(stack_other, find_target(stack_other, num));
	while (moves_curr != 0 && moves_other != 0)
	{
		rotate_ab(stack_current, stack_other);
		moves_curr = moves_curr - 1;
		moves_other = moves_other - 1;
	}
	if (moves_curr != 0 || moves_other != 0)
		exe_operations_single(stack_current, stack_other, num);
}

void	exe_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		cheapest;

	while ((*stack_b) != NULL)
	{
		cheapest = find_cheapest(stack_a, stack_b);
		exe_t_operations(stack_b, stack_a, cheapest);
		push_a(stack_a, stack_b);
	}
	while (check_smallest(*stack_a))
	{
		if (check_smallest(*stack_a) > (ft_lstsize(*stack_a) / 2))
			revrotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}
