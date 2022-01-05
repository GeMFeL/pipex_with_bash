CC = cc
CFLAGS =-Wall -Wextra -Werror
NAME = pipex.a
P_NAME = pipex
FILES = pipex.c pipex_utils.c

OBJ = $(FILES:%.c=%.o)

all: creat
	$(CC) $(CFLAGS) main.c $(NAME) libft/libft.a -o $(P_NAME)

creat: compile_libft $(OBJ)
	ar rcs $(NAME) $(OBJ)

compile_libft:
	cd libft && make all

fclean: clean
	cd libft && make fclean
	rm -rf  $(NAME) $(P_NAME)
clean:
	cd libft && make clean
	rm -rf $(OBJ)

re: fclean all
