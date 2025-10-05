NAME = fractol

NAME_1 = fractol_bonus

SRC = main.c init_fractol.c put_fractol.c

BSRC = main_bonus.c init_fractol_bonus.c put_fractol_bonus.c

CC = cc 

CFLAGS = -Wall -Werror -Wextra 

LIBFT = ./libft/libft.a 

MLB = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext 

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)


all: $(NAME)
bonus: $(NAME_1)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLB) -o $(NAME)

$(NAME_1) :  $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) $(MLB) -o $(NAME_1)

$(LIBFT):
	make -C ./libft

clean:
	make clean -C ./libft
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAME_1)

re: fclean $(NAME)

.PHONY: re fclean clean bonus all
