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
> INPUT: define what should happen if strings and int are mixed
> INPUT: give error message when signs are used twice or multiple times
> INPUT: how to handle numbers bigger than int?
> INPUT: what happens if input = ./push_swap -0 0
> write RULES
> find algorithm
*/

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
	//instead of this I could also use &argv[1];
	//ERROR HANDLING: define what should happen if strings and int are mixed
static char	**clean_argv(char **argv)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		t;
	size_t		p;
	char	*argv_temp1 = NULL;
	char	**argv_temp2 = NULL;
	char	**argv_temp3 = NULL;
	char	**argv_cleaned;

	//attempt to find a way to work with input if strings and int are mixed, maybe better to just return an error message
	i = 1;
	k = 0;
	t = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{			
			ft_printf("test1\n");
			if (argv[i][j] == 32)
			{
				ft_printf("test2a\n");
//				argv_temp = ft_calloc(k + 1, sizeof(char ***));					
				argv_temp2 = ft_split(argv[i], 32);
				break ;
			}
			else
			{
				ft_printf("test2b\n");
				j++;
			}
		}
		ft_printf("test3\n");
		if (ft_strlen(argv[i]) == j)
		{
			j = 0;
			argv_temp1 = ft_strdup(argv[i]);
			t++;
			argv_temp3 = argv_cleaned;
//			ft_free(argv_cleaned);
			argv_cleaned = ft_calloc((t + k + 1), sizeof(char **));
			ft_printf("test4a\n");
			if (!argv_temp3)
			{
				argv_cleaned[j] = ft_strdup(argv_temp1);
				argv_cleaned[j + 1] = NULL;
				ft_printf("test4a-1\n");
				free(argv_temp1);
				ft_free(argv_temp3);
			}
			else
			{
				while (argv_temp3[j] != NULL)
				{
					argv_cleaned[j] = ft_strdup(argv_temp3[j]);
					j++;
				}
				ft_printf("test4a-2\n");
				argv_cleaned[j] = ft_strdup(argv_temp1);
				argv_cleaned[j + 1] = NULL;
				free(argv_temp1);
				ft_free(argv_temp3);
			}
		}
		else
		{
			j = 0;
			ft_printf("test4b\n");
			while(argv_temp2[j])
				k++;
			argv_temp3 = argv_cleaned;
			ft_free(argv_cleaned);
			argv_cleaned = ft_calloc((t + k), sizeof(char **));
			while (argv_temp3[j])
			{
				argv_cleaned[j] = ft_strdup(argv_temp3[j]);
				j++;
			}
			p = 0;
			while (argv_temp2[p])
			{
				argv_cleaned[j] = ft_strdup(argv_temp2[p]);
				p++;
			}
			argv_cleaned[j] = NULL;
			ft_free(argv_temp2);
			ft_free(argv_temp3);
		}	
//		argv_temp[k] = NULL;
		ft_printf("test5\n");
		i++;
	}
	
//	argv_sh[k] = NULL;
//	i = 0;
//	while (argv[i])
//		i++;
//	while (argv_sh[k])
//	{
//		k++;
//		i--;
//	}
//	k = 0;
//	j = 0;
//	while (argv_sh[k][j])
//	{
//		j++;
//		i++;
//	}
	ft_printf ("result: %i\n", i);
	
	i = 0;
	while (argv[i])
		i++;
	argv_cleaned = ft_calloc((i), sizeof(char *));
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
			if (!ft_isdigit(stack_char[i][j]) && stack_char[i][j] != 32 
			&& stack_char[i][j] != 43 && (stack_char[i][j] != 45))
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
/*
int	intmaxcheck(long long *stack_a)
{
	size_t	i;
	
	i = 0;
	while (!stack_a[i])
	{
		if (stack_a[i] >= INT_MAX || stack_a[i] <= INT_MAX)
		{
			free(stack_a);
			perror("Error: MAX or MIN INT");
			return (1);
		}
		i++;
	}
	return (0);
}
*/
static int	*create_stacka(char **stack_char)
{
	int	i;
//	long long	*stack_a;
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
//		stack_a[i] = (long long) ft_atoi(stack_char[i]);
		i++;
	}
	stack_a[i] = 0;
	i = 0;
	/*
	if (intmaxcheck(stack_a) == 1)
		return (0);
	*/
	ft_free(stack_char);
//	return ((int *)stack_a);
	return (stack_a);
}

	//only for testing reasons
void	testsorting(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		ft_printf("stack_a[%d]: %d\n", i, stack[i]);
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
int	check_noarg(char **stack_char)
{
	int	i;

	i = 0;
	while (stack_char[i] != 0)
		i++;
	if (i <= 1)
	{
		ft_free(stack_char);
		perror("Error4: Please insert minimum 2 arguments");
		return (1);
	}
	return (0);
}

	//error_check duplicates
int	check_dupli(char **stack_char)
{
	int	i;
	int	j;

	i = 0;
	while (stack_char[i])
	{
		j = 1;
		while (stack_char[i + j])
		{
			if (ft_strncmp(stack_char[i], stack_char[i + j], 
					ft_strlen(stack_char[i])) != 0)
				j++;
			else
			{
				ft_free(stack_char);
				perror("Error1: Duplicates within arguments");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

	//error_check for double signs
	//created *temp to make it more readable
int	check_signs(char **stack_char)
{
	int	i;
	char	*temp;
	int	j;
	
	i = 0;
	j = 0;
	while (stack_char[j])
	{
		temp = stack_char[j];
		i = 0;
		while (*temp)
		{
			if (*temp == 43 || *temp == 45)
				i++;
			temp++;
		}
		if (i > 1)
		{
			ft_free(stack_char);
			perror("Error1: too many signs");
			return (1);
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		i;
	char	**stack_char;

	i = 0;
	if (argc == 2)
		stack_char = ft_split(argv[1], 32);
	else if (argc > 2)
//	{
//		while (argv[i])
//		{
//			ft_printf("test(%i): %s\n", i, argv[i]);
//			i++;
//		}
//		write(1, "\n", 1);
		stack_char = clean_argv(argv);
//	}
//		stack_char = &argv[1];
	else
	{
		perror("Error3: too less arguments\n");
		return (1);
	}
	if (input_errorcheck(stack_char) == 1 || check_signs(stack_char) == 1)
		return (1);
	if (check_noarg(stack_char) != 0)
		return (1);
	if (check_dupli(stack_char) != 0)
		return (1);
	stack_a = create_stacka(stack_char);
	push_swap(stack_a);
	return (0);
}
