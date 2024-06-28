/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 02:23:17 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/28 02:23:31 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_game *game)
{
	int		pixel[2];
	double	pos[2];

	pos[1] = game->player.posx - 5;
	pixel[1] = 0;
	while (pixel[1] <= game->minimap.width)
	{
		pos[0] = game->player.posy - 5;
		pixel[0] = 0;
		draw_line(game, pixel, pos);
		pixel[1]++;
		pos[1] += game->minimap.scale;
	}
}

void	mini_map(t_game *game)
{
	draw_border(game);
	draw_map(game);
	draw_player(game, game->minimap.width / 2,
		game->minimap.width / 2, game->minimap.width / 20);
}
