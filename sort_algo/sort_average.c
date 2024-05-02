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
	int		i;

	i = 0;
	//necessary?
	if (stack == NULL || stack->next == NULL)
		return (1);
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

	//necessary?
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (NULL);
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
/*
//sort according to cheapest way of biggest numbers
void	sort_biggest(t_list **stack_a, t_list **stack_b)
{
	int	m;
	int s;
	int	i;
	t_list	*curr;

	i = ft_lstsize(*stack_b);
	while (i >= 1)
	{
		curr = *stack_b;
		if ((m = check_biggest(curr)) > ((s = ft_lstsize(curr)) / 2))
		{
			while (m < (s - 1))
			{
				revrotate_b(stack_b);
				m++;
			}
			revrotate_b(stack_b);
//			ft_printf("caseA\n");
			push_a (stack_a, stack_b);
		}
		else
		{
			while (m > 0)
			{
				rotate_b(stack_b);
				m--;
			}
//			ft_printf("caseB\n");
			//rotate_b(stack_b);
			push_a (stack_a, stack_b);
		}
		i--;
//		testsorting(stack_a, 'a');
//		testsorting(stack_b, 'b');
	}
//	if (check_sorted(*stack_b))
//		push_3(stack_b);
//	push_a(stack_a, stack_b);
//	push_a(stack_a, stack_b);
//	push_a(stack_a, stack_b);
}

//check for easiest way to resort to a
//if b[i] < a[i] -> push_a
//if b[i] > a[i] && b[0] > a[last] -> push_a & rotate_a
//else -> curr->next
void	sort_compare_ab(t_list **stack_a, t_list **stack_b)
{
	int	i;
	t_list *curr;
	
	i = ft_lstsize(*stack_b);
	curr = ft_lstlast(*stack_b);
//	while (i < ft_lstsize(*stack_b))
//	while (i <= 4)
	ft_printf("%i\n", i);
	while (i > 0)
	{
//		if (ft_lstsize(*stack_b) == 3)
//		{
//			printf("case 0\n");
//			push_3(stack_b);
//			sort_compare_ab(stack_a, stack_b);
//		}
		curr = ft_lstlast(*stack_b);
		if (((*stack_a)->content) > curr->content)
		{
			printf("case a\n");
			push_a(stack_a, stack_b);
		}
		else if (((*stack_a)->content) > (curr->content) && 
			(curr->content > (ft_lstlast(*stack_a))->content))
		{
			printf("case b\n");
			push_a(stack_a, stack_b);
			rotate_b(stack_b);
//			curr = ft_lstlast(*stack_b);
		}
		else if (((*stack_a)->content) < (ft_lstlast(*stack_b))->content)
			push_b(stack_a, stack_b);
		else
		{
			printf("case c\n");
			revrotate_b(stack_b);
//			curr = ft_lstlast(*stack_b);
		}
		i--;
	}

}
	
void	resort_to_stacka(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	r;
	
	i = 0;
	if (*stack_b == NULL)
		return ;
	r = ft_lstsize(*stack_b);
	while (i < r)
	{
//		printf("faulty b\n");
		push_a (stack_a, stack_b);
		i++;
	}
}

void	check_swap(t_list **stack)
{
	t_list	*curr;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	curr = (*stack)->next;
	while ((*stack) != NULL && (((*stack)->content) < (curr->content)))
	{
		*stack = (*stack)->next;
		curr = curr->next;
	}
//	ft_printf("test1: %i\n", stack_a->next);
	if ((*stack)->next != NULL)
	{
//		perror("Already sorted: delete message and return "
//		"(0) before closing poject");
//		return (1);
		swap_a(stack);
	}
}
*/
