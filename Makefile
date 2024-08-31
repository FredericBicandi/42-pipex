NAME = pipex
INCLUDES = ./src/
PRINTF = ./ft_printf/libftprintf.a
LIBFTDIR = ./ft_printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra

gnl = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
Libft = libft/ft_clean.c libft/ft_strncmp.c libft/ft_strdup.c  libft/ft_split.c libft/ft_strcombine.c
SRCS = pipex.c src/utils.c src/pipex_utils.c src/file_handler.c src/exec.c
BSRCS = bonus/pipex_bonus.c src/utils.c src/pipex_utils.c src/file_handler.c src/exec.c
OBJECTS = $(SRCS:.c=.o) 
BOBJECTS = $(BSRCS:.c=.o) 

all: $(NAME) clean

$(NAME): $(OBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(PRINTF) $(Libft) $(gnl)

$(PRINTF):
	@make -C ./ft_printf

bonus: $(NAME) $(BOBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) $(BOBJECTS) -o $(NAME) $(PRINTF) $(Libft) $(gnl) -no-pie
clean:
	@make clean -C ./ft_printf
	rm -f $(OBJECTS)
	rm -f $(BOBJECTS)
	@clear

fclean: clean 
	@make fclean -C ./ft_printf
	rm -f $(NAME)

re: fclean all
.PHONY: all bonus clean fclean re
