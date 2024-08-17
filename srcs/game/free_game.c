/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:12:13 by eboumaza          #+#    #+#             */
/*   Updated: 2024/08/17 23:25:45 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int code)
{
	if (code == 1)
		printf("Error\nMlx init failed\n");
	if (code == 2)
		printf("Error\nOpen failed\n");
	else if (code == 3)
		printf("Error\nInvalid line found\n");
	else if (code == 4)
		printf("Error\nMap is not surrounded by walls\n");
	else if (code == 5)
		printf("Error\nEmpty file\n");
	else if (code == 6)
		printf("Error\nNo position start\n");
	else if (code == 7)
		printf("Error\nSeveral starting positions\n");
	else if (code == 8)
		printf("Error\nInvalide : is a directory\n");
	else if (code == 9)
		printf("Error\nColor error\n");
	else if (code == 10)
		printf("Closing Cub3d\n");
	else if (code == 11)
		printf("Wrong extension\n");
}

void	game_construct(t_game *game)
{
	game->mlibx.mlx_ptr = NULL;
	game->mlibx.win_ptr = NULL;
	game->map = NULL;
	game->p_map = NULL;
	game->width = WIDTH;
	game->height = HEIGHT;
	game->c = -1;
	game->f = -1;
	game->no.img = NULL;
	game->so.img = NULL;
	game->we.img = NULL;
	game->ea.img = NULL;
	game->player.dirx = 0;
	game->player.diry = 0;
	game->player.planex = 0;
	game->player.planey = 0;
	game->key.z = 0;
	game->key.s = 0;
	game->key.q = 0;
	game->key.d = 0;
	game->key.left = 0;
	game->key.right = 0;
	game->img.img = NULL;
}

// 0 pour toute la map, sinon le nombre de ligne a free
void	free_map(t_game *game, int line)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
		if (i != 0 && line == i)
			return ;
	}
	free(game->p_map);
	game->map = NULL;
}

void	free_mlx(t_game *game)
{
	if (game->ea.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->ea.img);
	if (game->no.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->no.img);
	if (game->so.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->so.img);
	if (game->we.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->we.img);
	if (game->img.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->img.img);
	if (game->mlibx.win_ptr)
		mlx_destroy_window(game->mlibx.mlx_ptr, game->mlibx.win_ptr);
	if (game->mlibx.mlx_ptr)
	{
		mlx_destroy_display(game->mlibx.mlx_ptr);
		free(game->mlibx.mlx_ptr);
	}
}

void	free_game(t_game *game, int error_code)
{
	if (error_code)
		print_error(error_code);
	free_map(game, 0);
	free_mlx(game);
	if (error_code == 10)
		exit(0);
	if (error_code)
		exit(error_code);
}
