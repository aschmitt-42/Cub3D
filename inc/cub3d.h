/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:34:13 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/01 20:08:02 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ml/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

#ifndef WIDTH
# define WIDTH 10
#endif

#ifndef HEIGHT
# define HEIGHT 10
#endif

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

typedef struct s_game
{
	int			width;
	int			height;
	char		**map;
	void		*NO;
	void		*SO;
	void		*WE;
	void		*EA;
	int			*F;
	int			*C;
	t_data		mlibx;
}				t_game;

// construct
void	game_construct(t_game *game);

// free
void	free_map(char **map);
void 	free_game(t_game *game, int error_code);

// init map
int		check_extention(char *file);
char	**ft_malloc_map(char *file);
void	print_map(char **map);
void	init_map(char *file, t_game *game);

// init mlx
void	init_mlx(t_game *game);

// game
void	cub3d(t_game *game);

// libft
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_iswspace(char c);
int		ft_isdigit(int c);
int		create_rgb(unsigned char r, unsigned char g, unsigned char b);

#endif