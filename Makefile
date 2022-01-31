CC = cc
CFLAGS =-Wall -Wextra -Werror
NAME = pipex.a
P_NAME = pipex
SOURCE_FILES = source/split.c source/strlen.c source/strnstr.c source/strjoin.c \
				source/strncmp.c source/strchr.c source/strdup.c source/putstr_fd.c
FILES = pipex.c pipex_utils.c get_here_doc.c errors_and_free.c \
		fork_child_proc_to_exec_cmd.c

SOURCE_OBJ = $(SOURCE_FILES:%.c=%.o)
OBJ = $(FILES:%.c=%.o)

all: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o $(P_NAME)

$(NAME): creat

creat: $(SOURCE_OBJ) $(OBJ)
	ar rcs $(NAME) $(SOURCE_OBJ) $(OBJ)

fclean: clean
	rm -rf  $(NAME) $(P_NAME)

clean:
	rm -rf $(SOURCE_OBJ) $(OBJ)

re: fclean all
