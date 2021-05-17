# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 15:34:00 by xli               #+#    #+#              #
#    Updated: 2021/05/17 16:27:20 by xli              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#CHECKER = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES_PATH = includes/

INCLUDES = $(INCLUDES_PATH)push_swap.h

SRCS_PATH = srcs/push_swap/

SRCS_FILES = push_swap.c

MAIN = srcs/push_swap/main.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

#CHECKER_PATH = srcs/checker/

#CHECKER_FILES =

#CHECKER_MAIN = srcs/checker/main.c

#CHECKER_SRCS = $(addprefix $(CHECKER_PATH), $(CHECKER_FILES))

PARSE_PATH = srcs/parse/

PARSE_FILES = operation0.c operation1.c operation2.c operation3.c exit.c parse.c

PARSE_SRCS = $(addprefix $(PARSE_PATH), $(PARSE_FILES))

LIB_PATH = libft/

LIB = $(LIB_PATH)libft.a

OBJS = $(SRCS:.c=.o)

#CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

#CHECKER_MAIN_OBJS = $(CHECKER_MAIN:.c=.o)

PARSE_OBJS = $(PARSE_SRCS:.c=.o)

MAIN_OBJS = $(MAIN:.c=.o)

all : $(NAME) $(CHECKER)
	@echo "compile OK"

%.o : %.c $(INCLUDES) $(LIB)
	@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

$(LIB) :
	@$(MAKE) -C $(LIB_PATH)

$(NAME) : $(INCLUDES) $(OBJS) $(PARSE_OBJS) $(MAIN_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PARSE_OBJS) $(MAIN_OBJS) $(LIB) -o $(NAME)

#$(CHECKER) : $(INCLUDES) $(CHECKER_OBJS) $(PARSE_OBJS) $(CHECKER_MAIN_OBJS)
#	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(PARSE_OBJS) $(CHECKER_MAIN_OBJS) $(LIB) -o $(CHECKER)

clean :
	@rm -rf $(OBJS) $(PARSE_OBJS) $(MAIN_OBJS)
	@$(MAKE) clean -C $(LIB_PATH)
	@echo "clean done"

fclean :
	@rm -rf $(OBJS) $(PARSE_OBJS) $(MAIN_OBJS)
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIB_PATH)
	@echo "fclean done"

re : fclean all

.PHONY : all clean fclean re