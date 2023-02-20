# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 11:46:22 by otait-ta          #+#    #+#              #
#    Updated: 2023/02/17 15:24:57 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a

NAME = fractol

HEADER = src/fractol.h

SRC = main.c src/arg_helpers.c src/tools.c src/hndl_mlx.c src/julia.c src/map_helpers.c \
 	src/mandelbrot.c src/hooks.c 

OBJ = $(SRC:.c=.o)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

FLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME) 

$(LIBFT):
	make -C libft


$(NAME): $(OBJ) ${HEADER}
	cc $(FLAGS) -L libft/ -lft -lmlx -framework OpenGl -framework Appkit $(OBJ) -o $(NAME) 

clean: 
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/$(LIBFT)
	

re: fclean all

.PHONY: all clean fclean re	

