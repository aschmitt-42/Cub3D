/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:12 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/26 01:17:40 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_game *game)
{
	if (keycode == 119)
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

int		key_release(int keycode, t_game *game)
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

int	move_lr(t_game *game)
{
	double	oldDirX;
	double	oldPlaneX;

	if (game->key.left)
	{
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-game->rotSpeed) - game->player.dirY * sin(-game->rotSpeed);
		game->player.dirY = oldDirX * sin(-game->rotSpeed) + game->player.dirY * cos(-game->rotSpeed);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-game->rotSpeed) - game->player.planeY * sin(-game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(-game->rotSpeed) + game->player.planeY * cos(-game->rotSpeed);
		return (1);
	}
	if (game->key.right)
	{
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(game->rotSpeed) - game->player.dirY * sin(game->rotSpeed);
		game->player.dirY = oldDirX * sin(game->rotSpeed) + game->player.dirY * cos(game->rotSpeed);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(game->rotSpeed) - game->player.planeY * sin(game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(game->rotSpeed) + game->player.planeY * cos(game->rotSpeed);
		return (1);
	}
	return (0);
}

int    move_updown(t_game *game)
{
	int n;

	if (game->key.z)
	{
		n = game->player.posX + game->player.dirX * game->moveSpeed;
		if(game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX += game->player.dirX * game->moveSpeed;
		n = game->player.posY + game->player.dirY * game->moveSpeed;
		if(game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY += game->player.dirY * game->moveSpeed;
		return (1);
	}
	if (game->key.s)
	{
		n = game->player.posX - game->player.dirX * game->moveSpeed;
		if(game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX -= game->player.dirX * game->moveSpeed;
		n = game->player.posY - game->player.dirY * game->moveSpeed;
		if(game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY -= game->player.dirY * game->moveSpeed;
		return (1);
	}
	return (0);
}
int	move_side(t_game *game)
{
	int n;

	if (game->key.d)
	{
		n = game->player.posX - game->player.dirY * (game->moveSpeed * 2);
		if(game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX -= game->player.dirY * game->moveSpeed;
		n = game->player.posY + game->player.dirX * (game->moveSpeed * 2);
		if(game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY += game->player.dirX * game->moveSpeed;
		return (1);
	}
	if (game->key.q)
	{
		n = game->player.posX + game->player.dirY * (game->moveSpeed * 2);
		if(game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX += game->player.dirY * game->moveSpeed;
		n = game->player.posY - game->player.dirX * (game->moveSpeed * 2);
		if(game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY -= game->player.dirX * game->moveSpeed;
		return (1);
	}
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
