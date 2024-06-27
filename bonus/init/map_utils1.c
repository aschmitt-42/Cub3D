/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:26 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/27 22:28:43 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_img_addr(t_game *game)
{
	game->NO.addr = (int *)(mlx_get_data_addr(game->NO.img,
				&game->NO.bpp, &game->NO.size_line, &game->NO.endian));
	game->SO.addr = (int *)(mlx_get_data_addr(game->SO.img,
				&game->SO.bpp, &game->SO.size_line, &game->SO.endian));
	game->EA.addr = (int *)(mlx_get_data_addr(game->EA.img,
				&game->EA.bpp, &game->EA.size_line, &game->EA.endian));
	game->WE.addr = (int *)(mlx_get_data_addr(game->WE.img,
				&game->WE.bpp, &game->WE.size_line, &game->WE.endian));
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
	if (game->C && game->F && game->NO.img && game->SO.img && game->WE.img
		&& game->EA.img && game->map[line][0] != '\n')
		return (0);
	return (1);//verifier si toutes les infos du header sont remplie, et si la ligne nest pas juste un /n, alors header est finit
}
