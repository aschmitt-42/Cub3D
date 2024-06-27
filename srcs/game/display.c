/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:48:43 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 23:27:15 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	pixel_put(t_game *game, int x, int y, int color)
{
	int	test;

	test = y * game->img.size_line / 4 + x;
	*(game->img.addr + test) = color;
}

void	test(t_game *game, t_image *texture, int texX)
{
	double	texpos;
	double	step;
	int		y;
	int		color;
	int		texy;

	step = 1.0 * texture->height / game->ray.lineheight;
	texpos = (game->ray.drawstart - game->ray.h / 2
			+ game->ray.lineheight / 2) * step;
	y = -1;
	while (++y < game->height)
	{
		if (y < game->ray.drawstart)
			pixel_put(game, game->ray.x, y, game->f);
		else if (y > game->ray.drawend)
			pixel_put(game, game->ray.x, y, game->c);
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

	if (game->ray.side == 0 && game->ray.raydirx >= 0)
		texture = game->no;
	if (game->ray.side == 0 && game->ray.raydirx < 0)
		texture = game->so;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		texture = game->ea;
	if (game->ray.side == 1 && game->ray.raydiry >= 0)
		texture = game->we;
	if (game->ray.side == 0)
		wallx = game->player.posy + game->ray.perpwalldist * game->ray.raydiry;
	else
		wallx = game->player.posx + game->ray.perpwalldist * game->ray.raydirx;
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)(texture.width));
	if (game->ray.side == 0 && game->ray.raydirx > 0)
		texx = texture.width - texx - 1;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		texx = texture.width - texx - 1;
	test(game, &texture, texx);
}
