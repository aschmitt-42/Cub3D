/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:38 by aschmitt          #+#    #+#             */
/*   Updated: 2024/05/31 23:01:50 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extention(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (1);
	printf("Erreur d'extension\n");
	return (0);
}

char	**ft_malloc_map(char *file, int i, int fd)
{
	char	*temp;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Erreur de fichier\n"), NULL);
	temp = get_next_line(fd);
	while (temp)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
	}
	if (i <= 2)
		return (close(fd), printf("Erreur de MAP\n"), NULL);
	map = malloc(sizeof(char *) * (i + 1));
	close(fd);
	if (!map)
		return (NULL);
	map[0] = NULL;
	return (map);
}

void	map_filler(char *file, t_game *game)
{
	int		i;
	int		fd;

	i = 1;
	game->map = ft_malloc_map(file, 0, 0);
	if (!game->map)
		exit(1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur de fichier\n");
		return ;
	}
	game->map[0] = get_next_line(fd);
	while (game->map[i - 1])
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	game->width = ft_strlen(game->map[0]) - 1;
	game->height = i - 1;
}

void	init_map(char *file, t_game *game)
{
	if (file == NULL || !check_extention(file))
		exit(1);
	map_filler(file, game);
	(void)game;
}
