/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:14:39 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/18 11:30:50 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	count_median(t_list *stack_a)
{
	t_list	*curr;
	int	i;

	i = 0;
	curr = stack_a;
//	ft_printf("hello1a\n");
	while (curr != NULL)
	{
		i += curr->content;
		curr = curr->next;
	}
	if (i == 0 || ft_lstsize(stack_a) == 0)
		return (0);
//	ft_printf("%i\n", i);
//	ft_printf("%i\n", ft_lstsize(stack_a));
//	ft_printf("%i\n", (i / ft_lstsize(stack_a)));
	return (i / ft_lstsize(stack_a));
}

t_list	*sort_median(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*curr;
	int	i;


	i = 0;
	stack_b = NULL;
	curr = *stack_a;
	while (i < ft_lstsize(*stack_a))
	{
//		ft_printf("hello1\n");		
		if (curr->content < count_median(curr))
		{
			push_b(stack_a, &stack_b);
			if (curr->content < count_median(stack_b))
				rotate_b(&stack_b);
			curr = *stack_a;
//			ft_printf("hello11\n");
		}
		else
		{
//			ft_printf("hello22\n");
			rotate_a(stack_a);
			curr = *stack_a;
		}
//		ft_printf("%i\n", curr->content);
		i++;
//		ft_printf("%i\n", curr->next);
	}
	return (stack_b);
}

void	sort_compare_ab(t_list **stack_a, t_list **stack_b)
{
	int	i;
	t_list *curr;
	
	i = 0;
	curr = *stack_a;
	while (i < ft_lstsize(*stack_a))
	{
		if (curr->content < (ft_lstlast(*stack_b))->content)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			curr = *stack_a;
		}
		else
			curr = curr->next;
		i++;
	}
}

void	resort_to_stacka(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	r;
	
	i = 0;
	r = ft_lstsize(*stack_b);
	while (i < r)
	{
		push_a (stack_a, stack_b);
		i++;
	}
}
