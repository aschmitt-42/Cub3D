/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:12 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 19:36:34 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(game->rotSpeed)
		- game->player.dirY * sin(game->rotSpeed);
	game->player.dirY = olddirx * sin(game->rotSpeed)
		+ game->player.dirY * cos(game->rotSpeed);
	oldplanex = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(game->rotSpeed)
		- game->player.planeY * sin(game->rotSpeed);
	game->player.planeY = oldplanex * sin(game->rotSpeed)
		+ game->player.planeY * cos(game->rotSpeed);
}

int	move_lr(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	if (game->key.left)
	{
		olddirx = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-game->rotSpeed)
			- game->player.dirY * sin(-game->rotSpeed);
		game->player.dirY = olddirx * sin(-game->rotSpeed)
			+ game->player.dirY * cos(-game->rotSpeed);
		oldplanex = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-game->rotSpeed)
			- game->player.planeY * sin(-game->rotSpeed);
		game->player.planeY = oldplanex * sin(-game->rotSpeed)
			+ game->player.planeY * cos(-game->rotSpeed);
		return (1);
	}
	if (game->key.right)
		return (turn_right(game), 1);
	return (0);
}

int	move_updown(t_game *game)
{
	int	n;

	if (game->key.z)
	{
		n = game->player.posX + game->player.dirX * game->moveSpeed;
		if (game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX += game->player.dirX * game->moveSpeed;
		n = game->player.posY + game->player.dirY * game->moveSpeed;
		if (game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY += game->player.dirY * game->moveSpeed;
		return (1);
	}
	if (game->key.s)
	{
		n = game->player.posX - game->player.dirX * game->moveSpeed;
		if (game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX -= game->player.dirX * game->moveSpeed;
		n = game->player.posY - game->player.dirY * game->moveSpeed;
		if (game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY -= game->player.dirY * game->moveSpeed;
		return (1);
	}
	return (0);
}

int	move_side(t_game *game)
{
	int	n;

	if (game->key.d)
	{
		n = game->player.posX - game->player.dirY * (game->moveSpeed * 2);
		if (game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX -= game->player.dirY * game->moveSpeed;
		n = game->player.posY + game->player.dirX * (game->moveSpeed * 2);
		if (game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY += game->player.dirX * game->moveSpeed;
		return (1);
	}
	if (game->key.q)
	{
		n = game->player.posX + game->player.dirY * (game->moveSpeed * 2);
		if (game->map[n][(int)(game->player.posY)] == '0')
			game->player.posX += game->player.dirY * game->moveSpeed;
		n = game->player.posY - game->player.dirX * (game->moveSpeed * 2);
		if (game->map[(int)(game->player.posX)][n] == '0')
			game->player.posY -= game->player.dirX * game->moveSpeed;
		return (1);
	}
	return (0);
}
