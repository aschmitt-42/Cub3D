/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:14:43 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/27 23:05:55 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_game *game)
{
	free_game(game, 10);
	return (0);
}

void	init_mlx(t_game *game)
{
	game->mlibx.win_ptr = mlx_new_window
		(game->mlibx.mlx_ptr, game->width, game->height, "Cub3D");
	if (!game->mlibx.win_ptr)
		free_game(game, 1);
	game->img.img = mlx_new_image(game->mlibx.mlx_ptr,
			game->width, game->height);
	if (!game->img.img)
		free_game(game, 1);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_line, &game->img.endian);
	init_vecteur(game);
	game->minimap.enable = 0;
	game->minimap.width = game->width / 8;
	draw(game);
	mlx_hook(game->mlibx.win_ptr, 17, 1L << 0, close_win, game);
	mlx_hook(game->mlibx.win_ptr, 2, 1L << 0, key_press, game);
	mlx_loop_hook(game->mlibx.mlx_ptr, play, game);
	mlx_hook(game->mlibx.win_ptr, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlibx.mlx_ptr);
}
