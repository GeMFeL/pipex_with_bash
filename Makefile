# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 14:32:52 by jchakir           #+#    #+#              #
#    Updated: 2022/02/05 14:10:37 by jchakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =-Wall -Wextra -Werror
NAME = pipex
BONUS_NAME = pipex_bonus
SOURCE_FILES = source/strjoin.c source/strncmp.c \
				source/strdup.c source/putstr_fd.c source/strlen.c
MANDA_FILES = $(SOURCE_FILES)
MANDA_FILES += pipex.c pipex_utils.c errors_and_free.c \
				fork_child_proc_to_exec_cmd.c

BONUS_FILES = $(SOURCE_FILES)
BONUS_FILES += errors_and_free_bonus.c fork_child_proc_to_exec_cmd_bonus.c \
				get_here_doc_bonus.c pipex_bonus.c pipex_utils_bonus.c

MANDA_OBJ = $(MANDA_FILES:%.c=%.o)
BONUS_OBJ = $(BONUS_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(MANDA_OBJ)
	$(CC) $(CFLAGS) $(MANDA_OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -rf  $(NAME) $(BONUS_NAME)

clean:
	rm -rf $(MANDA_OBJ) $(BONUS_OBJ)

re: fclean all

