/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:20:19 by mstracke          #+#    #+#             */
/*   Updated: 2024/03/18 13:49:04 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* for testing purpose: valgrind --leak-check=full 
--show-leak-kinds=all --track-origins=yes */
/* open: 
> [solved]in function check_dupli change strncmp to 
	strcmp or adapt n (status quo: if str a < str b == problem)
> [solved]INPUT: define what should happen if strings and int are mixed
> [solved]INPUT: give error message when signs are used twice or multiple times
> [solved]INPUT: how to handle numbers bigger than int?
> [solved] INPUT: what happens if input = ./push_swap -0 0
> write RULES with linked lists?
> find algorithm
*/

#include "push_swap.h"

	//check some arguments are bigger than an integer
int	intmaxcheck(int *stack_a, long long value)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		free(stack_a);
		perror("Error: MAX or MIN INT");
		return (1);
	}
	return (0);
}

	//use input arguments and creat an array of ints (used as stack_a)
	//do not return 0 if error, better instead: 1
static int	*create_stacka(char **stack_char, size_t size)
{
	size_t	i;
	int		*stack_a;

	if (input_errorcheck(stack_char) == 1)
		return (0);
	//c does not manage the end of an int* like with *char
//	stack_a = ft_calloc((i + 1), sizeof(int));
	stack_a = ft_calloc((size), sizeof(int));
	if (!stack_a)
	{
		ft_free(stack_char);
		return (0);
	}
	i = 0;
	while (i < (size))
	{
		if (intmaxcheck(stack_a, (long long) ft_atoi(stack_char[i])) == 1)
		{
			ft_free(stack_char);
			return (0);
		}
		stack_a[i] = ft_atoi(stack_char[i]);
		i++;
//		ft_printf("stack_a: %i\n", stack_a[i - 1]);
//		ft_printf("stack_char: %s\n", stack_char[i - 1]);
	}
//	ft_printf("%i\n", i);
	ft_free(stack_char);
	return (stack_a);
}

	//only for testing reasons
void	testsorting(int *stack, int size, char c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("stack_%c[%d]: $%d$\n", c, i, stack[i]);
//		free(stack_a[i]);
		i++;
	}
	free (stack);
	stack = NULL;
}

//adapt function for final upload? 
void	push_swap(int *stack_a, int size)
{
//	int	*stack_b;

//	ft_printf("test 5a\n");
	if (!stack_a)
		return ;
//	stack_b = ft_calloc(1, sizeof(int));
	swap_a(stack_a);
//	stack_b = ft_push(stack_a, stack_b);
	testsorting(stack_a, size, 'a');
//	testsorting(stack_b, size, 'b');
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		size;
	char	**stack_char;

	size = 0;
	if (argc == 2)
		stack_char = ft_split(argv[1], 32);
	else if (argc > 2)
		stack_char = clean_argv(argv, ft_calloc(1, sizeof(char *)));
	else
	{
		perror("Error3: too less arguments\n");
		return (1);
	}
	if (check_noarg(stack_char) != 0)
		return (1);
	if (input_errorcheck(stack_char) == 1 || check_signs(stack_char) == 1)
		return (1);
	size = ft_arrlen(stack_char);
	stack_a = create_stacka(stack_char, size);
	if (!stack_a || check_dupli(stack_a, size) == 1)
		return (1);
	push_swap(stack_a, size);
	return (0);
}
