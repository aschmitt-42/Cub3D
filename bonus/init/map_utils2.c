/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:58:16 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/27 22:29:39 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pos_start(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	game->player.posX = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'S' || game->map[i][j] == 'N'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				if (game->player.posX != -1)
					free_game(game, 7);
				game->player.posX = i + 0.5;
				game->player.posY = j + 0.5;
				game->player.start = game->map[i][j];
				game->map[i][j] = '0';
			}
		}
	}
	if (game->player.posX == -1)
		free_game(game, 6);
}

void	verify_texture(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && !game->NO.img)
		free_game(game, 2);
	if (line[0] == 'S' && line[1] == 'O' && !game->SO.img)
		free_game(game, 2);
	if (line[0] == 'W' && line[1] == 'E' && !game->WE.img)
		free_game(game, 2);
	if (line[0] == 'E' && line[1] == 'A' && !game->EA.img)
		free_game(game, 2);
}

void	open_texture(t_game *game, size_t line)
{
	int	j;

	j = 2;
	while (is_wspace(game->map[line][j]))
		j++;
	if (j == 2)
		free_game(game, 1);
	del_newline(game->map[line]);
	if (game->map[line][0] == 'N' && game->map[line][1] == 'O' &&
		!game->NO.img)
		game->NO.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr,
				game->map[line] + j, &game->NO.width, &game->NO.height);
	else if (game->map[line][0] == 'S' && game->map[line][1] == 'O' &&
		!game->SO.img)
		game->SO.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr,
				game->map[line] + j, &game->SO.width, &game->SO.height);
	else if (game->map[line][0] == 'W' && game->map[line][1] == 'E' &&
		!game->WE.img)
		game->WE.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr,
				game->map[line] + j, &game->WE.width, &game->WE.height);
	else if (game->map[line][0] == 'E' && game->map[line][1] == 'A' &&
		!game->EA.img)
		game->EA.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr,
				game->map[line] + j, &game->EA.width, &game->EA.height);
	verify_texture(game, game->map[line]);
}

void	verify_point(t_game *game, int i, int j)
{
	if (!game->map[i + 1] || j == 0 || i == 0
		|| game->map[i][j + 1] == '\0')
		free_game(game, 4);
	if (!(game->map[i][j + 1] == '1' || game->map[i][j + 1] == '0')
		|| !(game->map[i][j - 1] == '1' || game->map[i][j - 1] == '0')
		|| !(game->map[i + 1][j] == '1' || game->map[i + 1][j] == '0')
		|| !(game->map[i - 1][j] == '1' || game->map[i - 1][j] == '0'))
		free_game(game, 4);
}

void	map_verif(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (!game->map)
		free_game(game, 5);
	pos_start(game);
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0')
				verify_point(game, i, j);
		}
	}
}
