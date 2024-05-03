/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:03:29 by mstracke          #+#    #+#             */
/*   Updated: 2024/05/02 10:05:06 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//delete the error message and return (0) if no parameters 
//are specified (according to subject)
//perror("Error3: too less arguments\n: Change to return (0) "
//"and delete error message before closing the project");
//	if (check_noarg(stack_char) != 0)
//		return (1);
int	main(int argc, char **argv)
{
	char	**stack_char;
	t_list	*stack_a;
	int		size;

	size = 0;
	if (argc == 2)
		stack_char = ft_split(argv[1], 32);
	else if (argc > 2)
		stack_char = clean_argv(argv, ft_calloc(1, sizeof(char *)));
	else
		return (0);
	if (input_errorcheck(stack_char) == 1 || check_signs(stack_char) == 1)
		return (1);
	size = ft_arrlen(stack_char);
	stack_a = create_stack_a(stack_char, size);
	if (stack_a == NULL || check_dupli(&stack_a) == 1)
		return (1);
	push_swap(stack_a);
	return (0);
}
