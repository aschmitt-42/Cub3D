/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:48:43 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/20 17:24:39 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	display(t_game *game)
{
	t_image texture = game->NO;
	if (game->ray.side == 1)
		texture = game->EA;
	double wallX; //where exactly the wall was hit
	if (game->ray.side == 0)
		wallX = game->player.posY + game->ray.perpWallDist * game->ray.rayDirY;
	else
		wallX = game->player.posX + game->ray.perpWallDist * game->ray.rayDirX;
	wallX -= floor((wallX));
	int texX = (int)(wallX * (double)(texture.width));
	if(game->ray.side == 0 && game->ray.rayDirX > 0)
		texX = texture.width - texX - 1;
	if(game->ray.side == 1 && game->ray.rayDirY < 0)
		texX = texture.width - texX - 1;
	double step = 1.0 * texture.height / game->ray.lineHeight;
	double texPos = (game->ray.drawStart - game->ray.h / 2 + game->ray.lineHeight / 2) * step;
	int plafond = create_trgb(0, 64,0,64);
	int sol = create_trgb(0, 192,0,192);
	int	y = -1;
	while (++y < game->height)
	{
		if (y < game->ray.drawStart)
			mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->ray.x, y, sol);
		else if (y > game->ray.drawEnd)
			mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->ray.x, y, plafond);
		else
		{
			int texY = (int)texPos & (texture.height - 1);
			texPos += step;
			int color = *(int *)((char *)texture.addr + (texY * texture.size_line + texX * (texture.bpp / 8)));
			mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->ray.x, y, color);
		}
	}
}

	/*int n;
	int color;
	int	y;

	if (game->ray.side == 1)
		n = 127;
	else
		n = 255;
	if (game->map[game->ray.mapX][game->ray.mapY] == '1')
		color = create_trgb(0, n, 0, 0);
	else if (game->map[game->ray.mapX][game->ray.mapY] == '2')
		color = create_trgb(0, 0, n, 0);
	else if (game->map[game->ray.mapX][game->ray.mapY] == '3')
		color = create_trgb(0, 0, 0, n);
	else if (game->map[game->ray.mapX][game->ray.mapY] == '4')
		color = create_trgb(0, n, n, n);
	else
		color = create_trgb(0, n, n, 0);
	int plafond = create_trgb(0, 64,0,64);
	int sol = create_trgb(0, 192,0,192);
	y = -1;
	while (++y < game->height)
	{
		if (y < game->ray.drawStart)
			mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->ray.x, y, sol);
		else if (y > game->ray.drawEnd)
			mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->ray.x, y, plafond);
		else
			mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->ray.x, y, color);
	}*/