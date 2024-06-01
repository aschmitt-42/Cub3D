/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:12:13 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/01 20:15:49 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_construct(t_game *game)
{
	game->mlibx.mlx_ptr = NULL;
	game->mlibx.win_ptr = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->C = 0;
	game->F = 0;
	game->NO = NULL;
	game->SO = NULL;
	game->WE = NULL;
	game->EA = NULL;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_mlx(t_data *mlibx)
{
	if (mlibx->mlx_ptr)
		free(mlibx->mlx_ptr);
}

void	print_error(int code)
{
	if (code == 1)
		printf("Error\nInvalid line found\n");
	else if (code == 2)
		printf("Error\n\n");
	else if (code == 3)
		printf("Error\n\n");
	else if (code == 4)
		printf("Error\n\n");
	else if (code == 5)
		printf("Error\n\n");
	else if (code == 6)
		printf("Error\n\n");
	else if (code == 7)
		printf("Error\n\n");
	else if (code == 8)
		printf("Error\n\n");
	else if (code == 9)
		printf("Error\n\n");
	else if (code == 10)
		printf("Error\nFail to init mlx\n");
	exit(code);
}

// code derreur : 1= ,2= ,3= ,4= ,5= ,6= ,7= ,8= ,9= ,10=
void 	free_game(t_game *game, int error_code)
{
	free_map(game->map);
	free_mlx(&game->mlibx);
	if (game->NO)
		free(game->NO);
	if (game->SO)
		free(game->SO);
	if (game->WE)
		free(game->WE);
	if (game->EA)
		free(game->EA);
	if (error_code)
		print_error(error_code);
}

