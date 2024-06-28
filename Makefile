# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:06:26 by aschmitt          #+#    #+#              #
#    Updated: 2024/06/28 02:27:50 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

INC			= inc/
SRC_DIR		= srcs/
SRC_BONUS_DIR = bonus/
GAME_DIR	= game/
INIT_DIR	= init/
LIBFT_DIR	= libft_functions/
OBJ_DIR		= obj/
OBJ_DIR_BONUS = obj_bonus/

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -I
LDFLAGS 	= -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm
LIB 		= inc/ml/libmlx.a inc/ml/libmlx_Linux.a
RM			= rm -f

SRC			= $(SRC_DIR)$(GAME_DIR)main.c \
			  $(SRC_DIR)$(GAME_DIR)free_game.c \
			  $(SRC_DIR)$(GAME_DIR)dda.c \
			  $(SRC_DIR)$(GAME_DIR)display.c \
			  $(SRC_DIR)$(GAME_DIR)draw.c \
			  $(SRC_DIR)$(GAME_DIR)key.c \
			  $(SRC_DIR)$(GAME_DIR)key_utils.c \
			  $(SRC_DIR)$(INIT_DIR)vecteur_init.c \
			  $(SRC_DIR)$(INIT_DIR)map_init.c \
			  $(SRC_DIR)$(INIT_DIR)mlx_init.c \
			  $(SRC_DIR)$(INIT_DIR)map_utils1.c \
			  $(SRC_DIR)$(INIT_DIR)map_utils2.c \
			  $(SRC_DIR)$(LIBFT_DIR)gnl.c \
			  $(SRC_DIR)$(LIBFT_DIR)utils1.c \
			  $(SRC_DIR)$(LIBFT_DIR)utils2.c

SRC_BONUS = $(SRC_BONUS_DIR)$(GAME_DIR)main.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)free_game.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)dda.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)display.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)draw.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)key.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)mini_map.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)mini_map_utils.c \
			  $(SRC_BONUS_DIR)$(GAME_DIR)key_utils.c \
			  $(SRC_BONUS_DIR)$(INIT_DIR)vecteur_init.c \
			  $(SRC_BONUS_DIR)$(INIT_DIR)map_init.c \
			  $(SRC_BONUS_DIR)$(INIT_DIR)mlx_init.c \
			  $(SRC_BONUS_DIR)$(INIT_DIR)map_utils1.c \
			  $(SRC_BONUS_DIR)$(INIT_DIR)map_utils2.c \
			  $(SRC_BONUS_DIR)$(LIBFT_DIR)gnl.c \
			  $(SRC_BONUS_DIR)$(LIBFT_DIR)utils1.c \
			  $(SRC_BONUS_DIR)$(LIBFT_DIR)utils2.c

OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

OBJ_BONUS 	= $(patsubst $(SRC_BONUS_DIR)%.c,$(OBJ_DIR_BONUS)%.o,$(SRC_BONUS))

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

bonus:	$(OBJ_BONUS)
			@echo $(G)Compiling [$(SRC_BONUS)]$(X)
			@$(CC) $^ $(LIB) $(LDFLAGS) -o $(NAME)
			@echo $(G)Compiling [$(NAME)]$(X)
			
$(OBJ_DIR_BONUS)%.o:	$(SRC_BONUS_DIR)%.c $(INC)*.h Makefile
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@echo $(G)Delete [Obj]$(X)	
			@$(RM) -r $(OBJ_DIR)
			@$(RM) -r $(OBJ_DIR_BONUS)

fclean: 	clean
			@echo $(G)Delete [$(NAME)]$(X)	
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
