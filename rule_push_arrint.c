/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:42:30 by mstracke          #+#    #+#             */
/*   Updated: 2024/03/19 16:43:00 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(int *stack_1, int *stack_2)
{
	int	*temp_1;
	int	*temp_2;
	int	i;
	int	len;

	if (!stack_2)
		return ;
	temp_1 = stack_1;
	temp_2 = stack_2;
//	free(stack_2);
	len = ft_arrlen(stack_1);
	stack_1 = (int *)malloc(sizeof(int) * (len + 1));
	if (!stack_1)
		return (0);
	stack_1[0] = temp_2[0];
	i = 0;
	while ((len + 1) > i)
	{
		stack_1[i + 1] = temp_1[i];
		i++;
	}
//	ft_printf("test1\n");
//	free (temp_2);
//	temp_2 = 0;
//	len = 0;
//	while (stack_1[len])
//		len++;
//	stack_1 = ft_calloc((len - 1), sizeof(int));
//	if (!stack_1)
//		return (0);
	free(temp1);
	len = ft_arrlen(stack_2);
	stack_1 = (int *)malloc(sizeof(int) * (len - 1));
	if (!stack_2)
		return (0);
	i = 0;
	while((len - 1) > i)
	{
		stack_2[i] = temp_2[i + 1];
		i++;
	}
	free(temp_2);
//	temp_1 = 0;
//	return (stack_2);
}

void	push_a(int *stack_a, int *stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb");
}

void	push_b(int *stack_a, int *stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa");
}
