/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:12 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/20 15:34:22 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key.z = 1;
	else if (keycode == 115)
		game->key.s = 1;
	else if (keycode == 100)
		game->key.d = 1;
	else if (keycode == 97)
		game->key.q = 1;
	else if (keycode == 65361)
		game->key.left = 1;
	else if (keycode == 65363)
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
	else if (keycode == 100)
		game->key.d = 0;
	else if (keycode == 97)
		game->key.q = 0;
	else if (keycode == 65361)
		game->key.left = 0;
	else if (keycode == 65363)
		game->key.right = 0;
	return (0);
}

void    move_lr(t_game *game)
{
	double oldDirX;
	double oldPlaneX;

	if (game->key.left)
	{
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-game->rotSpeed) - game->player.dirY * sin(-game->rotSpeed);
		game->player.dirY = oldDirX * sin(-game->rotSpeed) + game->player.dirY * cos(-game->rotSpeed);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-game->rotSpeed) - game->player.planeY * sin(-game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(-game->rotSpeed) + game->player.planeY * cos(-game->rotSpeed);
	}
	if (game->key.right)
	{
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(game->rotSpeed) - game->player.dirY * sin(game->rotSpeed);
		game->player.dirY = oldDirX * sin(game->rotSpeed) + game->player.dirY * cos(game->rotSpeed);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(game->rotSpeed) - game->player.planeY * sin(game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(game->rotSpeed) + game->player.planeY * cos(game->rotSpeed);
	}
}

void    move_updown(t_game *game)
{
	int x;
	int y;

	if (game->key.z)
	{
		x = game->player.posX + game->player.dirX * game->moveSpeed;
		y = game->player.posY;
		if(game->map[x] && game->map[x][y] == '0')
			game->player.posX += game->player.dirX * game->moveSpeed;
		x =	game->player.posX;
		y = game->player.posY + game->player.dirY * game->moveSpeed;
		if(game->map[x] && game->map[x][y] == '0')
			game->player.posY += game->player.dirY * game->moveSpeed;
	}
	if (game->key.s)
	{
		x = game->player.posX - game->player.dirX * game->moveSpeed;
		y = game->player.posY;
		if(game->map[x] && game->map[x][y] == '0')
			game->player.posX -= game->player.dirX * game->moveSpeed;
		x =	game->player.posX;
		y = game->player.posY - game->player.dirY * game->moveSpeed;
		if(game->map[x] && game->map[x][y] == '0')
			game->player.posY -= game->player.dirY * game->moveSpeed;
	}
}
void	move_side(t_game *game)
{
	int x;
	int y;

	if (game->key.d)
	{
		x = game->player.posX - game->player.dirY * (game->moveSpeed * 2);
		y = game->player.posY;
		if(game->map[x][y] == '0')
			game->player.posX -= game->player.dirY * game->moveSpeed;
		x = game->player.posX;
		y = game->player.posY + game->player.dirX * (game->moveSpeed * 2);
		if(game->map[x][y] == '0')
			game->player.posY += game->player.dirX * game->moveSpeed;
	}
	if (game->key.q)
	{
		x = game->player.posX + game->player.dirY * (game->moveSpeed * 2);
		y = game->player.posY;
		if(game->map[x][y] == '0')
			game->player.posX += game->player.dirY * game->moveSpeed;
		x = game->player.posX;
		y = game->player.posY - game->player.dirX * (game->moveSpeed * 2);
		if(game->map[x][y] == '0')
			game->player.posY -= game->player.dirX * game->moveSpeed;
	}
}

int	play(t_game *game)
{
	draw(game);
	move_lr(game);
	move_updown(game);
	move_side(game);
	return (0);
}
