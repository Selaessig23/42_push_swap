/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:56:00 by mstracke          #+#    #+#             */
/*   Updated: 2024/05/02 10:03:14 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//only for testing reasons
//free the nodes / linked lists --> comment out for testing reasons
//	testsorting(&stack_a, 'a');
//	testsorting(&stack_b, 'b');
void	testsorting(t_list **stack, char c)
{
	t_list	*curr;
	t_list	*temp;
	int		i;

	curr = *stack;
	i = 0;
	c = 12;
	while (curr != NULL)
	{
		temp = curr;
//		ft_printf("stack_%c[%d]: $%d$\n", c, i, curr->content);
		curr = curr->next;
		free(temp);
		i++;
	}
	stack = NULL;
}


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
