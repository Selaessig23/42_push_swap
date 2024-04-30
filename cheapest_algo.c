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

#include "push_swap.h"

/*
//for testing reasons: cheapest target node
static void	test_oper(t_list **stack_a, t_list **stack_b)
{
	int	index_cheapest;
	int	index_target;

//	ft_printf("test1\n");
	index_cheapest = find_index(stack_b, find_cheapest(stack_a, stack_b));
//	ft_printf("test2\n");
	index_target = find_index(stack_a, find_target(stack_a, find_cheapest(stack_a, stack_b)));
//	if (index_cheapest > 0 && index_target > 0 && num > (ft_lstsize(stack_current) / 2) 
//		&& (find_target(stack_other, num) > ft_lstsize(stack_current)))
	ft_printf("cheapest: %i\n", find_cheapest(stack_a, stack_b));
	ft_printf("target: %i\n", find_target(stack_a, find_cheapest(stack_a, stack_b)));
}
*/

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

void	exe_operations_down(t_list **stack_current, t_list **stack_other, int num)
{
	int	moves_curr;
	int	moves_other;

	moves_curr = calc_moves(stack_current, num);
	moves_other = calc_moves(stack_other, find_target(stack_other, num));
	while (moves_curr != 0 && moves_other != 0)
	{
		revrotate_ab(stack_current, stack_other);
		moves_curr = moves_curr - 1;
		moves_other = moves_other - 1;
	}
	if (moves_curr != 0 || moves_other != 0)
		exe_operations_single(stack_current, stack_other, num);
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
	bool	exe;
	int		cheapest;

	exe = true;
	while ((*stack_b) != NULL)
	{
		cheapest = find_cheapest(stack_a, stack_b);
		target_operations(stack_b, stack_a, cheapest, exe);
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
