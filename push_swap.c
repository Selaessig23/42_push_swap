/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:20:19 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/17 18:09:44 by mstracke         ###   ########.fr       */
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
	//free the nodes / linked lists
void	testsorting(t_list **stack, char c)
{
	t_list	*curr;
	t_list	*temp;
	int		i;

	curr = *stack;
	i = 0;
	while (curr != NULL)
	{
		temp = curr;
		ft_printf("stack_%c[%d]: $%d$\n", c, i, curr->content);
		curr = curr->next;
		free(temp);
		i++;
	}
	stack = NULL;
}

/*
void	push_3(int *stack_a, int *stack_b)
{
	if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2] && stack_a[0] > stack_a[2])
	{
		rr_a(stack_a);
		rr_a(stack_a);
	}
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a);
	if (stack_a[1] > stack_a[2] && stack_a[2] < stack_a[0])
		rr_a(stack_a);
	else
	{
		rr_a(stack_a);
		swap_a(stack_a);
	}
	
}

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
	if (stack_a->next == NULL)
	{
//		perror("Already sorted: delete message and return "
//		"(0) before closing poject");
//		return (1);
		return (0);
	}
	return (9);
}

//adapt function for final upload? 
void	push_swap(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
//	ft_printf("test 5a\n");
//	stack_b = ft_calloc(1, sizeof(t_list));
	while (check_sorted(stack_a) == 9)
	{
		stack_b = sort_median(&stack_a);
		sort_compare_ab(&stack_a, &stack_b);
		resort_to_stacka(&stack_a, &stack_b);
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
	testsorting(&stack_a, 'a');
	testsorting(&stack_b, 'b');
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
