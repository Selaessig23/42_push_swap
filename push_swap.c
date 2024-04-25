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
/* open: 
> [solved]in function check_dupli change strncmp to 
	strcmp or adapt n (status quo: if str a < str b == problem)
> [solved] INPUT: define what should happen if strings and int are mixed
> [solved] INPUT: give error message when signs are used twice or multiple times
> [solved] INPUT: how to handle numbers bigger than int?
> [solved] INPUT: what happens if input = ./push_swap -0 0
> [solved] free the nodes / linked lists
> improve the code by integrating ft_lstlast and clean the code of libft_bonus
> [solved] write RULES with linked lists?
> find algorithm
> test with ./push_swap 7 9 6 5 20 14 55 66 32 1
*/

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
static t_list	*create_stack_a(char **stack_char, size_t size)
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

	//only for testing reasons
	//free the nodes / linked lists --> commented out for testing reasons
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

//with three ints we only have 3*2*1 possibilities to sort the list
//easy and most-efficient to handle hard-coded
//less code would produce to first search for biggest number
void	push_3(t_list **stack)
{
	t_list	*stack_1;
	t_list	*stack_2;
	
	stack_1 = (*stack)->next;
	stack_2 = stack_1->next;
	if (ft_lstsize(*stack) == 2)
	{
//		ft_printf("te\n");
		if (check_biggest(*stack) == 1)
			swap_a(stack);
	}
	else if (ft_lstsize(*stack) == 3)
	{//	ft_printf("push3\n");
		if (((*stack)->content > stack_1->content) && (stack_1->content > stack_2->content))
		{
	//		ft_printf("case1A\n");
			swap_a(stack);
			revrotate_a(stack);
		}
		else if (stack_1->content > stack_2->content)
		{
	//		ft_printf("case1B\n");
			revrotate_a(stack);
			stack_1 = (*stack)->next;
		}
		if (((*stack)->content > stack_1->content) && ((*stack)->content > stack_2->content))
		{
	//		ft_printf("case2A\n");	
			rotate_a(stack);
		}
		else if ((*stack)->content > stack_1->content)
		{
	//		ft_printf("case2B\n");	
			swap_a(stack);
		}
	}
}

/*
void	push_5(int *stack_a, int *stack_b)
{
	//if size ==5
	push_3(&stack_a[2]);
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a);
	if (stack_a[1] > stack_a[2]
}
*/

int	check_sorted(t_list *stack_a)
{
	t_list	*curr;

	curr = stack_a->next;
	while (stack_a->next != NULL && ((stack_a->content) < (curr->content)))
	{
		stack_a = stack_a->next;
		curr = curr->next;
	}
//	ft_printf("test1: %i\n", stack_a->next);
	if (stack_a->next == NULL)
	{
//		perror("Already sorted: delete message and return "
//		"(0) before closing poject");
//		return (1);
		return (0);
	}
	return (9);
}

//adapt function for final upload: when deleting testsorting integrate free 
void	push_swap(t_list *stack_a)
{
	int	i;
	t_list	*stack_b;

	stack_b = NULL;
//	stack_b = ft_calloc(1, sizeof(t_list));
	i = ft_lstsize(stack_a);
//	while (check_sorted(stack_a) == 9)
	if (check_sorted(stack_a) == 0)
	{
		ft_free_ll(&stack_a);
		return ;
	}
	if (i < 4)
	{
//		ft_printf("test1\n");
		push_3(&stack_a);
	}
	else
	{
//		ft_printf("test2\n");
		stack_b = sort_average(&stack_a);
//		testsorting(&stack_b, 'b');
		sort_to_a(&stack_a, &stack_b);
//		testsorting(&stack_a, 'a');
//		ft_printf("test 5a\n");
		//not yet working: use code of check_sorted for it
		sort_biggest(&stack_a, &stack_b);
		if (check_sorted(stack_a) != 0)
			sort_clean_a(&stack_a);
		//sort_compare_ab(&stack_a, &stack_b);
//		testsorting(&stack_a, 'a');
//		testsorting(&stack_b, 'b');
//		check_swap(&stack_b);
//		resort_to_stacka(&stack_a, &stack_b);
//		check_swap(&stack_a);
//		testsorting(&stack_a, 'a');
//		testsorting(&stack_b, 'b');
//		i++;
	}
//	if (check_sorted(stack_a) == 0)
//	{
//		ft_free_ll(&stack_a);
//		return ;
//	}
/*
	if (!stack_a)
		return ;
	if (size = 3)
		push_3(stack_a);
	else if (size =< 5)
		push_5(stack_a);
	else
		push_max;
*/
//	swap_a(&stack_a);
//	push_b(&stack_a, &stack_b);
//	push_b(&stack_a, &stack_b);
//	swap_b(&stack_b);
//	swap_ab(&stack_a, &stack_b);
//	push_a(&stack_a, &stack_b);
//	rotate_a(&stack_a);
//	rotate_b(&stack_b);
//	rotate_ab(&stack_a, &stack_b);
//	revrotate_a(&stack_a);
//	revrotate_b(&stack_b);
//	revrotate_ab(&stack_a, &stack_b);
//	ft_printf("testA\n");
	testsorting(&stack_a, 'a');
//	ft_printf("test");
	testsorting(&stack_b, 'b');
//	ft_free_ll(stack_a);
	return;
}

//delete the error message and return (0) if no parameters are specified (according to subject)
//do I have to integrate read when argc == 0?
int	main(int argc, char **argv)
{
	t_list		*stack_a;
//	int		*stack_a;
	int		size;
	char	**stack_char;

	size = 0;
	if (argc == 2)
		stack_char = ft_split(argv[1], 32);
	else if (argc > 2)
		stack_char = clean_argv(argv, ft_calloc(1, sizeof(char *)));
	else
	{
		perror("Error3: too less arguments\n: Change to return (0) and delete error message before closing the project");
		return (1);
	}
	if (check_noarg(stack_char) != 0)
		return (1);
	if (input_errorcheck(stack_char) == 1 || check_signs(stack_char) == 1)
		return (1);
	size = ft_arrlen(stack_char);
	stack_a = create_stack_a(stack_char, size);
	if (check_dupli(&stack_a) == 1)
		return (1);
	push_swap(stack_a);
	return (0);
}
