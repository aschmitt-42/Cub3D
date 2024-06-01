/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:38 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/01 16:50:07 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_color_FC(t_game *game, int line)
{
	(void)game;
	(void)line;
}

void	open_texture(t_game *game, size_t line)
{
	int	j;
	
	j = 2;
	while (game->map[line])
	{
		while (ft_iswspace(game->map[line][j]))
			j++;
		if (j == 2)
		{
			printf("Error\n");
			free_map(game->map + line);
		}
		//ouvrir la texture et la mettre dans le bon element de game
	}
}

int	still_header(t_game *game, size_t line)
{
	if (!game->map || !game->map[line])
		return (0);
	return (0);//verifier si toutes les infos du header sont remplie, et si la ligne nest pas juste un /n, alors header est finit
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
			create_color_FC(game, line);
		else if (game->map[line][0] != '\n')
			return (printf("Error\nInvalid line found\n"), free_map(game->map + line),
				exit(1), NULL);
		free(game->map[line]);
		line++;
	}
	return (game->map + line);
}

void	map_verif(t_game *game)
{
	(void)game;
	return;
}

void	map_filler(char *file, t_game *game)
{
	int		i;
	int		fd;

	i = 1;
	game->map = ft_malloc_map(file);
	if (!game->map)
		exit(1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free_map(game->map);
		printf("Error\nOpen failed\n");
		return ;
	}
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
