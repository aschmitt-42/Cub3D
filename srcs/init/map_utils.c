/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:26 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/01 16:50:19 by eboumaza         ###   ########.fr       */
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

char	**ft_malloc_map(char *file)
{
	char	*temp;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nOpen failed\n"), NULL);
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
	map[0] = NULL;
	return (map);
}
