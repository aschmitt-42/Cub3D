/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:34:49 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/28 02:23:39 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player_pixel(t_game *game, int center[2], int xy[2], int radius)
{
	int	x;
	int	y;

	x = xy[0];
	y = xy[1];
	if (x * x + y * y <= radius * radius)
	{
		if (game->player.dirx < 0.75 && game->player.dirx > -0.75
			&& game->player.planex < 0 && x < -game->minimap.width / 40)
			pixel_put(game, center[0] + x, center[1] + y, 16711680);
		else if (game->player.dirx < 0.75 && game->player.dirx > -0.75
			&& game->player.planex > 0 && x > game->minimap.width / 40)
			pixel_put(game, center[0] + x, center[1] + y, 16711680);
		else if (game->player.dirx < -0.75 && game->player.dirx > -1
			&& y < -game->minimap.width / 40)
			pixel_put(game, center[0] + x, center[1] + y, 16711680);
		else if (game->player.dirx < 1 && game->player.dirx >= 0.75
			&& y > game->minimap.width / 40)
			pixel_put(game, center[0] + x, center[1] + y, 16711680);
		else
			pixel_put(game, center[0] + x, center[1] + y, 4144959);
	}
}

void	draw_player(t_game *game, int centerx, int centery, int radius)
{
	int	xy[2];
	int	center[2];

	center[0] = centerx;
	center[1] = centery;
	xy[0] = -radius;
	while (xy[0] <= radius)
	{
		xy[1] = -radius;
		while (xy[1] <= radius)
		{
			put_player_pixel(game, center, xy, radius);
			xy[1]++;
		}
		xy[0]++;
	}
}

void	draw_border(t_game *game)
{
	int	i;
	int	color;

	i = 0;
	color = create_rgb(255, 215, 46);
	while (i <= game->minimap.width)
	{
		pixel_put(game, game->minimap.width + 1, i, color);
		pixel_put(game, game->minimap.width + 2, i, color);
		i++;
	}
	i = 0;
	while (i <= game->minimap.width + 2)
	{
		pixel_put(game, i, game->minimap.width + 1, color);
		pixel_put(game, i, game->minimap.width + 2, color);
		i++;
	}
}

int	is_in_map(t_game *game, double x, double y)
{
	if (x < 0 || y < 0)
		return (0);
	if ((int)y >= game->map_y_scale
		|| (size_t)x >= ft_strlen(game->map[(int)y]))
		return (0);
	return (1);
}

void	draw_line(t_game *game, int *pixel, double *pos)
{
	int	color;
	int	last_pos;

	while (pixel[0] <= game->minimap.width)
	{
		last_pos = (int)pos[0];
		if (!is_in_map(game, pos[0], pos[1])
			|| is_wspace(game->map[(int)pos[1]][(int)pos[0]]))
			color = 0;
		else if (game->map[(int)pos[1]][(int)pos[0]] == '1')
			color = 4144959;
		else
			color = 14474460;
		while (last_pos == (int)pos[0] && pixel[0] <= game->minimap.width)
		{
			pixel_put(game, pixel[0], pixel[1], color);
			pos[0] += game->minimap.scale;
			pixel[0]++;
		}
	}
}
