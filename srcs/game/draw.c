/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:58:44 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 19:05:05 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sidedist(t_game *game)
{
	if (game->ray.rayDirX < 0)
	{
		game->ray.stepX = -1;
		game->ray.sideDistX = (game->player.posX - game->ray.mapX)
			* game->ray.deltaDistX;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sideDistX = (game->ray.mapX + 1.0 - game->player.posX)
			* game->ray.deltaDistX;
	}
	if (game->ray.rayDirY < 0)
	{
		game->ray.stepY = -1;
		game->ray.sideDistY = (game->player.posY - game->ray.mapY)
			* game->ray.deltaDistY;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sideDistY = (game->ray.mapY + 1.0 - game->player.posY)
			* game->ray.deltaDistY;
	}
}

void	init_value(t_game *game)
{
	game->ray.cameraX = 2 * game->ray.x / (double)(game->width) - 1;
	game->ray.rayDirX = game->player.dirX + game->player.planeX
		* game->ray.cameraX;
	game->ray.rayDirY = game->player.dirY + game->player.planeY
		* game->ray.cameraX;
	game->ray.mapX = game->player.posX;
	game->ray.mapY = game->player.posY;
	if (game->ray.rayDirX == 0)
		game->ray.deltaDistX = 1e30;
	else
		game->ray.deltaDistX = fabs(1 / game->ray.rayDirX);
	if (game->ray.rayDirY == 0)
		game->ray.deltaDistY = 1e30;
	else
		game->ray.deltaDistY = fabs(1 / game->ray.rayDirY);
	game->ray.hit = 0;
	init_sidedist(game);
}

void	draw(t_game *game)
{
	game->ray.x = -1;
	while (++game->ray.x < game->width)
	{
		init_value(game);
		performe_dda(game);
		display(game);
	}
	mlx_put_image_to_window(game->mlibx.mlx_ptr,
		game->mlibx.win_ptr, game->img.img, 0, 0);
}
