/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:38 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/01 20:14:18 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_color_FC(t_game *game, int line, int j, int i)
{
	int	rgb[3];

	while (game->map[line])
	{
		while (ft_iswspace(game->map[line][j]))
			j++;
		while (i < 3)
		{
			if (ft_isdigit(game->map[line][j]))
			{
				rgb[i] = ft_atoi(game->map[line] + j);
				i++;
			}
			else
				free_game(game, 1);
			while (game->map[line][j] && game->map[line][j - 1] != ',')//revoir la condition darret
				j++;
		}
	if (game->map[line][j] == 'C')
		*game->C = create_rgb(rgb[0], rgb[1], rgb[2]);
	else
		*game->F = create_rgb(rgb[0], rgb[1], rgb[2]);
	}
	return (1);
}

void	open_texture(t_game *game, size_t line)
{
	int	j;
	
	j = 2;
	return ;
	while (game->map[line])
	{
		while (ft_iswspace(game->map[line][j]))
			j++;
		if (j == 2)
			free_game(game, 1);
		if (game->map[line][0] == 'N' && game->map[line][1] == 'O')
			game->NO = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
				game->map[line] + j, &game->width, &game->height);
		else if (game->map[line][0] == 'S' && game->map[line][1] == 'O')
			game->SO = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
				game->map[line] + j, &game->width, &game->height);
		else if (game->map[line][0] == 'W' && game->map[line][1] == 'E')
			game->WE = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
				game->map[line] + j, &game->width, &game->height);
		else if (game->map[line][0] == 'E' && game->map[line][1] == 'A')
			game->EA = mlx_xpm_file_to_image(game->mlibx.mlx_ptr, 
				game->map[line] + j, &game->width, &game->height);
		//verif si lallocation a fonctionner, sinon free_game;
	}
}
void	map_verif(t_game *game)
{
	(void)game;
	return;
}

int	still_header(t_game *game, size_t line)
{
	if (!game->map || !game->map[line])
		return (0);
	if (game->C && game->F && game->NO && game->SO && game->WE && game->EA)
		return (0);
	return (1);//verifier si toutes les infos du header sont remplie, et si la ligne nest pas juste un /n, alors header est finit
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
			free_game(game, 1);
		line++;
	}
	//free les tab davant
	return (game->map + line);
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
	print_map(game->map);
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
