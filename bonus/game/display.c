/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:48:43 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 23:09:12 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_game *game, int x, int y, int color)
{
	int	test;

	test = y * game->img.size_line / 4 + x;
	*(game->img.addr + test) = color;
}

void	put_texture(t_game *game, t_image *texture, int texX)
{
	double	texpos;
	double	step;
	int		y;
	int		color;
	int		texy;

	step = 1.0 * texture->height / game->ray.lineHeight;
	texpos = (game->ray.drawStart - game->ray.h / 2
			+ game->ray.lineHeight / 2) * step;
	y = -1;
	while (++y < game->height)
	{
		if (y < game->ray.drawStart)
			pixel_put(game, game->ray.x, y, game->F);
		else if (y > game->ray.drawEnd)
			pixel_put(game, game->ray.x, y, game->C);
		else
		{
			texy = (int)texpos & (texture->height - 1);
			texpos += step;
			color = *(int *)((char *)texture->addr
					+ (texy * texture->size_line + texX * (texture->bpp / 8)));
			pixel_put(game, game->ray.x, y, color);
		}
	}
}

void	display(t_game *game)
{
	double	wallx;
	int		texx ;
	t_image	texture;

	if (game->ray.side == 0 && game->ray.rayDirX >= 0)
		texture = game->NO;
	if (game->ray.side == 0 && game->ray.rayDirX < 0)
		texture = game->SO;
	if (game->ray.side == 1 && game->ray.rayDirY < 0)
		texture = game->EA;
	if (game->ray.side == 1 && game->ray.rayDirY >= 0)
		texture = game->WE;
	if (game->ray.side == 0)
		wallx = game->player.posY + game->ray.perpWallDist * game->ray.rayDirY;
	else
		wallx = game->player.posX + game->ray.perpWallDist * game->ray.rayDirX;
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)(texture.width));
	if (game->ray.side == 0 && game->ray.rayDirX > 0)
		texx = texture.width - texx - 1;
	if (game->ray.side == 1 && game->ray.rayDirY < 0)
		texx = texture.width - texx - 1;
	put_texture(game, &texture, texx);
}
