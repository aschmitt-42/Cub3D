/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:38 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/01 21:19:49 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_verif(t_game *game)
{
	(void)game;
	return;
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
		{
			printf("%ld et %s\n", line, game->map[line]);
			free_game(game, 2);
		}
		line++;
	}
	free_map(game, line);//supprime les strings du headers
	//free les tab davant
	return (game->map + line);
}

void	map_filler(char *file, t_game *game)
{
	int		i;
	int		fd;

	i = 1;
	game->map = ft_malloc_map(game, file);
	if (!game->map)
		free_game(game, 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_game(game, 1);
	game->map[0] = get_next_line(fd);
	while (game->map[i - 1])
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	game->map = handle_header(game);//rempli toutes les infos du headers, et free les string associe, puis renvoie game->map + header_len
	map_verif(game);
}

void	init_map(char *file, t_game *game)
{
	if (file == NULL || !check_extention(file))
		exit(1);
	map_filler(file, game);
	print_map(game->map);
	(void)game;
}
