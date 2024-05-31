/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:55 by aschmitt          #+#    #+#             */
/*   Updated: 2024/05/31 23:04:36 by eboumaza         ###   ########.fr       */
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
	init_map(av[1], game);
	init_mlx(game);
}

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (write(2, "Error args\n", 11), 1);
	init(&game, av);
	cub3d(&game);
	free_game(&game, 0);
	return (0);
}
