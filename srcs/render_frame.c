/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:25:32 by eboumaza          #+#    #+#             */
/*   Updated: 2024/06/02 18:05:58 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_game *game)
{
	if (!game->mlibx.mlx_ptr || !game->mlibx.win_ptr || !game->SO)
		printf("test\n");
	//mlx_put_image_to_window (game->mlibx.mlx_ptr, game->mlibx.win_ptr, game->SO, 1, 1);
	return (0);
}
