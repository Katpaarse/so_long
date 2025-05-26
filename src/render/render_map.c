/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:47:35 by jukerste          #+#    #+#             */
/*   Updated: 2025/05/26 16:40:35 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, char tile, int x, int y, int width, int height)
{
	(void) height;
	(void) width;
	if (tile == '1')
	{
		if (y == 0 || y == height -1)
			mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_image_to_window(game->mlx, game->img_side_wall, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == '0')
		mlx_image_to_window(game->mlx, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_image_to_window(game->mlx, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	height;
	int	width;

	height = 0;
	while (game->map[height])
		height++;
	width = ft_strlen(game->map[0]);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y, width, height);
			x++;
		}
		y++;
	}
}
