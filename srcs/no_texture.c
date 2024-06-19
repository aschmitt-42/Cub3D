#include "cub3d.h"
#include <math.h>
#define mapWidth 24
#define mapHeight 24
#define screenWidth 1024
#define screenHeight 512

void	draw(t_game *game);

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/*
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
*/

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}


void clear_window(void *mlx_ptr, void *win_ptr, int width, int height)
{
    int x, y;
	int color = create_trgb(0, 0,0,0);

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
        }
    }
}

void put_pixel_to_image(char *data, int x, int y, int color, int size_line, int bpp) {
    int offset = y * size_line + x * (bpp / 8);
    *(int *)(data + offset) = color;
}

int	play(t_game *game)
{
	draw(game);
	if (game->key.left)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-game->rotSpeed) - game->player.dirY * sin(-game->rotSpeed);
		game->player.dirY = oldDirX * sin(-game->rotSpeed) + game->player.dirY * cos(-game->rotSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-game->rotSpeed) - game->player.planeY * sin(-game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(-game->rotSpeed) + game->player.planeY * cos(-game->rotSpeed);
	}
	if (game->key.right)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(game->rotSpeed) - game->player.dirY * sin(game->rotSpeed);
		game->player.dirY = oldDirX * sin(game->rotSpeed) + game->player.dirY * cos(game->rotSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(game->rotSpeed) - game->player.planeY * sin(game->rotSpeed);
		game->player.planeY = oldPlaneX * sin(game->rotSpeed) + game->player.planeY * cos(game->rotSpeed);
	}
	if (game->key.z)
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
	if (game->key.s)
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
	if (game->key.d)
	{
		int x = game->player.posX - game->player.dirY * (game->moveSpeed * 2);
		int y = game->player.posY;
		if(worldMap[x][y] == 0)
			game->player.posX -= game->player.dirY * game->moveSpeed;
		x = game->player.posX;
		y = game->player.posY + game->player.dirX * (game->moveSpeed * 2);
		if(worldMap[x][y] == 0)
			game->player.posY += game->player.dirX * game->moveSpeed;
	}
	if (game->key.q)
	{
		int x = game->player.posX + game->player.dirY * (game->moveSpeed * 2);
		int y = game->player.posY;
		if(worldMap[x][y] == 0)
			game->player.posX += game->player.dirY * game->moveSpeed;
		x = game->player.posX;
		y = game->player.posY - game->player.dirX * (game->moveSpeed * 2);
		if(worldMap[x][y] == 0)
			game->player.posY -= game->player.dirX * game->moveSpeed;
	}
	// t_img tmp = game->img;
	// game->img = game->img2;
	// game->img2 = tmp;
}

