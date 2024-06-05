/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:25:32 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/05 16:22:41 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_game *game)
{
	if (!game->mlibx.mlx_ptr || !game->mlibx.win_ptr || !game->SO)
		printf("test\n");
	mlx_put_image_to_window(game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->SO, 100, 300);
	return (0);
}
