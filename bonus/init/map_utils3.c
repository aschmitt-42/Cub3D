/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:37:45 by aschmitt          #+#    #+#             */
/*   Updated: 2024/07/16 13:38:50 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	pos_start(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	game->player.posx = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'S' || game->map[i][j] == 'N'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				if (game->player.posx != -1)
					free_game(game, 7);
				game->player.posx = i + 0.5;
				game->player.posy = j + 0.5;
				game->player.start = game->map[i][j];
				game->map[i][j] = '0';
			}
		}
	}
	if (game->player.posx == -1)
		free_game(game, 6);
}
