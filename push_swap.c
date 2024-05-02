/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:20:19 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/24 12:39:39 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* for testing purpose: valgrind --leak-check=full 
--show-leak-kinds=all --track-origins=yes */

#include "push_swap.h"

//check some arguments are bigger than an integer and free the linked list
int	intmaxcheck(t_list *stack_a, long long value)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		ft_free_ll(&stack_a);
		perror("Error: MAX or MIN INT");
		return (1);
	}
	return (0);
}

//use input arguments and create a linked list (used as stack_a)
//do not return 0 if error, better instead: exit 1?
//free the nodes / linked lists
t_list	*create_stack_a(char **stack_char, size_t size)
{
	size_t	i;
	t_list	*stack_a;

	stack_a = NULL;
	if (input_errorcheck(stack_char) == 1)
		return (0);
	i = 0;
	while (i < (size))
	{
		if (intmaxcheck(stack_a, (long long) ft_atoi(stack_char[i])) == 1)
		{
			ft_free(stack_char);
			return (0);
		}
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(stack_char[i])));
		i++;
	}
	ft_free(stack_char);
	return (stack_a);
}

//with three ints we only have 3*2*1 possibilities to sort the list
//easy and most-efficient to handle these possibilities hard-coded
//less code would produce to first search for biggest number
void	push_3(t_list **stack)
{
	t_list	*stack_1;
	t_list	*stack_2;

	stack_1 = (*stack)->next;
	stack_2 = stack_1->next;
	if (ft_lstsize(*stack) == 2)
	{
		if (check_biggest(*stack) == 1)
			swap_a(stack);
	}
	else if (ft_lstsize(*stack) == 3)
	{
		if (((*stack)->content > stack_1->content) && 
			(stack_1->content > stack_2->content))
		{
			swap_a(stack);
			revrotate_a(stack);
		}
		else if (stack_1->content > stack_2->content)
		{
			revrotate_a(stack);
			stack_1 = (*stack)->next;
		}
		if (((*stack)->content > stack_1->content) && 
			((*stack)->content > stack_2->content))
			rotate_a(stack);
		else if ((*stack)->content > stack_1->content)
			swap_a(stack);
	}
}

int	check_sorted(t_list *stack_a)
{
	t_list	*curr;

	curr = stack_a->next;
	while (stack_a->next != NULL && ((stack_a->content) < (curr->content)))
	{
		stack_a = stack_a->next;
		curr = curr->next;
	}
	if (stack_a->next == NULL)
		return (0);
	return (9);
}

//adapt function for final upload: when deleting testsorting integrate free 
void	push_swap(t_list *stack_a)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	i = ft_lstsize(stack_a);
	if (check_sorted(stack_a) == 0)
	{
		ft_free_ll(&stack_a);
		return ;
	}
	if (i < 4)
		push_3(&stack_a);
	else
	{
		stack_b = sort_average(&stack_a);
		exe_cheapest(&stack_a, &stack_b);
	}
	ft_free_ll(*stack_a);
	ft_free_ll(*stack_a);
	return ;
}
