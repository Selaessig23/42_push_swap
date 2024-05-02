/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:21:16 by mstracke          #+#    #+#             */
/*   Updated: 2024/04/24 11:20:04 by mstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to avoid duplications
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* change in libft of ft_atoi: */
/* return value size_t (to exclude INT_MAX & INT_MIN) */
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

//declare linked lists
typedef struct s_list
{
	int					content;
	struct s_list		*next;
}	t_list;

int	main(int argc, char **argv);
//push_swap.h basic functions to build stack and allocate functions
void	push_swap(t_list *stack_a);
int	check_sorted(t_list *stack_a);
void	push_3(t_list **stack);
t_list	*create_stack_a(char **stack_char, size_t size);
int	intmaxcheck(t_list *stack_a, long long value);
//libft_bonus functions in /libft_bonus
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);
//operations for push_swap in /rules
//rule_revrotate.c
void	revrotate_a(t_list **stack_a);
void	revrotate_b(t_list **stack_b);
void	revrotate_ab(t_list **stack_a, t_list **stack_b);
//rule_rotate.c
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
//rule_push.c
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
//rule_swap.c
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ab(t_list **stack_a, t_list **stack_b);
//ps_helper.c: helper functions
void	ft_free(char **stack_char);
void	ft_free_ll(t_list **ll);
size_t	ft_arrlen(char **argv_temp2);
//check of input arguments and input in /error_handling
//arg_check.c: check if arguments are strings and or inte
char	**clean_argv(char **argv, char **argv_cleaned);
//input_check.c: check input in detail
int		digit_check(char *str);
int		input_errorcheck(char **stack_char);
int		check_noarg(char **stack_char);
int		check_dupli(t_list **stack_a);
int		check_signs(char **stack_char);
//algorithms to sort the stack in sort_algo
//sort_average.c sort for average
float	count_average(t_list *stack);
t_list	*sort_average(t_list **stack_a);
//void	sort_compare_ab(t_list **stack_a, t_list **stack_b);
//void	sort_biggest(t_list **stack_a, t_list **stack_b);
//void	resort_to_stacka(t_list **stack_a, t_list **stack_b);
//void	check_swap(t_list **stack);

int		intmaxcheck(t_list *stack_a, long long value);
//int		intmaxcheck(int *stack_a, long long value);

//cost_move.c sorting algortithms helper functions
int    check_smallest(t_list *stack);
int    check_biggest(t_list *stack);
void	sort_clean_a(t_list **stack_a);
void	sort_to_a(t_list **stack_a, t_list **stack_b);
//cheapest_target.c
int	find_index(t_list **stack, int num);
int  find_target(t_list **stack, int num);
int	calc_moves(t_list **stack, int num);
int	target_operations(t_list **stack_current, t_list **stack_other, int num, bool exe);
int	find_cheapest(t_list **stack_a, t_list **stack_b);
//cheapest_algo.c for testing
void	exe_oper(t_list **stack_a, t_list **stack_b);
//cheapest_algo.c
void	exe_operations_single(t_list **stack_current, t_list **stack_other, int num);
void	exe_operations_down(t_list **stack_current, t_list **stack_other, int num);
void	exe_operations_up(t_list **stack_current, t_list **stack_other, int num);
void	exe_cheapest(t_list **stack_a, t_list **stack_b);
//testfunctions.c for testing reasons
//void	testsorting(t_list **stack, char c);

/*
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int	ft_printf(const char *format, ...);
*/
//

#endif
