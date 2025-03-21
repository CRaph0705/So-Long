# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 17:53:43 by rcochran          #+#    #+#              #
#    Updated: 2025/03/19 17:19:05 by rcochran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
AR			=	ar -rcs
NAME		= 	so_long
# BNAME		=	

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

INCLUDES	= -I$(LIBFT_PATH)/includes -I ./includes
# BINCLUDES	=	-I ./bonus

FILES		= 	actions \
				display \
				error \
				exit \
				keybind \
				map_validity \
				map_validity_utils \
				map \
				moves \
				pathfinding \
				start

MAIN		=	main.c
# BMAIN		=	main_bonus.c
# OBJ_MAIN		= 	$(addprefix $(SRC_DIR), $(MAIN:.c=.o))
# OBJ_BMAIN		= 	$(addprefix $(SRC_BDIR), $(BMAIN:.c=.o))

SRC_FILES	=	$(addsuffix .c, $(FILES))
# SRC_BFILES	= 	$(addsuffix .c, $(BFILES))

OBJ_DIR		= obj/
# BOBJ_DIR	= bobj/

SRC_DIR		= src/
# SRC_BDIR	= bonus/

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
# BSRC		= 	$(addprefix $(SRC_BDIR), $(SRC_BFILES))

OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
# BOBJ		=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(BSRC))

OBJ_MAIN	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_DIR)$(MAIN))
# OBJ_BMAIN	=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(SRC_BDIR)$(BMAIN))

all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(BOBJ_DIR)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f checker

re : fclean all

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ) $(OBJ_MAIN)
	$(CC) -g3 $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L$(LIBFT_PATH) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

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

# bonus: $(NAME)

# rebonus: fclean bonus