void	draw(t_game *game)
{
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX; //length of ray from current position to next x or y-side
	double sideDistY;
	double deltaDistX; //longueur du rayon depuis la position actuelle jusqu'au prochain côté x ou y
	double deltaDistY;
	int stepX; //dans quelle direction avancer dans la direction x ou y (soit +1 ou -1)
	int stepY;
	int hit; //Y a-t-il eu un coup de mur ?
	int side; //un mur NS ou EW a-t-il été touché ?
	double perpWallDist;
	int h;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int color;
	int plafond = create_trgb(0, 64,0,64);
	int sol = create_trgb(0, 192,0,192);

	// printf("x : %f\ny : %f\n", game.player.dirX, game.player.dirY);
	for(double x = 0; x < screenWidth ; x++)
	{
		//calculate ray position and direction
		cameraX = 2 * x / (double)screenWidth - 1; // x-coordinate in camera space
		
		rayDirX = game->player.dirX + game->player.planeX * cameraX;
		rayDirY = game->player.dirY + game->player.planeY * cameraX;
		//dans quelle case de la carte nous nous trouvons (convertir double en int)
		mapX = game->player.posX;
		mapY = game->player.posY;

		if (rayDirX == 0)
			deltaDistX = 1e30;
		else 
			deltaDistX = fabs(1 / rayDirX); // sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		
		if (rayDirY == 0) 
			deltaDistY = 1e30;
		else 
			deltaDistY = fabs(1 / rayDirY); //  sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY)); 
		hit = 0;
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
		
		if(side == 0)
	  		perpWallDist = (sideDistX - deltaDistX);
      	else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		h = screenHeight ;
		lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
    	drawStart = -lineHeight / 2 + h / 2;
    	if(drawStart < 0)
			drawStart = 0;
    	drawEnd = lineHeight / 2 + h / 2;
    	if(drawEnd >= h)
			drawEnd = h - 1;
		//choose wall color
    	
		if (worldMap[mapX][mapY] == 1)
			color = create_trgb(0, 255, 0, 0);
		else if (worldMap[mapX][mapY] == 2)
			color = create_trgb(0, 0, 255, 0);
		else if (worldMap[mapX][mapY] == 3)
			color = create_trgb(0, 0, 0, 255);
		else if (worldMap[mapX][mapY] == 4)
			color = create_trgb(0, 255, 255, 255);
		else
			color = create_trgb(0, 255, 255, 0);
		//give x and y sides different brightness
		// if (side == 1)
		// 	color = color / 2;

		//draw the pixels of the stripe as a vertical line
		for (int y = 0; y < screenHeight; y++)
		{
			if (y < drawStart)
				mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, x, y, sol);
			else if (y > drawEnd)
				mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, x, y, plafond);
			else
				mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, x, y, color);
		}
		/*
		
		int test;
		for (int y = 0; y < screenHeight; y++)
		{
			test = y * game->img.size_line / 4 + x;
			if (y < drawStart)
				*(game->img.addr + test) = sol;
			else if (y > drawEnd)
				*(game->img.addr + test) = plafond;
			else
				*(game->img.addr + test) = color;
		}
		mlx_put_image_to_window(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->img.img, 0, 0);

		*/
		// put_pixel_to_image(game->img.addr, x, y, sol, game->img.size_line, game->img.bpp); // data[y * size_line / 4 + game->player.dirX] = sol; // mlx_pixel_put(game->mlibx.mlx_ptr, game->mlibx.win_ptr, x, y, sol);
			
    }
}

/*
65361 : fleche gauche
65363 : fleche droite
122 : z
113 : q
115 : s
100 : d
*/

int		ft_key_press(int keycode, t_game *game)
{
	
	printf("%d\n", keycode);
	if (keycode == 122)
		game->key.z = 1;
	else if (keycode == 115)
		game->key.s = 1;
	else if (keycode == 100)
		game->key.d = 1;
	else if (keycode == 113)
		game->key.q = 1;
	else if (keycode == 65361)
		game->key.left = 1;
	else if (keycode == 65363)
		game->key.right = 1;
	// else if (keycode == 65307)
		// close
	return (1);
}
int		ft_key_release(int keycode, t_game *game)
{
	if (keycode == 122)
		game->key.z = 0;
	else if (keycode == 115)
		game->key.s = 0;
	else if (keycode == 100)
		game->key.d = 0;
	else if (keycode == 113)
		game->key.q = 0;
	else if (keycode == 65361)
		game->key.left = 0;
	else if (keycode == 65363)
		game->key.right = 0;
	return (1);
}

int main()
{
	t_game game;
	
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame
	game.key.z = 0;
	game.key.s = 0;
	game.key.q = 0;
	game.key.d = 0;
	game.key.left = 0;
	game.key.right = 0;
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
	game.img.img = mlx_new_image(game.mlibx.mlx_ptr, screenWidth, screenHeight);
	game.img.addr = (int *)mlx_get_data_addr(game.img.img, &game.img.bpp,&game.img.size_line, &game.img.endian);
	game.img2.img = mlx_new_image(game.mlibx.mlx_ptr, screenWidth, screenHeight);
	game.img2.addr = (int *)mlx_get_data_addr(game.img2.img, &game.img2.bpp,&game.img2.size_line, &game.img2.endian);
	draw(&game);
	mlx_hook(game.mlibx.win_ptr, 2, 1L << 0, ft_key_press, &game);

	mlx_loop_hook(game.mlibx.mlx_ptr, play, &game);
	
	mlx_hook(game.mlibx.win_ptr, 3, 1L << 1, ft_key_release, &game);

	mlx_loop(game.mlibx.mlx_ptr);
	
	// oldTime = time;
    //time = getTicks();
	// double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    // print(1.0 / frameTime);

    //speed modifiers
    // game.moveSpeed = 2; //frameTime * 5.0; //the constant value is in squares/second
    // game.rotSpeed = 3; //frameTime * 3.0;
	

	
}
