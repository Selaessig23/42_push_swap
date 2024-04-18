/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:55:33 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/17 18:08:26 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description: Returns the last node of the list. */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
