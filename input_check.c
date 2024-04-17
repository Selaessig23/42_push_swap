/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:45:47 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/02 09:46:10 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_check(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!ft_isdigit(str[j]) && str[j] != 32 
			&& str[j] != 43 && (str[j] != 45))
			return (1);
		j++;
	}
	return (0);
}

//error check for faulty input_creation (of ft_split or clean_argv)
//and error check of wrong input (if not integer)
int	input_errorcheck(char **stack_char)
{
	int	i;
	int	j;

	if (!stack_char)
	{
		ft_free(stack_char);
		return (1);
	}
	i = 0;
	while (stack_char[i])
	{
		j = 0;
		if (digit_check(stack_char[i]) == 1)
		{
			ft_free(stack_char);
			perror("Error1A: only digits\n");
			return (1);
		}
		i++;
	}
	return (0);
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

	//error_check duplicates within a linked list
int	check_dupli(t_list **stack_a)
{
	t_list	*add;
	t_list	*curr;

	curr = *stack_a;
//	ft_printf("test1a\n");
	while (curr != NULL)
	{
	
		add = curr->next;
		while ((add != NULL && curr->content != add->content))
			add = add->next;
		if (add != NULL && curr->content == add->content)
		{
			ft_free_ll(stack_a);
//			ft_free_ll(&curr);
//			ft_free_ll(&add);
			perror("Error1: Duplicates within arguments");
			return (1);
		}
		curr = curr->next;

	}
//	ft_printf("test1\n");
	return (0);
}

/*
	//error_check duplicates within an array of ints
int	check_dupli(int *stack_a, int size)
{
	int	j;

	j = 1;
	size = size - 1;
	while (size >= 0)
	{
		j = size - 1;
		while ((j >= 0 && stack_a[size] != stack_a[j]))
			j--;
		if (j >= 0 && stack_a[size] == stack_a[j])
		{
			free(stack_a);
			perror("Error1: Duplicates within arguments");
			return (1);
		}
		size--;
	}
	return (0);
}
*/
	//error_check for double signs
	//created *temp to make it more readable
int	check_signs(char **stack_char)
{
	char	*temp;
	int		i;
	int		j;

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
