/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:14:43 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/19 23:52:25 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_game *game)
{
	free_game(game, 10);
	return (0);
}


void	init_mlx(t_game *game)
{
	game->mlibx.win_ptr = mlx_new_window
		(game->mlibx.mlx_ptr, game->width, game->height, "Cub3D");
	if (!game->mlibx.win_ptr)
		free_game(game, 1);
	init_vecteur(game);
	draw(game);
	mlx_hook(game->mlibx.win_ptr, 17, 1L << 0, close_win, game);
	printf("1 : %f\n", game->player.posY);
	mlx_hook(game->mlibx.win_ptr, 2, 1L << 0, key_press, game);
	printf("2 : %f\n", game->player.posY);
	mlx_loop_hook(game->mlibx.mlx_ptr, play, game);
	
	mlx_hook(game->mlibx.win_ptr, 3, 1L << 1, key_release, game);
	printf("3 : %f\n", game->player.posY);
	mlx_loop(game->mlibx.mlx_ptr);
}
