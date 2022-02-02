# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 14:32:52 by jchakir           #+#    #+#              #
#    Updated: 2022/02/02 16:13:25 by jchakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =-Wall -Wextra -Werror
NAME = pipex
SOURCE_FILES = source/strjoin.c source/strncmp.c \
				source/strdup.c source/putstr_fd.c source/strlen.c
MANDA_FILES = $(SOURCE_FILES)
MANDA_FILES += pipex.c pipex_utils.c get_here_doc.c main.c \
				errors_and_free.c fork_child_proc_to_exec_cmd.c

MANDA_OBJ = $(MANDA_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(MANDA_OBJ)
	$(CC) $(CFLAGS) $(MANDA_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -rf  $(NAME)

clean:
	rm -rf $(MANDA_OBJ)

re: fclean all
