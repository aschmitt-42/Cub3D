/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:58:16 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/23 22:41:44 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_color_FC(t_game *game, int line, int j, int i)
{
	int	rgb[3];

	while (i < 3)
	{
		while (is_wspace(game->map[line][j]))
			j++;
		if (ft_isdigit(game->map[line][j]))
		{
			rgb[i] = ft_atoi(game->map[line] + j);
			i++;
		}
		else
			free_game(game, 1);
		while (is_wspace(game->map[line][j]))
			j++;
		while (game->map[line][j] && game->map[line][j - 1] != ',')//revoir la condition darret
			j++;
	}
	if (game->map[line][0] == 'C')
		game->C = create_rgb(rgb[0], rgb[1], rgb[2]);
	else
		game->F = create_rgb(rgb[0], rgb[1], rgb[2]);
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
	if (game->map[line][0] == 'N' && game->map[line][1] == 'O')
		game->NO.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
			game->map[line] + j, &game->NO.width, &game->NO.height);
	else if (game->map[line][0] == 'S' && game->map[line][1] == 'O')
		game->SO.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
			game->map[line] + j, &game->SO.width, &game->SO.height);
	else if (game->map[line][0] == 'W' && game->map[line][1] == 'E')
		game->WE.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
			game->map[line] + j, &game->WE.width, &game->WE.height);
	else if (game->map[line][0] == 'E' && game->map[line][1] == 'A')
		game->EA.img = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
			game->map[line] + j, &game->EA.width, &game->EA.height);
		//verif si lallocation a fonctionner, sinon free_game;
}

void	get_y_scale_map(t_game *game)
{
	size_t	i;
	
	i = 0;
	while(game->map[i])
		i++;
	game->map_y_scale = i;
}
