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

#include "push_swap.h"

static void	ft_free(char **stack_char)
{
	int	i;

	i = 0;
	while (stack_char[i])
	{
		free(stack_char[i]);
		i++;
	}
	free(stack_char);
	stack_char = NULL;
}

	//create new char ** serving as input (argv without ./"programm-name")
static char	**clean_argv(char **argv)
{
	int		i;
	char	**argv_cleaned;

	i = 0;
	while (argv[i])
		i++;
	argv_cleaned = ft_calloc((i + 1), sizeof(char *));
	if (!argv_cleaned)
	{
		ft_free(argv_cleaned);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		argv_cleaned[i - 1] = ft_strdup(argv[i]);
		if (!argv_cleaned[i - 1])
		{
			ft_free(argv_cleaned);
			return (0);
		}
		i++;
	}
	argv_cleaned[i - 1] = NULL;
	return (argv_cleaned);
}

	//error check for faulty input_creation (of ft_split or clea_aergv) 
	//and error check of wrong input (if not integer)
static int	input_errorcheck(char **stack_char)
{
	int	i;
	int	j;

	if (!stack_char)
	{
		ft_free(stack_char);
		return (0);
	}
	i = 0;
	while (stack_char[i])
	{
		j = 0;
		while (stack_char[i][j])
		{
			if (!ft_isdigit(stack_char[i][j]) && stack_char[i][j] != 32)
			{
				ft_free(stack_char);
				perror("Error1A: only digits\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	*create_stacka(char **stack_char)
{
	int	i;
	int	*stack_a;

	if (input_errorcheck(stack_char) == 1)
		return (0);
	i = 0;
	while (stack_char[i])
		i++;
	stack_a = ft_calloc((i + 1), sizeof(int));
	if (!stack_a)
	{
		ft_free(stack_char);
		return (0);
	}
	i = 0;
	while (stack_char[i])
	{
		stack_a[i] = ft_atoi(stack_char[i]);
		i++;
	}
	stack_a[i] = 0;
	i = 0;
	ft_free(stack_char);
	return (stack_a);
}

	//only for testing reasons
void	testsorting(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		ft_printf("stack_a[%i]: %i\n", i, stack[i]);
//		free(stack_a[i]);
		i++;
	}
	free (stack);
	stack = NULL;
}

void	push_swap(int *stack_a)
{
	int	*stack_b;

//	ft_printf("test 5a\n");
	if (!stack_a)
		return ;
	stack_b = ft_calloc(1, sizeof(int));
	swap_a(stack_a);
//	stack_b = ft_push(stack_a, stack_b);
	testsorting(stack_a);
	testsorting(stack_b);
}

	//error_check amount of arguments
int	check_noarg(int *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i] != 0)
		i++;
	if (i <= 1)
	{
		free (stack_a);
		perror("Error4: Please insert minimum 2 arguments");
		return (1);
	}
	return (0);
}

	//error_check duplicates
int	check_dupli(int *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i])
	{
		while (stack_a[i] != 
	return (0);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	i;

	i = 0;
	if (argc == 2)
		stack_a = create_stacka(ft_split(argv[1], 32));
	else if (argc > 2)
		stack_a = create_stacka(clean_argv(argv));
	else
	{
		perror("Error3: too less arguments\n");
		return (1);
	}
	if (!stack_a)
		return (0);
	if (check_noarg(stack_a) != 0)
		return (1);
	if (check_dupli(stack_a) != 0)
		return (1);
	push_swap(stack_a);
	return (0);
}
