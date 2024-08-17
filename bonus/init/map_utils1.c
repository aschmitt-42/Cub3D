/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:26 by eboumaza          #+#    #+#             */
/*   Updated: 2024/08/17 23:28:11 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_img_addr(t_game *game)
{
	game->no.addr = (int *)(mlx_get_data_addr(game->no.img,
				&game->no.bpp, &game->no.size_line, &game->no.endian));
	game->so.addr = (int *)(mlx_get_data_addr(game->so.img,
				&game->so.bpp, &game->so.size_line, &game->so.endian));
	game->ea.addr = (int *)(mlx_get_data_addr(game->ea.img,
				&game->ea.bpp, &game->ea.size_line, &game->ea.endian));
	game->we.addr = (int *)(mlx_get_data_addr(game->we.img,
				&game->we.bpp, &game->we.size_line, &game->we.endian));
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}

int	check_extention(char *file, char *extension)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	while (is_wspace(file[i - 1]))
	{
		i--;
		file[i] = '\0';
	}
	if (file[i - 4] == extension[0] && file[i - 3] == extension[1]
		&& file[i - 2] == extension[2] && file[i - 1] == extension[3])
		return (1);
	return (0);
}

void	del_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	i--;
	while (line[i] == '\n' || is_wspace(line[i]))
	{
		line[i] = '\0';
		i--;
	}
}

int	still_header(t_game *game, size_t line)
{
	if (!game->map || !game->map[line])
		return (0);
	if (game->c != -1 && game->f != -1 && game->no.img && game->so.img && game->we.img
		&& game->ea.img && game->map[line][0] != '\n')
		return (0);
	return (1);
}
