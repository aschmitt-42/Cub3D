/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:14:43 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/01 20:06:42 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlibx.mlx_ptr = mlx_init();
	if (!game->mlibx.mlx_ptr)
		free_game(game, 10);
	game->mlibx.win_ptr = mlx_new_window
		(game->mlibx.mlx_ptr, WIDTH * 120, HEIGHT * 120, "Cub3D");
	if (!game->mlibx.win_ptr)
		free_game(game, 10);
}
