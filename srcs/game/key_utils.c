/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:12 by aschmitt          #+#    #+#             */
/*   Updated: 2024/07/16 10:32:33 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(game->rotspeed)
		- game->player.diry * sin(game->rotspeed);
	game->player.diry = olddirx * sin(game->rotspeed)
		+ game->player.diry * cos(game->rotspeed);
	oldplanex = game->player.planex;
	game->player.planex = game->player.planex * cos(game->rotspeed)
		- game->player.planey * sin(game->rotspeed);
	game->player.planey = oldplanex * sin(game->rotspeed)
		+ game->player.planey * cos(game->rotspeed);
}

int	move_lr(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	if (game->key.left)
	{
		olddirx = game->player.dirx;
		game->player.dirx = game->player.dirx * cos(-game->rotspeed)
			- game->player.diry * sin(-game->rotspeed);
		game->player.diry = olddirx * sin(-game->rotspeed)
			+ game->player.diry * cos(-game->rotspeed);
		oldplanex = game->player.planex;
		game->player.planex = game->player.planex * cos(-game->rotspeed)
			- game->player.planey * sin(-game->rotspeed);
		game->player.planey = oldplanex * sin(-game->rotspeed)
			+ game->player.planey * cos(-game->rotspeed);
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
		n = game->player.posx + game->player.dirx * game->movespeed;
		if (game->map[n][(int)(game->player.posy)] == '0')
			game->player.posx += game->player.dirx * game->movespeed;
		n = game->player.posy + game->player.diry * game->movespeed;
		if (game->map[(int)(game->player.posx)][n] == '0')
			game->player.posy += game->player.diry * game->movespeed;
		return (1);
	}
	if (game->key.s)
	{
		n = game->player.posx - game->player.dirx * game->movespeed;
		if (game->map[n][(int)(game->player.posy)] == '0')
			game->player.posx -= game->player.dirx * game->movespeed;
		n = game->player.posy - game->player.diry * game->movespeed;
		if (game->map[(int)(game->player.posx)][n] == '0')
			game->player.posy -= game->player.diry * game->movespeed;
		return (1);
	}
	return (0);
}

int	move_side(t_game *game)
{
	int	n;

	if (game->key.d)
	{
		n = game->player.posx - game->player.diry * (game->movespeed * 2);
		if (game->map[n][(int)(game->player.posy)] == '0')
			game->player.posx -= game->player.diry * game->movespeed;
		n = game->player.posy + game->player.dirx * (game->movespeed * 2);
		if (game->map[(int)(game->player.posx)][n] == '0')
			game->player.posy += game->player.dirx * game->movespeed;
		return (1);
	}
	if (game->key.q)
	{
		n = game->player.posx + game->player.diry * (game->movespeed * 2);
		if (game->map[n][(int)(game->player.posy)] == '0')
			game->player.posx += game->player.diry * game->movespeed;
		n = game->player.posy - game->player.dirx * (game->movespeed * 2);
		if (game->map[(int)(game->player.posx)][n] == '0')
			game->player.posy -= game->player.dirx * game->movespeed;
		return (1);
	}
	return (0);
}
