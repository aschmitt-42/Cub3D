/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:34:13 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/19 17:48:26 by aschmitt         ###   ########.fr       */
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
# include <math.h>

#ifndef WIDTH
# define WIDTH 1024
#endif

#ifndef HEIGHT
# define HEIGHT 512
#endif

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

typedef struct s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}				t_player;

typedef struct s_key
{
	int		z;
	int		q;
	int		s;
	int		d;
	int		left;
	int		right;
}				t_key;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int 	bpp;
    int 	size_line;
   	int 	endian;
}				t_img;

typedef struct s_ray
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX; //length of ray from current position to next x or y-side
	double	sideDistY;
	double	deltaDistX; //longueur du rayon depuis la position actuelle jusqu'au prochain côté x ou y
	double	deltaDistY;
	double	perpWallDist;
	int		mapX;
	int		mapY;
	int		stepX; //dans quelle direction avancer dans la direction x ou y (soit +1 ou -1)
	int		stepY;
	int		hit; //Y a-t-il eu un coup de mur ?
	int		side; //un mur NS ou EW a-t-il été touché ?
	int		h;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		x;
}				t_ray;

typedef struct s_game
{
	int			width;
	int			height;
	double		moveSpeed;
	double		rotSpeed;
	char		**map;
	char		**p_map;
	void		*NO;
	void		*SO;
	void		*WE;
	void		*EA;
	int			F;
	int			C;
	t_data		mlibx;
	t_player	player;
	t_key		key;
	t_img		img;
	t_img		img2;
	t_ray		ray;
}				t_game;

// construct
void	game_construct(t_game *game);

// free
void	free_map(t_game *game, int line);
void 	free_game(t_game *game, int error_code);

// init map
void	create_color_FC(t_game *game, int line, int j, int i);
void	open_texture(t_game *game, size_t line);
void 	del_newline(char *line);
int		still_header(t_game *game, size_t line);
int		check_extention(char *file);
char	**ft_malloc_map(t_game *game, char *file);
void	print_map(char **map);
void	init_map(char *file, t_game *game);
char	*get_next_line(int fd);

// init mlx
void	init_mlx(t_game *game);

// game
void	cub3d(t_game *game);



int		render_next_frame(t_game *game);
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

// key hook
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		play(t_game *game);

void    draw(t_game *game);
void	performe_dda(t_game *game);
void	init_vecteur(t_game *game);
void	display(t_game *game);

#endif