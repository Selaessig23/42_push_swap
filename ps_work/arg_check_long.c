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

#include "push_swap.h"

	//create new char ** serving as input (argv without ./"programm-name")
	//instead of this I could also use &argv[1];
	//ERROR HANDLING: define what should happen if strings and int are mixed
char	**clean_argv(char **argv)
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
			else if (argv[i][j] == 34)
			{
				ft_printf("test2c\n");
				break ;
			}
			else
			{
				ft_printf("test2b: %c\n", argv[i][j]);
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
				free(argv_temp1);
				ft_printf("test4a-1: %s\n", argv_cleaned[j]);
//				ft_free(argv_temp3);
			}
			else
			{
				while (argv_temp3[j] != NULL)
				{
					argv_cleaned[j] = ft_strdup(argv_temp3[j]);
					ft_printf("test4a-2: %s\n", argv_cleaned[j]);
					j++;
				}
				argv_cleaned[j] = ft_strdup(argv_temp1);
				argv_cleaned[j + 1] = NULL;
				ft_printf("test4a-3 %s\n", argv_cleaned[j]);
				ft_printf("test4a-3 %s\n", argv_cleaned[j + 1]);
				free(argv_temp1);
				ft_free(argv_temp3);
			}
		}
		else
		{
			j = 0;
			while(argv_temp2[j] != NULL)
			{
				ft_printf("test4b-1: %s\n", argv_temp2[j]);
				j++;
				k++;
			}
			argv_temp3 = argv_cleaned;
//			ft_free(argv_cleaned);
			argv_cleaned = ft_calloc((t + k + 1), sizeof(char **));
			j = 0;
			ft_printf("test4b-2\n");
			while (argv_temp3[j] != NULL)
			{
				argv_cleaned[j] = ft_strdup(argv_temp3[j]);
				j++;
			}
			p = 0;
			while (argv_temp2[p])
			{
				argv_cleaned[j] = ft_strdup(argv_temp2[p]);
				j++;
				p++;
			}
			argv_cleaned[j] = NULL;
			ft_free(argv_temp2);
			ft_free(argv_temp3);
		}	
//		argv_temp[k] = NULL;
		i++;
		ft_printf("test5\n");
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
	while (argv_cleaned[i])
	{
			ft_printf("final_array: %s\n", argv_cleaned[i]);
			i++;
	}
	/*
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
	*/
	return (argv_cleaned);
}
