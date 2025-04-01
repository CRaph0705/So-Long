# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 17:53:43 by rcochran          #+#    #+#              #
#    Updated: 2025/04/01 13:51:41 by rcochran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra -MMD -MP
AR			=	ar -rcs
NAME		= 	so_long
BNAME		=	so_long_bonus

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX_PATH 	= ./mlx_macos
else
	MLX_PATH 	= ./mlx_linux
endif
MLX			=	$(MLX_PATH)/libmlx.a



INCLUDES	= -I$(LIBFT_PATH)/includes -I ./includes -I/usr/include -I$(MLX_PATH) -O3
BINCLUDES	= -I$(LIBFT_PATH)/includes -I ./bincludes -I/usr/include -I$(MLX_PATH) -O3

FILES		=	display \
				error \
				exit \
				floor_map \
				game \
				map_validity_utils \
				map_validity \
				map \
				moves \
				pathfinding \
				render

BFILES		=	bad_guy \
				bad_guy_utils \
				defeat \
				display_utils \
				display \
				error \
				exit \
				floor_map \
				game \
				map_validity_utils \
				map_validity \
				map \
				moves_utils \
				moves \
				pathfinding \
				render


MAIN		=	main.c
BMAIN		=	main_bonus.c
# OBJ_MAIN		= 	$(addprefix $(SRC_DIR), $(MAIN:.c=.o))
# OBJ_BMAIN		= 	$(addprefix $(SRC_BDIR), $(BMAIN:.c=.o))

SRC_FILES	=	$(addsuffix .c, $(FILES))
SRC_BFILES	= 	$(addsuffix .c, $(BFILES))

OBJ_DIR		= obj/
BOBJ_DIR	= bobj/

SRC_DIR		= src/
SRC_BDIR	= bonus/

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
BSRC		= 	$(addprefix $(SRC_BDIR), $(SRC_BFILES))

OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
BOBJ		=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(BSRC))

OBJ_MAIN	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_DIR)$(MAIN))
OBJ_BMAIN	=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(SRC_BDIR)$(BMAIN))

all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(BOBJ_DIR)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(BNAME)
	rm -f $(LIBFT)
	rm -f $(MLX)

re : fclean all

$(NAME) : $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJ) $(OBJ_MAIN)
ifeq ($(UNAME), Darwin)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
else
	$(CC) -g3 $(CFLAGS) $(OBJ) $(OBJ_MAIN)  -lX11 -lXext -lm -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -o $(NAME)
endif

$(BNAME) : $(MLX) $(LIBFT) $(BOBJ_DIR) $(BOBJ) $(OBJ_BMAIN)
ifeq ($(UNAME), Darwin)
	$(CC) $(CFLAGS) $(BOBJ) $(OBJ_BMAIN) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)
else
	$(CC) -g3 $(CFLAGS) $(BOBJ) $(OBJ_BMAIN) -lX11 -lXext -lm -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -o $(BNAME)
endif

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
# mkdir -p $(dir $@)
	$(CC) -g3 $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BOBJ_DIR)%.o: $(SRC_BDIR)%.c
# mkdir -p $(dir $@)
	$(CC) -g3 $(CFLAGS) $(INCLUDES) $(BINCLUDES) -c $< -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(BOBJ_DIR) : 
	mkdir -p $(BOBJ_DIR)

debug : $(LIBFT) $(OBJ_DIR) $(OBJ) Makefile
	$(CC) -g3 $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L$(LIBFT_PATH) -lft -o $(NAME)

bonus : $(BNAME)

rebonus: fclean bonus
