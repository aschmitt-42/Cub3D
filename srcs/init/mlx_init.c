/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:14:43 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/02 18:06:13 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	close_win(t_game *game)
{
	free_game(game, 10);
	return (0);
}

int	keybind(int keycode, t_game *game)
{
	//ft_printf("Keypressed : %d\n", keycode);
	if (keycode == 65307)
		close_win(game);
	if (keycode == 115 || keycode == 119
		|| keycode == 97 || keycode == 100)
		(void)game;//cam
	if (keycode == 65363 || keycode == 65361 ||
		keycode == 65364 || keycode == 65362)
		(void)game;//mouv
	return (0);
}

int	mouse_hook(int keycode, t_game *game)
{
	printf("MOUSE : %d\n", keycode);
	(void)game;
	return (0);
}

void	init_mlx(t_game *game)
{
	game->mlibx.win_ptr = mlx_new_window
		(game->mlibx.mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!game->mlibx.win_ptr)
		free_game(game, 1);
	mlx_hook(game->mlibx.win_ptr, 2, 1L << 0, keybind, game);
	mlx_hook(game->mlibx.win_ptr, 17, 1L << 0, close_win, game);
	mlx_mouse_hook(game->mlibx.win_ptr, mouse_hook, game);
}
