/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:55 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/01 20:41:59 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(t_game *game)
{
	(void)game;
}

void	init(t_game *game, char **av)
{
	game_construct(game);
	init_mlx(game);
	init_map(av[1], game);
	game->mlibx.win_ptr = mlx_new_window
		(game->mlibx.mlx_ptr, WIDTH * 120, HEIGHT * 120, "Cub3D");
	if (!game->mlibx.win_ptr)
		free_game(game, 10);
}

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (write(2, "Error\nNo .cub file specified\n", 29), 1);
	init(&game, av);
	cub3d(&game);
	free_game(&game, 0);
	return (0);
}
