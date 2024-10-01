# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:06:26 by aschmitt          #+#    #+#              #
#    Updated: 2024/10/01 14:25:52 by eboumaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3d
NAME_BONUS	= cub3d_bonus

INC			= inc/
SRC_DIR		= srcs/
SRC_BONUS_DIR = bonus/
GAME_DIR	= game/
INIT_DIR	= init/
LIBFT_DIR	= libft_functions/
OBJ_DIR		= obj/
OBJ_DIR_BONUS = obj_bonus/

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -I
LDFLAGS 	= -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm
LIB 		= ml/libmlx.a ml/libmlx_Linux.a
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
			  $(SRC_DIR)$(INIT_DIR)map_utils3.c \
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
			  $(SRC_BONUS_DIR)$(INIT_DIR)map_utils3.c \
			  $(SRC_BONUS_DIR)$(LIBFT_DIR)gnl.c \
			  $(SRC_BONUS_DIR)$(LIBFT_DIR)utils1.c \
			  $(SRC_BONUS_DIR)$(LIBFT_DIR)utils2.c

OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

OBJ_BONUS 	= $(patsubst $(SRC_BONUS_DIR)%.c,$(OBJ_DIR_BONUS)%.o,$(SRC_BONUS))

MAKE_ML = $(MAKE) -C ml/

G = "\033[32m"
X = "\033[0m"


all: 	$(NAME)
		

$(NAME):	$(OBJ)
			$(MAKE_ML)
			$(CC) $^ $(LIB) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC)*.h Makefile $(INC)
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus:          $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
				$(MAKE_ML)	
				$(CC) $^ $(LIB) $(LDFLAGS) -o $(NAME_BONUS)
			
$(OBJ_DIR_BONUS)%.o:	$(SRC_BONUS_DIR)%.c $(INC)*.h Makefile
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			$(MAKE_ML) clean
			$(RM) -r $(OBJ_DIR)
			$(RM) -r $(OBJ_DIR_BONUS)

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
