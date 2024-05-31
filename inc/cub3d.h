/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:34:13 by aschmitt          #+#    #+#             */
/*   Updated: 2024/05/31 22:58:06 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "ml/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

typedef struct s_game
{
	int			width;
	int			height;
	char		**map;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	t_data		minilib;
}				t_game;

// construct
void	game_construct(t_game *game);

// free

void	free_map(t_game *game);
void 	free_game(t_game *game, int error_code);

// init

void	init_map(char *file, t_game *game);
void	init_mlx(t_game *game);

// game

void	cub3d(t_game *game);

#endif