/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:12:13 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/20 16:43:00 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int code)
{
	if (code == 1)
		printf("Error\nError\nMlx init failed\n");
	if (code == 2)
		printf("Error\nOpen failed\n");
	else if (code == 3)
		printf("Error\nInvalid line found\n");
	else if (code == 4)
		printf("Error\nMap is not surrounded by walls\n");
	else if (code == 5)
		printf("Error\nEmpty file\n");
	else if (code == 6)
		printf("Error\n\n");
	else if (code == 7)
		printf("Error\n\n");
	else if (code == 8)
		printf("Error\n\n");
	else if (code == 9)
		printf("Error\n\n");
	else if (code == 10)
		printf("Closing Cub3d\n");
}

void	game_construct(t_game *game)
{
	game->mlibx.mlx_ptr = NULL;
	game->mlibx.win_ptr = NULL;
	game->map = NULL;
	game->p_map = NULL;
	game->width = WIDTH;
	game->height = HEIGHT;
	game->C = 0;
	game->F = 0;
	game->NO.img = NULL;
	game->SO.img = NULL;
	game->WE.img = NULL;
	game->EA.img = NULL;
	game->player.dirX = 0;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0;
	game->player.posX = 1;
	game->player.posY = 16;
	game->key.z = 0;
	game->key.s = 0;
	game->key.q = 0;
	game->key.d = 0;
	game->key.left = 0;
	game->key.right = 0;
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
			return;
	}
	free(game->p_map);
	game->map = NULL;
}

void	free_mlx(t_game *game)
{
	if (game->EA.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->EA.img);
	if (game->NO.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->NO.img);
	if (game->SO.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->SO.img);
	if (game->WE.img)
		mlx_destroy_image(game->mlibx.mlx_ptr, game->WE.img);
	if (game->mlibx.win_ptr)
		mlx_destroy_window(game->mlibx.mlx_ptr, game->mlibx.win_ptr);
	if (game->mlibx.mlx_ptr)
	{
		mlx_destroy_display(game->mlibx.mlx_ptr);
		free(game->mlibx.mlx_ptr);
	}
}
// code derreur : 1= ,2= ,3= ,4= ,5= ,6= ,7= ,8= ,9= ,10=
void 	free_game(t_game *game, int error_code)
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
