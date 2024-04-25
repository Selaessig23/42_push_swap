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

//declare linked lists
typedef struct s_list
{
	int					content;
	struct s_list		*next;
}	t_list;

//libft_bonus functions (to integrate in libft)
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);
//void	ft_lstadd_front(t_list **lst, t_list *new);
//functions for push_swap
void	revrotate_a(t_list **stack_a);
void	revrotate_b(t_list **stack_b);
void	revrotate_ab(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ab(t_list **stack_a, t_list **stack_b);
//helper functions
void	ft_free(char **stack_char);
void	ft_free_ll(t_list **ll);
size_t	ft_arrlen(char **argv_temp2);
//int	calc_size(char **stack_char);
//int	ft_strcmp(const char *str1, const char *str2);
//input arguments
char	**clean_argv(char **argv, char **argv_cleaned);
//check input
int		digit_check(char *str);
int		input_errorcheck(char **stack_char);
int		check_noarg(char **stack_char);
int		check_dupli(t_list **stack_a);
//int		check_dupli(int *stack_a, int size);
int		check_signs(char **stack_char);
int		intmaxcheck(t_list *stack_a, long long value);
//int		intmaxcheck(int *stack_a, long long value);
//sorting algortithms
void	push_3(t_list **stack);
t_list	*sort_average(t_list **stack_a);
void	sort_compare_ab(t_list **stack_a, t_list **stack_b);
void	sort_biggest(t_list **stack_a, t_list **stack_b);
void	resort_to_stacka(t_list **stack_a, t_list **stack_b);
void	check_swap(t_list **stack);
int    check_biggest(t_list *stack);
int		check_sorted(t_list *stack_a);
void	sort_clean_a(t_list **stack_a);
void	sort_to_a(t_list **stack_a, t_list **stack_b);
//for testing reasons:
void	testsorting(t_list **stack, char c);

/*
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int	ft_printf(const char *format, ...);
*/
//

#endif
