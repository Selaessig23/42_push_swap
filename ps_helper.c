/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:03:30 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/02 10:03:56 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate the size of an array of strings
size_t	ft_arrlen(char **arr_str)
{
	size_t	i;

	i = 0;
	while (arr_str[i])
		i++;
	return (i);
}

//free an array of strings
void	ft_free(char **stack_char)
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

void	ft_free_ll(t_list **ll)
{
	t_list	*temp;
	t_list	*curr;

	curr = *ll;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	curr = NULL;
}
/*
int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
*/
/*
int	calc_size(char **stack_char)
{
	int	i;
	
	i = 0;
	while (stack_char[i])
		i++;
	return (i);
}
*/
