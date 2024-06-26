/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:26 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/26 17:27:13 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i = 0;
	int j = 0;

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

char	**ft_malloc_map(t_game *game, char *file)
{
	char	*temp;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	
	if ((fd = open(file, O_DIRECTORY) != -1))
		free_game(game, 8);
	if ((fd = open(file, O_RDONLY)) == -1)
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

void del_newline(char *line)
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
	/*
	if (!game->NO)
		printf("NO\n");
	if (!game->EA)
		printf("EA\n");
	if (!game->WE)
		printf("WE\n");
	if (!game->SO)
		printf("SO\n");
	if (!game->F)
		printf("F\n");
	if (!game->C)
		printf("C\n");
	*/
	if (!game->map || !game->map[line])
		return (0);
	if (game->C && game->F && game->NO.img && game->SO.img && game->WE.img && game->EA.img && game->map[line][0] != '\n')
		return (0);
	return (1);//verifier si toutes les infos du header sont remplie, et si la ligne nest pas juste un /n, alors header est finit
}
