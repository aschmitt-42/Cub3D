/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:45:06 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/26 18:12:52 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_border(t_game *game)
{
	int	i;
	int	color;

	i = 0;
	color = create_trgb(0, 255, 215, 46);
	while (i <= game->minimap.width)
	{
		pixel_put(game, game->minimap.width + 1, i, color);
		pixel_put(game, game->minimap.width + 2, i, color);
		i++;
	}
	i = 0;
	while (i <= game->minimap.width + 2)
	{
		pixel_put(game, i, game->minimap.width + 1, color);
		pixel_put(game, i, game->minimap.width + 2, color);
		i++;
	}
}

int	is_in_map(t_game *game, double x, double y)
{
	if (x < 0 || y < 0)
		return (0);
	if ((int)y >= game->map_y_scale || (size_t)x >= ft_strlen(game->map[(int)y]))
		return (0);
	return (1);
}

void	draw_map(t_game *game)
{
	int		color;
	int 	last_pos;
	double	scale;
	int		pixel[2];
	double	pos[2];

	scale = 1 / (game->minimap.width * 0.1);
	pos[1] = game->player.posX - 5;
	pixel[1] = 0;
	while (pixel[1] <= game->minimap.width)
	{
		pos[0] = game->player.posY - 5;
		pixel[0] = 0;
		while (pixel[0] <= game->minimap.width)
		{
			last_pos = (int)pos[0];
			if (!is_in_map(game, pos[0], pos[1]) || is_wspace(game->map[(int)pos[1]][(int)pos[0]]))
				color = 0;//create_trgb(255, 20, 10, 8);
			else if (game->map[(int)pos[1]][(int)pos[0]] == '1')
				color = create_trgb(0, 63, 63, 63);
			else
				color = create_trgb(0, 220, 220, 220);
			while (last_pos == (int)pos[0] && pixel[0] <= game->minimap.width)
			{
				pixel_put(game, pixel[0], pixel[1], color);
				pos[0] += scale;
				pixel[0]++;
			}
		}
		pixel[1]++;
		pos[1] += scale;
	}
}

void draw_line(t_game *game, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
    int err = (dx > dy ? dx : -dy) / 2, e2;
	
	pixel_put(game, x0, y0, 0);	
	//put_pixel(x0, y0);

    if (x0 == x1 && y0 == y1) return;

    e2 = err;
    if (e2 > -dx) {
        err -= dy;
        x0 += sx;
    }
    if (e2 < dy) {
        err += dx;
        y0 += sy;
    }
    draw_line(game, x0, y0, x1, y1); // Recursive call
}

void draw_player(t_game *game) 
{
    // Define the points of the triangle
    int size = 20;
    
    // Center of the triangle
    int cx = game->minimap.width / 2;
    int cy = game->minimap.width / 2;
    
    // Convert rotation from 0 to 1 into radians (0 to 2*PI)
    float angle = game->player.dirX * M_PI;

    // Calculate the sine and cosine of the angle for rotation
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);

    // Define the points of the triangle in local coordinates
    int x1 = 0;
    int y1 = -size / 2;

    int x2 = size / 2;
    int y2 = size / 2;

    int x3 = -size / 2;
    int y3 = size / 2;

    // Apply rotation and translate to the center of the screen
    int px1 = cx + (int)(x1 * cos_angle - y1 * sin_angle);
    int py1 = cy + (int)(x1 * sin_angle + y1 * cos_angle);

    int px2 = cx + (int)(x2 * cos_angle - y2 * sin_angle);
    int py2 = cy + (int)(x2 * sin_angle + y2 * cos_angle);

    int px3 = cx + (int)(x3 * cos_angle - y3 * sin_angle);
    int py3 = cy + (int)(x3 * sin_angle + y3 * cos_angle);

    // Draw the triangle as lines between these points
    draw_line(game, px1, py1, px2, py2); // First side
    draw_line(game, px2, py2, px3, py3); // Second side
    draw_line(game, px3, py3, px1, py1); // Third side
}

// Bresenham's line algorithm to draw a line between two points recursively

// Bresenham's line algorithm to draw a line between two points recursively

void	mini_map(t_game *game)
{
	draw_border(game);
	draw_map(game);
	draw_player(game);
}