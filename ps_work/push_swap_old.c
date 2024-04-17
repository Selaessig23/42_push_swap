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

static int	*create_stacka(char *arg)
{
	int	i;
	char	**stack_char;
	int	*stack_a;

	i = 0;
	//to test if there are only digits or spaces
	//change standard output
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 1)
			i++;
		else if (arg[i] == 32)
			i++;
		else
		{
			perror("Error1A: only digits\n");
			return (0);
		}
	}
	stack_char = ft_split(arg, 32);
	if (!stack_char)
	{
		free(stack_char);
		stack_char = NULL;
	}
	i = 0;
	while (stack_char[i])
	       i++;
	stack_a = ft_calloc((i + 1), sizeof(int));
	if (!stack_a)
	{	
		while (**stack_char)
		{
			free(*stack_char);
			++**stack_char;
		}
		free(stack_char);
		stack_char = NULL;
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
	while (stack_char[i])
	{
		free(stack_char[i]);
		i++;;
	}
	free(stack_char);
	stack_char = NULL;
	return (stack_a);
}

void	push_swap(int *stack_a)
{
	int	i;
	int	*stack_b;

	i = 0;
//	ft_printf("test 5a\n");
	if (!stack_a)
		return;
	stack_b = ft_calloc(1, sizeof(int));
	swap_a(stack_a);
	stack_b = ft_push(stack_a, stack_b);
	while (stack_a[i])
	{
		ft_printf("stack_a[%i]: %i\n", i, stack_a[i]);
//		free(stack_a[i]);
		i++;
	}
	free (stack_a);
	stack_a = NULL;
	i = 0;
	while (stack_b[i])
	{
		ft_printf("stack_b[%i]: %i\n", i, stack_b[i]);
//		free(stack_a[i]);
		i++;
	}
	free (stack_b);
	stack_b = NULL;
}

int	main (int argc, char **argv)
{
	int	*stack_a;
	int	i;
	int	j;

	i = 0;
	j = 0;
	//integrate error check if some arguments are bigger than an integer
	if (argc == 2)
	{
		stack_a = create_stacka(argv[1]);
		if (!stack_a)
			return (0);
	}
	else if (argc > 2)
	{
		while (argv[i])
			i++;
		stack_a = ft_calloc((i), sizeof(int));
		i = 0;
		while(argv[i])
			i++;
		i = 1;
		while (argv[i])
		{
			if (ft_isdigit(argv[i][0]) == 1)
			{
				//to consider cases like this: 12 1f
				while (argv[i][j])
				{ 
					if (ft_isdigit(argv[i][j]) == 1)
						j++;
					else
					{
						perror("Error2A: only digits\n");
						return (1);
					}
				}
				stack_a[i - 1] = ft_atoi(argv[i]);
				i++;
			}
			else if (argv[i][0] == 32)
				i++;
			else
			{
				perror("Error2B: only digits\n");
				return (1);
			}
		}
		stack_a[i - 1] = 0;
	}
	else
	{
		perror("Error3: too less arguments\n");
		return (1);
	}
	i = 0;
	while (stack_a[i] != 0)
		i++;
	if (i <= 1)
	{
		free (stack_a);
		perror("Error4: Please insert minimum 2 arguments");
		return (1);
	}
	//error_check duplicates
	push_swap(stack_a);
	return (0);
}



