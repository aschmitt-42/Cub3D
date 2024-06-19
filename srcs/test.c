/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:18:25 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/19 12:50:26 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// mlx_xpm_file_to_image(mlx_ptr, game->map[line] + j, &game->width, &game->height);

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void	draw(t_game *game)
{
	// printf("x : %f\ny : %f\n", game.player.dirX, game.player.dirY);
	for(double x = 0; x < screenWidth ; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)screenWidth - 1; // x-coordinate in camera space
		
		double rayDirX = game->player.dirX + game->player.planeX * cameraX;
		double rayDirY = game->player.dirY + game->player.planeY * cameraX;
		//dans quelle case de la carte nous nous trouvons (convertir double en int)
		int mapX = game->player.posX;
		int mapY = game->player.posY;

		//length of ray from current position to next x or y-side
	  	double sideDistX;
	  	double sideDistY;

		//longueur du rayon depuis la position actuelle jusqu'au prochain côté x ou y
		double deltaDistX;
		if (rayDirX == 0)
			deltaDistX = 1e30;
		else 
			deltaDistX = fabs(1 / rayDirX); // sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY;
		if (rayDirY == 0) 
			deltaDistY = 1e30;
		else 
			deltaDistY = fabs(1 / rayDirY); //  sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY)); 

		//dans quelle direction avancer dans la direction x ou y (soit +1 ou -1)
		int stepX;
	 	int stepY;

		int hit = 0; //Y a-t-il eu un coup de mur ?
	  	int side; //un mur NS ou EW a-t-il été touché ?
	
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player.posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player.posY  - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player.posY ) * deltaDistY;
		}

		//perform DDA
	  	while (hit == 0)
	  	{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
	  	}
		double perpWallDist;
		if(side == 0)
	  		perpWallDist = (sideDistX - deltaDistX);
      	else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int h = screenHeight ;
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
    	int drawStart = -lineHeight / 2 + h / 2;
    	if(drawStart < 0)
			drawStart = 0;
    	int drawEnd = lineHeight / 2 + h / 2;
    	if(drawEnd >= h)
			drawEnd = h - 1;
		//choose wall color
        
    	// int color;
		// if (worldMap[mapX][mapY] == 1)
		// 	color = create_trgb(0, 255, 0, 0);
		// else if (worldMap[mapX][mapY] == 2)
		// 	color = create_trgb(0, 0, 255, 0);
		// else if (worldMap[mapX][mapY] == 3)
		// 	color = create_trgb(0, 0, 0, 255);
		// else if (worldMap[mapX][mapY] == 4)
		// 	color = create_trgb(0, 255, 255, 255);
		// else
		// 	color = create_trgb(0, 255, 255, 0);
		//give x and y sides different brightness
		// if (side == 1)
		// 	color = color / 2;

		//draw the pixels of the stripe as a vertical line

              //texturing calculations
        int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

      //calculate value of wallX
        double wallX; //where exactly the wall was hit
        if (side == 0) 
            wallX = game->player.posY + perpWallDist * rayDirY;
        else
            wallX = game->player.posX + perpWallDist * rayDirX;
        wallX -= floor((wallX));

      //x coordinate on the texture
        int texX = wallX * (double)(texWidth);
        if(side == 0 && rayDirX > 0) 
            texX = texWidth - texX - 1;
        if(side == 1 && rayDirY < 0) 
            texX = texWidth - texX - 1;
		
		double step = 1.0 * texHeight / lineHeight;
		double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y<drawEnd; y++)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
		}
    }
}

int	keey(int keycode, t_game *game)
{
	if (keycode == 65361)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-game->rotSpeed) - game->player.dirY * sin(-game->rotSpeed);
		game->player.dirY = oldDirX * sin(-game->rotSpeed) + game->player.dirY * cos(-game->rotSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-game->rotSpeed) - game->player.planeY * sin(-game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(-game->rotSpeed) + game->player.planeY * cos(-game->rotSpeed);
	}
	if (keycode == 65363)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(game->rotSpeed) - game->player.dirY * sin(game->rotSpeed);
		game->player.dirY = oldDirX * sin(game->rotSpeed) + game->player.dirY * cos(game->rotSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(game->rotSpeed) - game->player.planeY * sin(game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(game->rotSpeed) + game->player.planeY * cos(game->rotSpeed);
	}
	if (keycode == 122)
	{
		int x = game->player.posX + game->player.dirX * game->moveSpeed;
		int y = game->player.posY;
		if(worldMap[x][y] == 0)
		{
			double te = game->player.dirX * game->moveSpeed;
			game->player.posX += te;
		}
		x =	game->player.posX;
		y = game->player.posY + game->player.dirY * game->moveSpeed;
		if(worldMap[x][y] == 0)
		{
			double te = game->player.dirY * game->moveSpeed;
			game->player.posY += te;
		}
	}
	if (keycode == 115)
	{
		int x = game->player.posX - game->player.dirX * game->moveSpeed;
		int y = game->player.posY;
		if(worldMap[x][y] == 0)
			game->player.posX -= game->player.dirX * game->moveSpeed;
		x =	game->player.posX;
		y = game->player.posY - game->player.dirY * game->moveSpeed;
		if(worldMap[x][y] == 0)
			game->player.posY -= game->player.dirY * game->moveSpeed;
	}
	// if (keycode == 115 || keycode == 119
	// 	|| keycode == 97 || keycode == 100)
	// 	//moov
	// if (keycode == 65363 || keycode == 65361)
	// 	//cam
	// clear_window(game->mlibx.mlx_ptr, game->mlibx.win_ptr, 640, 480);
	// draw(game);
	printf("POS = X : %f y : %f\n", game->player.posX, game->player.posY);
	printf("DIR = X : %f y : %f\n", game->player.dirX, game->player.dirY);
	return (0);
}



int main()
{
	t_game game;
	int	width;
	int	height;
	
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	game.player.posX = 21;
	game.player.posY = 10;
	game.player.dirX = 1;
	game.player.dirY = 0;
	game.player.planeX = 0;
	game.player.planeY = 0.66;
	game.mlibx.mlx_ptr = mlx_init();
	game.mlibx.win_ptr = mlx_new_window(game.mlibx.mlx_ptr, screenWidth, screenHeight, "Cub3D");
	game.rotSpeed = 0.059400;
	game.moveSpeed = 0.1;
	game.NO = mlx_xpm_file_to_image(game.mlibx.mlx_ptr, "/home/jean/42_cursus/cub3D/assets/texture/eagle.xpm", &width, &height);
	game.SO = mlx_xpm_file_to_image(game.mlibx.mlx_ptr, "/home/jean/42_cursus/cub3D/assets/texture/greystone.xpm", &width, &height);
	game.WE = mlx_xpm_file_to_image(game.mlibx.mlx_ptr, "/home/jean/42_cursus/cub3D/assets/texture/purplestone.xpm", &width, &height);
	game.EA = mlx_xpm_file_to_image(game.mlibx.mlx_ptr, "/home/jean/42_cursus/cub3D/assets/texture/red.xpm", &width, &height);
	draw(&game);
	mlx_hook(game.mlibx.win_ptr, 2, 1L << 0, keey, &game);
	
	mlx_loop(game.mlibx.mlx_ptr);
	
	// oldTime = time;
    //time = getTicks();
	// double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    // print(1.0 / frameTime);

    //speed modifiers
    // game.moveSpeed = 2; //frameTime * 5.0; //the constant value is in squares/second
    // game.rotSpeed = 3; //frameTime * 3.0;
}