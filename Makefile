CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME_M = fractol
# NAME_B = fractol
HEADER = ./mandatory/include
SRC = ./mandatory/main.c ./mandatory/mandelbrot.c ./mandatory/julia.c\
		./mandatory/color.c ./mandatory/prod.c ./mandatory/zoom_mdt.c \
		./mandatory/zoom_julia.c ./mandatory/print_msg.c
OBJ = $(SRC:.c=.o)

all: $(NAME_M)

$(NAME_M): $(OBJ)
	@$(CC) $(OBJ) ./minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME_M)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

# bonus: $(NAME_B)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME_M)

re : fclean all