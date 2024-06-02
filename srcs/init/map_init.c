/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:38 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/02 19:14:45 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_verif(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!game->map)
		free_game(game, 5);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
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
			j++;
		}
		i++;
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
	print_map(game->map);
	map_verif(game);
}

void	init_map(char *file, t_game *game)
{
	if (file == NULL || !check_extention(file))
		exit(1);
	map_filler(file, game);
	(void)game;
}
