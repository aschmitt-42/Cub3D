/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:38 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/26 17:55:54 by aschmitt         ###   ########.fr       */
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
			if (game->map[i][j] == 'S' || game->map[i][j] == 'N' || game->map[i][j] == 'W' || game->map[i][j] == 'E')
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
			{
				if (!game->map[i + 1] || j == 0 || i == 0 || game->map[i][j + 1] == '\0')
					free_game(game, 4);
				if (!(game->map[i][j + 1] == '1' || game->map[i][j + 1] == '0')
					|| !(game->map[i][j - 1] == '1' || game->map[i][j - 1] == '0')
					|| !(game->map[i + 1][j] == '1' || game->map[i + 1][j] == '0')
					|| !(game->map[i - 1][j] == '1' || game->map[i - 1][j] == '0'))
					free_game(game, 4);
			}
		}
	}
}

char	**handle_header(t_game *game)
{
	size_t	line;

	line = 0;
	while (still_header(game, line))
	{
		if ((!ft_strncmp(game->map[line], "NO", 2)
			|| !ft_strncmp(game->map[line], "SO", 2)
			|| !ft_strncmp(game->map[line], "WE", 2)
			|| !ft_strncmp(game->map[line], "EA", 2)))
			open_texture(game, line);
		else if (game->map[line][0] == 'F' || game->map[line][0] == 'C')
			create_color_FC(game, line, 1, 0);
		else if (game->map[line][0] != '\n')
			free_game(game, 3);
		line++;
	}
	free_map(game, line);//supprime les strings du headers
	return (game->map + line);
}

void	get_img_addr(t_game *game)
{
	game->NO.addr = (int *)(mlx_get_data_addr(game->NO.img, &game->NO.bpp, &game->NO.size_line, &game->NO.endian));
	game->SO.addr = (int *)(mlx_get_data_addr(game->SO.img, &game->SO.bpp, &game->SO.size_line, &game->SO.endian));
	game->EA.addr = (int *)(mlx_get_data_addr(game->EA.img, &game->EA.bpp, &game->EA.size_line, &game->EA.endian));
	game->WE.addr = (int *)(mlx_get_data_addr(game->WE.img, &game->WE.bpp, &game->WE.size_line, &game->WE.endian));
}

void	map_filler(char *file, t_game *game)
{
	int		i;
	int		fd;

	i = 1;
	game->map = ft_malloc_map(game, file);
	if (!game->map)
		free_game(game, 2);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_game(game, 2);
	game->map[0] = get_next_line(fd);
	while (game->map[i - 1])
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	game->map = handle_header(game);//rempli toutes les infos du headers, et free les string associe, puis renvoie game->map + header_len
	// print_map(game->map);
	get_y_scale_map(game);
	map_verif(game);
	get_img_addr(game);
}

void	init_map(char *file, t_game *game)
{
	if (file == NULL || !check_extention(file))
		exit(1);
	map_filler(file, game);
}
