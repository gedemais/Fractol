# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 18:40:16 by gedemais          #+#    #+#              #
#    Updated: 2020/10/26 21:10:53 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OFLAGS = -O3 -Ofast -march=native

INC = includes/fractol.h

SRCS_NAME = main.c\
			mandelbrot.c\
			mlx_fts_1.c\
			colors.c\
			hud.c\
			singletons.c\
			deal_key.c\
			press.c\
			parsing.c\
			opencl.c\
			utils.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(SRCS_NAME:.c=.o)

MLX_PATH = minilibx_macos/

MLX = minilibx_macos/libmlx.a

MLX_OBJS_NAME = mlx_init_loop.o\
				mlx_int_str_to_wordtab.o\
				mlx_new_image.o\
				mlx_new_window.o\
				mlx_shaders.o\
				mlx_xpm.o

MLX_OBJS = $(addprefix $(MLX_PATH), $(MLX_OBJS_NAME))

LIB_PATH = libft/

LIB = libft/libft.a

INC = includes/fractol.h

NAME = fractol_du_sale

all : $(MLX_PATH) $(LIB) $(NAME) $(INC)

$(NAME) : $(MLX) $(INC) $(LIB_PATH) $(SRCS)
	@echo "Making $(RED)fractol_du_sale...$(DEF)"
	@$(CC) $(FLAGS) $(OFLAGS) -o $(NAME) -Iminilibx_macos/ $(SRCS) -Lminilibx_macos/ minilibx_macos/libmlx.a -framework OpenGL -framework OpenCL -framework AppKit -lpthread $(LIB)
	@echo "$(GRE)Done !$(DEF)"

$(LIB) :
	@echo "Making $(SOU)Libft$(DEF) :"
	@make -C libft/

$(MLX) : $(MLX_PATH)
	@echo "Making $(SOU)MinilibX$(DEF) :"
	@make -C $(MLX_PATH)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(MLX_OBJS)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJS)
	@rm -rf $(MLX_PATH)/libmlx.a
	@make -C libft/ fclean

re : fclean all
