/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:45:06 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/25 17:15:56 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_border(t_game *game)
{
	int	i;
	int	color;

	i = 0;
	color = create_trgb(0, 255, 215, 46);
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
	if ((int)y >= game->map_y_scale || (size_t)x >= ft_strlen(game->map[(int)y]))
		return (0);
	return (1);
}

void	draw_map(t_game *game)
{
	int		color;
	int 	last_pos;
	double	scale;
	int		pixel[2];
	double	pos[2];

	scale = 1 / (game->minimap.width * 0.1);
	pos[1] = game->player.posX - 5;
	pixel[1] = 0;
	while (pixel[1] <= game->minimap.width)
	{
		pos[0] = game->player.posY - 5;
		pixel[0] = 0;
		while (pixel[0] <= game->minimap.width)
		{
			last_pos = (int)pos[0];
			if (!is_in_map(game, pos[0], pos[1]) || is_wspace(game->map[(int)pos[1]][(int)pos[0]]))
				color = 0;//create_trgb(255, 20, 10, 8);
			else if (game->map[(int)pos[1]][(int)pos[0]] == '1')
				color = create_trgb(0, 63, 63, 63);
			else
				color = create_trgb(0, 220, 220, 220);
			while (last_pos == (int)pos[0] && pixel[0] <= game->minimap.width)
			{
				pixel_put(game, pixel[0], pixel[1], color);
				pos[0] += scale;
				pixel[0]++;
			}
		}
		pixel[1]++;
		pos[1] += scale;
	}
}

void	draw_player(t_game *game)
{
	(void)game;
}

void	mini_map(t_game *game)
{
	draw_border(game);
	draw_map(game);
	//draw_player(game);
}