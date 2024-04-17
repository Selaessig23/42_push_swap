/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:45:46 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/16 12:04:01 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	//use other function
	//curr = ft_lstlast(*lst);
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	curr = *lst;
	//while loop could be deleted when using other function
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}
