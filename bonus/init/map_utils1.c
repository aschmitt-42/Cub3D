/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:26 by eboumaza          #+#    #+#             */
/*   Updated: 2024/07/16 13:52:56 by aschmitt         ###   ########.fr       */
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

int	check_extention(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (1);
	printf("Error\nUnvalid extension\n");
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
	if (game->c && game->f && game->no.img && game->so.img && game->we.img
		&& game->ea.img && game->map[line][0] != '\n')
		return (0);
	return (1);
}
