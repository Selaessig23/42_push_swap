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

//execute operations according to cheapest target node
void	exe_oper(t_list **stack_a, t_list **stack_b)
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
