/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:12 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 22:15:35 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 109 && game->minimap.enable == 1)
	{
		game->minimap.enable = 0;
		draw(game);
	}
	else if (keycode == 109)
	{
		game->minimap.enable = 1;
		draw(game);
	}
	else if (keycode == 119)
		game->key.z = 1;
	else if (keycode == 115)
		game->key.s = 1;
	else if (keycode == 97)
		game->key.d = 1;
	else if (keycode == 100)
		game->key.q = 1;
	else if (keycode == 65363)
		game->key.left = 1;
	else if (keycode == 65361)
		game->key.right = 1;
	else if (keycode == 65307)
		close_win(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key.z = 0;
	else if (keycode == 115)
		game->key.s = 0;
	else if (keycode == 97)
		game->key.d = 0;
	else if (keycode == 100)
		game->key.q = 0;
	else if (keycode == 65363)
		game->key.left = 0;
	else if (keycode == 65361)
		game->key.right = 0;
	return (0);
}

int	play(t_game *game)
{
	int	n;

	n = move_lr(game);
	n = move_updown(game) || n;
	n = move_side(game) || n;
	if (n)
		draw(game);
	return (0);
}
