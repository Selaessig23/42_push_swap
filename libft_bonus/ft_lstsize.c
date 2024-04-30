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

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
