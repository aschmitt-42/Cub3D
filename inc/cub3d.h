/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:34:13 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 23:28:25 by aschmitt         ###   ########.fr       */
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

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

typedef struct s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	char		start;
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

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		h;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		x;
}				t_ray;

typedef struct s_minimap
{
	int		enable;
	int		i;
	int		width;
	int		max;
	int		min;
	int		pos;
	double	scale;
}		t_minimap;

typedef struct s_game
{
	int			width;
	int			height;
	double		movespeed;
	double		rotspeed;
	char		**map;
	char		**p_map;
	int			map_y_scale;
	t_image		no;
	t_image		so;
	t_image		we;
	t_image		ea;
	int			f;
	int			c;
	t_data		mlibx;
	t_player	player;
	t_key		key;
	t_image		img;
	t_ray		ray;
	t_minimap	minimap;
}				t_game;

// construct
void	game_construct(t_game *game);

// free
void	free_map(t_game *game, int line);
// code derreur : 1=error mlx ,2=open failed ,3=Invalid line parse ,4=maps not surrended by wall
//5=Empty file ,6=No position start ,7=Several starting positions ,8= ,9= ,10=closing cub3d
void	free_game(t_game *game, int error_code);

// init map
void	get_img_addr(t_game *game);
void	get_y_scale_map(t_game *game);
void	create_color_fc(t_game *game, int line, int j, int i);
void	open_texture(t_game *game, size_t line);
void	del_newline(char *line);
int		still_header(t_game *game, size_t line);
int		check_extention(char *file);
void	map_verif(t_game *game);
char	**ft_malloc_map(t_game *game, char *file);
void	print_map(char **map);
void	init_map(char *file, t_game *game);

// init mlx
void	init_mlx(t_game *game);
int		close_win(t_game *game);

// game
void	pixel_put(t_game *game, int x, int y, int color);
int		render_next_frame(t_game *game);
int		create_rgb(unsigned char r, unsigned char g, unsigned char b);
void	draw(t_game *game);
void	performe_dda(t_game *game);
void	init_vecteur(t_game *game);
void	display(t_game *game);
void	cub3d(t_game *game);

// key 
int		move_lr(t_game *game);
int		move_updown(t_game *game);
int		move_side(t_game *game);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		play(t_game *game);

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
int		is_wspace(char c);

void	mini_map(t_game *game);

#endif