/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:45:34 by mstracke          #+#    #+#             */
/*   Updated: 2024/01/10 11:14:56 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* DESCRIPTION: */
/* Adds the node ’new’ at the beginning of the list. */

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
