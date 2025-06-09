/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:47:35 by jukerste          #+#    #+#             */
/*   Updated: 2025/06/09 16:08:51 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, char tile, int y, int x)
{
	mlx_image_to_window(game->mlx, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
	{
		if (y == 0 || y == game->map_height - 1)
			mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
		else if (x == 0)
			mlx_image_to_window(game->mlx, game->img_side_wall_left, x * TILE_SIZE, y * TILE_SIZE);
		else if (x == game->map_width - 1)
			mlx_image_to_window(game->mlx, game->img_side_wall_right, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_image_to_window(game->mlx, game->img_side_wall, x * TILE_SIZE, y * TILE_SIZE);
	}
	if (tile == 'C')
		mlx_image_to_window(game->mlx, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		mlx_image_to_window(game->mlx, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, game->map[y][x], y, x);
			x++;
		}
		y++;	
	}
}
