# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:06:26 by aschmitt          #+#    #+#              #
#    Updated: 2024/06/20 17:25:59 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

INC			= inc/
SRC_DIR		= srcs/
INIT_DIR	= init/
LIBFT_DIR	= libft_functions/
OBJ_DIR		= obj/

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g3 -I
#CFLAGS 		= -I
LDFLAGS 	= -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm
LIB 		= inc/ml/libmlx.a inc/ml/libmlx_Linux.a
RM			= rm -f

SRC 		= $(SRC_DIR)main.c \
			  $(SRC_DIR)free_game.c \
			  $(SRC_DIR)dda.c \
			  $(SRC_DIR)display.c \
			  $(SRC_DIR)draw.c \
			  $(SRC_DIR)key.c \
			  $(SRC_DIR)$(INIT_DIR)vecteur_init.c \
			  $(SRC_DIR)$(INIT_DIR)map_init.c \
			  $(SRC_DIR)$(INIT_DIR)mlx_init.c \
			  $(SRC_DIR)$(INIT_DIR)map_utils1.c \
			  $(SRC_DIR)$(INIT_DIR)map_utils2.c \
			  $(SRC_DIR)$(LIBFT_DIR)gnl.c \
			  $(SRC_DIR)$(LIBFT_DIR)utils1.c \
			  $(SRC_DIR)$(LIBFT_DIR)utils2.c 


# $(SRC_DIR)no_texture.c


OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

G = "\033[32m"
X = "\033[0m"

all: 		$(NAME)

$(NAME):	$(OBJ)
			@echo $(G)Compiling [$(SRC)]$(X)
			@$(CC) $^ $(LIB) $(LDFLAGS) -o $(NAME)
			@echo $(G)Compiling [$(NAME)]$(X)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC)*.h Makefile
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@echo $(G)Delete [Obj]$(X)	
			@$(RM) -r $(OBJ_DIR)

fclean: 	clean
			@echo $(G)Delete [$(NAME)]$(X)	
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
