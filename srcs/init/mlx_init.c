/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:14:43 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/24 01:14:37 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_game *game)
{
	free_game(game, 10);
	return (0);
}

void	init_minimap(t_game *game)
{
	game->minimap.enable = 0;
	game->minimap.width = game->width / 8;
	game->minimap.img.img = mlx_new_image(game->mlibx.mlx_ptr, game->minimap.width, game->minimap.width); 
	game->minimap.img.addr = (int *)mlx_get_data_addr(game->minimap.img.img, &game->minimap.img.bpp, &game->minimap.img.size_line, &game->minimap.img.endian);
}//verif et free
void	init_mlx(t_game *game)
{
	game->mlibx.win_ptr = mlx_new_window
		(game->mlibx.mlx_ptr, game->width, game->height, "Cub3D");
	if (!game->mlibx.win_ptr)
		free_game(game, 1);
	init_vecteur(game);
	// draw(game);
	mlx_hook(game->mlibx.win_ptr, 17, 1L << 0, close_win, game);
	mlx_hook(game->mlibx.win_ptr, 2, 1L << 0, key_press, game);
	init_minimap(game);
	mlx_loop_hook(game->mlibx.mlx_ptr, play, game);
	mlx_hook(game->mlibx.win_ptr, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlibx.mlx_ptr);
}
