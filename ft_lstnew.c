/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1stnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:12:04 by mstracke          #+#    #+#             */
/*   Updated: 2024/01/09 16:27:43 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* NAME: create a new list node element */
/* DESCRIPTION:  */
/* Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.
*/
#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = (t_list *) malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
/* how to test?
int	main(void)
{
	t_list	*test;
	char	*content = "hello";

	test = ft_lstnew(content);
	return(0);
}
*/
