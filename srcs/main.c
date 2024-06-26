/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:55 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/26 17:55:47 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *game, char **av)
{
	game_construct(game);
	game->mlibx.mlx_ptr = mlx_init();
	if (!game->mlibx.mlx_ptr)
		free_game(game, 1);
	init_map(av[1], game);
	init_mlx(game);
}

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (write(2, "Error\nNo .cub file specified\n", 29), 1);
	init(&game, av);
	free_game(&game, 10);
	return (0);
}
