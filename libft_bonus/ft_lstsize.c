/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:36 by mstracke          #+#    #+#             */
/*   Updated: 2024/01/10 11:29:05 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*DESCRIPTION: */
/* Counts the number of nodes in a list. */

#include "../push_swap.h"

//could be wrong to not create a temp var to not modify the existing list
int	ft_lstsize(t_list *lst)
{
	int	i;
//	t_list	*curr;

//	ft_printf("hello1b-1\n");
	i = 0;
//	curr = lst;
	while(lst != NULL)
	{
		lst = lst->next;
		i++;
	}
//	ft_printf("hello1b-2\n");
	return (i);
}

