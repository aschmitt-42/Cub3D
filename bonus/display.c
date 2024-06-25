/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:48:43 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/25 16:08:34 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	pixel_put(t_game *game, int x, int y, int color)
{
	int	test = y * game->img.size_line / 4 + x;
	*(game->img.addr + test) = color;
}

void	display(t_game *game)
{
	double	wallX;  //where exactly the wall was hit
	double	step;
	double	texPos;
	int		texX;
	int		texY;
	int		color;

	t_image texture = game->NO;
	if (game->ray.side == 1)
		texture = game->EA;
	 
	if (game->ray.side == 0)
		wallX = game->player.posY + game->ray.perpWallDist * game->ray.rayDirY;
	else
		wallX = game->player.posX + game->ray.perpWallDist * game->ray.rayDirX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)(texture.width));
	if(game->ray.side == 0 && game->ray.rayDirX > 0)
		texX = texture.width - texX - 1;
	if(game->ray.side == 1 && game->ray.rayDirY < 0)
		texX = texture.width - texX - 1;
	step = 1.0 * texture.height / game->ray.lineHeight;
	texPos = (game->ray.drawStart - game->ray.h / 2 + game->ray.lineHeight / 2) * step;

	int y = -1;
	int plafond = create_trgb(0, 64,0,64);
	int sol = create_trgb(0, 192,0,192);
	
	while (++y < game->height)
	{
		if (y < game->ray.drawStart)
			pixel_put(game, game->ray.x, y, sol);
		else if (y > game->ray.drawEnd)
			pixel_put(game, game->ray.x, y, plafond);
		else
		{
			texY = (int)texPos & (texture.height - 1);
			texPos += step;
			color = *(int *)((char *)texture.addr + (texY * texture.size_line + texX * (texture.bpp / 8)));
			pixel_put(game, game->ray.x, y, color);
		}
	}
}
