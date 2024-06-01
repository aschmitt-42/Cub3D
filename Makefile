# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:06:26 by aschmitt          #+#    #+#              #
#    Updated: 2024/06/01 14:43:06 by eboumaza         ###   ########.fr        #
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
LDFLAGS 	= -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11
LIB 		= inc/ml/libmlx.a inc/ml/libmlx_Linux.a
RM			= rm -f

SRC 		= $(SRC_DIR)main.c \
			  $(SRC_DIR)free_game.c \
			  $(SRC_DIR)$(INIT_DIR)map_init.c \
			  $(SRC_DIR)$(INIT_DIR)mlx_init.c \
			  $(SRC_DIR)$(INIT_DIR)map_utils.c \
			  $(SRC_DIR)$(LIBFT_DIR)gnl.c \
			  $(SRC_DIR)$(LIBFT_DIR)utils1.c \
			  $(SRC_DIR)$(LIBFT_DIR)utils2.c \

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
