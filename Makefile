# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstracke <mstracke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 09:59:44 by mstracke          #+#    #+#              #
#    Updated: 2024/04/24 11:21:18 by mstracke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#here are the declarations
CUR_DIR = $(shell pwd)

LIBFT_PATH = $(CUR_DIR)/libft

#LIBFT_MAKEFILE = $(CUR_DIR)/libft/Makefile

#PROGRAM = push_swap

#NAME = libftpushswap.a

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

CPPFLAGS = 

HEADERS = push_swap.h libft/libft.h

#delete libft_bonus_parts after integration (esp. ft_lstadd_front.c)
SRCS =	main.c \
		push_swap.c \
		ps_helper.c \
		sort_algo.c \
		cost_move.c \
		cheapest_target.c \
		cheapest_algo.c \
		rules/rule_swap.c \
		rules/rule_push.c \
		rules/rule_rotate.c \
		rules/rule_revrotate.c \
		error_handling/arg_check.c \
		error_handling/input_check.c \
		libft_bonus/ft_lstlast.c \
		libft_bonus/ft_lstadd_front.c \
		libft_bonus/ft_lstnew.c \
		libft_bonus/ft_lstadd_back.c \
		libft_bonus/ft_lstsize.c
#		testfunctions.c

LIBFT = libft.a

LIBFT_LIBRARY = $(CUR_DIR)/libft/libft.a

LIBFT_CREATE = libft.a

#PROGRAM = printf

#variable substitution		
OBJS = $(SRCS:.c=.o)

#%.o rule will compile one .c file to its correspondig object (.o) file: without this rule it would not update correctly
#automatic variables: $@ = the file name of the target of the rule, $< = the name of the prerequisite
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

#This target depends on $(NAME), making it the default target to build everything.
#this should be the moulinette-version (delete programm stuff):
all: $(NAME)
#modified to create a program (easier for my own tests)
#all: $(PROGRAM)

#to create a program:
$(NAME): $(OBJS) $(LIBFT_LIBRARY)
	$(CC) $(CFLAGS) $^ -o $@
	@echo -- prog created, try it by using ./push_swap

#creates the library $(NAME)
#ranlib creates and index which improves the efficiency of certain operations, such as quickly looking up symbols within the library.The index is stored in the archive itself.
#cp to extract the object files from libft.a to libftprintf.a
#!important to note: if the program can't find any of the dependencies it will do all
#$(LIBFT): 
#$(NAME): $(LIBFT_LIBRARY) $(OBJS)
#	cp $(LIBFT_LIBRARY) $(NAME)	
#	ar rcs $(NAME) $(OBJS)
#	ranlib $(NAME)
#	@echo -- libftprintf created / updated

#The -C option is used to change the directory to the specified path before executing make. In this context, it ensures that make operates in the subfolder, not the current directory.
#The -f option allows you to specify a particular Makefile to be used. If your subfolder has a different name for its Makefile (e.g., SubfolderMakefile instead of Makefile), you can use -f to specify the name of the Makefile to use in the subfolder == it is not obligatory
$(LIBFT_LIBRARY): $(LIBFT_CREATE)
	make -C $(LIBFT_PATH)
	@echo -- lib created / updated

#!important to note: if the program can't find any of the dependencies it will do all
#I have to options: use timestamp and compare
$(LIBFT_CREATE):
#	make -C $(LIBFT_PATH)
#	@echo -- UPDATE
	
#clean: This target removes the object files ($(OFILES)).
#f: "force" -->prevents the command from prompting for confirmation
clean:
	@rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	@echo -- Deleting All .o

# fclean: this target depends on clean. Once all object files are deleted, this rule will delete the created executable / the compiled binary ('$(NAME)') 
fclean: clean
	@rm -f $(NAME)
#	@rm -f $(PROGRAM)
	make -C $(LIBFT_PATH) fclean
	@echo -- Deleting .a


#This target depends on fclean and all, effectively cleaning and rebuilding the project.
re: fclean all

#This line specifies that the listed targets (all, clean, fclean, re) are phony targets, meaning they don't represent actual files, and should always be considered out-of-date, triggering their recipes to be executed.
.PHONY: all clean fclean re
