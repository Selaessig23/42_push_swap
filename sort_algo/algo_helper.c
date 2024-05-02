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

	//search the index of the smallest int
int    check_smallest(t_list *stack)
{
    t_list  *curr;
    t_list  *small;
    int i;
    int j;
    int k;

	small = stack;
    	curr = small->next;
	i = 0;
	j = 1;
	k = (j - 1);
//	testsorting(&stack, 'b');
	if (stack == NULL || (stack)->next == NULL)
		return (0);
	while (curr)
	{
		if (small->content < curr->content)
		{
			k++;
		}
        	else
		{
			small = curr;
			i = j;
			k++;
		}
		curr = curr->next;
		j++;
	}
//	j = i;
//	ft_printf("highest-Number: %i\n", big->content);
//	ft_printf("Index: %i of %i of %i\n", i, (ft_lstsize(stack)), k);
	return (i);
}

	//search the index of the biggest int
int    check_biggest(t_list *stack)
{
    t_list  *curr;
    t_list  *big;
    int i;
    int j;
    int k;

	big = stack;
    	curr = big->next;
	i = 0;
	j = 1;
	k = (j - 1);
//	testsorting(&stack, 'b');
	if (stack == NULL || (stack)->next == NULL)
		return (0);
	while (curr)
	{
		if (big->content > curr->content)
		{
			k++;
		}
        	else
		{
			big = curr;
			i = j;
			k++;
		}
		curr = curr->next;
		j++;
	}
//	j = i;
//	ft_printf("highest-Number: %i\n", big->content);
//	ft_printf("Index: %i of %i of %i\n", i, (ft_lstsize(stack)), k);
	return (i);
}

//sort according to cheapest way of biggest numbers
//check if the biggest no is on top of stack_b 
//if not: 
//check if the last nuo of stack_b is smaller than 1st of stack_a
//&& 
void	sort_to_a(t_list **stack_a, t_list **stack_b)
{
//	int	m;
	int	s;
	int	i;
	t_list	*curr;

	i = 0;
//	ft_printf("start sort_t-o_a, %i\n", ft_lstsize(*stack_b));
	while (i <= ft_lstsize(*stack_b))
	{
		curr = *stack_b;
//		if ((ft_lstlast(*stack_b)->content > curr->content) && ((*stack_a)->content > (ft_lstlast(*stack_b)->content > curr->content)))
//		if ((ft_lstlast(*stack_b)->content > curr->content) 
//			&& ((*stack_a)->content > curr->content))
//		(((*stack_a)->content < curr->content) 
//			&& (ft_lstlast(*stack_b)->content > curr->content))
//		{
//			revrotate_b(stack_b);
//			push_a (stack_a, stack_b);
//			i--;
//		}
		if (check_biggest(curr) == 0)
			push_a (stack_a, stack_b);
		else
		{
			rotate_b(stack_b);
			i++;
		}
/*
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
//
*/

	}
	s = ft_lstsize(*stack_b);
	while ((ft_lstlast(*stack_b)->content >= curr->content) && ((*stack_a)->content > (ft_lstlast(*stack_b)->content > curr->content)))
	{
			revrotate_b(stack_b);
			push_a (stack_a, stack_b);
	}
//	testsorting(stack_a, 'a');
//	testsorting(stack_b, 'b');
//	while (s)
//	{
//		ft_printf("ups\n");			
//		push_a (stack_a, stack_b);
//		s--;
//	}
//	ft_printf("end sort_t-o_a\n");
}

void	sort_clean_a(t_list **stack_a)
{
	int	m;
	int s;
	int	i;
	t_list	*curr;

	i = ft_lstsize(*stack_a);
	s = 0;
	curr = *stack_a;
//	ft_printf("start sort_clean\n");
	while (i >= 1)
	{
//		ft_printf("biggest: %i // size: %i\n", check_biggest(curr), (ft_lstsize(curr) - 1 - s));
		if ((m = check_biggest(curr)) == (ft_lstsize(curr) - 1 - s))
		{	
//			ft_printf("caseA\n");
			curr = curr->next;
//			s++;
		}
		else if ((m = check_biggest(curr)) > ((s = ft_lstsize(curr)) / 2))
		{
//			ft_printf("caseB\n");
			while (m < (s - 1))
			{
				rotate_a(stack_a);
				m++;
			}
			revrotate_a(stack_a);
			curr = *stack_a;
//			ft_printf("caseA\n");
			//push_a (stack_a, stack_b);
		}
		else
		{
//			ft_printf("caseC\n");
			while (m > 0)
			{
				revrotate_a(stack_a);
				m--;
			}
//			ft_printf("caseB\n");
			//rotate_b(stack_b);
			//push_a (stack_a, stack_b);
			curr = *stack_a;
		}
		i--;
//		testsorting(stack_a, 'a');
//		testsorting(stack_b, 'b');
	}
//	ft_printf("end sort_clean\n");
//	if (check_sorted(*stack_b))
//		push_3(stack_b);
//	push_a(stack_a, stack_b);
//	push_a(stack_a, stack_b);
//	push_a(stack_a, stack_b);
}
