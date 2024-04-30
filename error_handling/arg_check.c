/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:45:47 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/02 09:52:44 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* for testing purpose: valgrind --leak-check=full 
--show-leak-kinds=all --track-origins=yes */
/* create new char ** serving as input (argv without ./"programm-name") */
/* instead of this I could also use &argv[1]; */
/* ERROR HANDLING: define what should happen if strings and int are mixed */
// OPEN: reduce 1 line in function clean_argv
#include "../push_swap.h"

//if there are spaces within one argument
static char	**int_multiple_arg(char **argv_cleaned, char **argv_temp2, 
				size_t t)
{
	size_t		j;
	size_t		p;
	char		**argv_temp3;

	j = 0;
	p = 0;
	argv_temp3 = argv_cleaned;
	argv_cleaned = ft_calloc((t + 1), sizeof(char *));
	while (argv_temp3[j] != NULL)
	{
		argv_cleaned[j] = ft_strdup(argv_temp3[j]);
		j++;
	}
	while (argv_temp2[p])
	{
		argv_cleaned[j] = ft_strdup(argv_temp2[p]);
		j++;
		p++;
	}
	argv_cleaned[j] = NULL;
	ft_free(argv_temp2);
	ft_free(argv_temp3);
	return (argv_cleaned);
}

//helper function for concat_argv
//concat string to array if array is already filled with strings
static void	concat_help(char **argv_cleaned, char **argv_temp3, 
			char *argv_temp1, size_t j)
{
	while (argv_temp3[j] != NULL)
	{
		argv_cleaned[j] = ft_strdup(argv_temp3[j]);
		j++;
	}
	argv_cleaned[j] = ft_strdup(argv_temp1);
	argv_cleaned[j + 1] = NULL;
	free(argv_temp1);
	ft_free(argv_temp3);
}

//if there are no spaces within one argument
static char	**concat_argv(char **argv_cleaned, char *argv, size_t t)
{
	size_t		j;
	char		*argv_temp1;
	char		**argv_temp3;

	j = 0;
	argv_temp1 = ft_strdup(argv);
	argv_temp3 = argv_cleaned;
	argv_cleaned = ft_calloc((t + 1), sizeof(char **));
	if (!argv_temp3)
	{
		argv_cleaned[j] = ft_strdup(argv_temp1);
		argv_cleaned[j + 1] = NULL;
		free(argv_temp1);
	}
	else
		concat_help(argv_cleaned, argv_temp3, argv_temp1, j);
	return (argv_cleaned);
}

//1st step: check if there are spaces within one argument
static int	clean_help(char *argv, char ***argv_temp2)
{
	size_t	j;

	j = 0;
	while (argv[j])
	{
		if (argv[j] == 32)
		{
			*argv_temp2 = ft_split(argv, 32);
			return (j);
		}
		else if (argv[j] == 34)
		{
			*argv_temp2 = ft_split(argv, 32);
			return (j);
		}
		else
			j++;
	}
	return (j);
}

//attempt to find a way to work with input 
//if strings and int are mixed, 
//check if there are spaces within one argument
//no: add string to string-array
//yes: add string-array to string-array
char	**clean_argv(char **argv, char **argv_cleaned)
{
	size_t		i;
	size_t		j;
	size_t		t;
	char		**argv_temp2;

	i = 1;
	t = 0;
	argv_temp2 = NULL;
	while (argv[i])
	{
		j = clean_help(argv[i], &argv_temp2);
		if (ft_strlen(argv[i]) == j)
		{
			t++;
			argv_cleaned = concat_argv(argv_cleaned, argv[i], t);
		}
		else
		{
			t = (t + ft_arrlen(argv_temp2));
			argv_cleaned = int_multiple_arg(argv_cleaned, argv_temp2, t);
		}
		i++;
	}
	return (argv_cleaned);
}
