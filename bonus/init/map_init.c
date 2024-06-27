/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:38 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 22:28:11 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_color_fc(t_game *game, int line, int j, int i)
{
	int	rgb[3];

	while (game->map[line][j] && i < 3)
	{
		while (is_wspace(game->map[line][j]))
			j++;
		if (ft_isdigit(game->map[line][j]))
			rgb[i++] = ft_atoi(game->map[line] + j);
		else
			free_game(game, 9);
		while (is_wspace(game->map[line][j]))
			j++;
		while (game->map[line][j] && game->map[line][j - 1] != ',')
			j++;
		if (rgb[i - 1] > 255 || rgb[i - 1] < 0)
			free_game(game, 9);
	}
	if (i < 3)
		free_game(game, 9);
	if (game->map[line][0] == 'C')
		game->C = create_rgb(rgb[0], rgb[1], rgb[2]);
	else
		game->F = create_rgb(rgb[0], rgb[1], rgb[2]);
}

char	**ft_malloc_map(t_game *game, char *file)
{
	char	*temp;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_game(game, 2);
	temp = get_next_line(fd);
	while (temp)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * (i + 1));
	close(fd);
	if (!map)
		return (NULL);
	game->p_map = map;
	map[0] = NULL;
	return (map);
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
			create_color_fc(game, line, 1, 0);
		else if (game->map[line][0] != '\n')
			free_game(game, 3);
		line++;
	}
	free_map(game, line);
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
	game->map = handle_header(game);
	print_map(game->map);
	map_verif(game);
	get_img_addr(game);
}

void	init_map(char *file, t_game *game)
{
	if (file == NULL || !check_extention(file))
		exit(1);
	map_filler(file, game);
}
