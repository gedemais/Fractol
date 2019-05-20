# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 18:40:16 by gedemais          #+#    #+#              #
#    Updated: 2019/05/20 21:00:13 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OFLAGS = -O1 -O2 -O3 -Ofast -march=native

INC = includes/fractol.h

SRCS_NAME = main.c\
			mandelbrot.c\
			mlx_fts_1.c\
			parsing.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(SRCS_NAME:.c=.o)

LIB = libft/libft.a

NAME = fractol_du_sale

all : $(NAME)

$(NAME) : $(INC) $(LIB) $(SRCS)
	@echo "Making $(RED)fractol_du_sale...$(DEF)"
	$(CC) $(FLAGS) -o $(NAME) -I /usr/local/include/ $(SRCS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB)
	@echo "$(GRE)Done !$(DEF)"

$(LIB) :
	@echo "Making $(SOU)Libft$(DEF) :"
	@make -C libft/

clean:
	@rm -rf $(OBJS)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJS)
	@make -C libft/ fclean

re : fclean all
