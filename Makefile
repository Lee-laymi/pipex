# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 00:03:36 by skrairab          #+#    #+#              #
#    Updated: 2022/09/15 22:42:06 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_split.c\
	ft_strjoin.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	pipex.c\
	re_pipe.c\
	getpath.c\
	runcmd.c

BONUS = ft_split.c\
	ft_strjoin.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	pipex.c\
	re_pipe.c\
	getpath.c\
	runcmd.c

SRCS_BONUS = $(BONUS)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = pipex

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -g $(CC_FLAGS) -o $(NAME) $(SRCS)

bonus:
	$(CC) -g $(CC_FLAGS) -o $(NAME) $(SRCS_BONUS)

clean:
	rm -rf $(NAME) $(OBJS_BONUS)
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) $(OBJS_BONUS)
	rm -rf *.o
	rm -rf pipex
	rm -rf outfile

re: fclean all

.PHONY: all clean fclean re
