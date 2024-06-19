/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:48:43 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/19 16:54:45 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	display(t_game *game)
{
	int n;
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
	}
}
