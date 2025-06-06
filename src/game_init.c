/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:07:04 by jukerste          #+#    #+#             */
/*   Updated: 2025/06/06 16:11:41 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->has_won = 0;
	game->coins_collected = 0;
	game->total_coins = 0;
	game->move_count = 0;
	game->map_width = ft_strlen(game->map[0]) - 1;
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->mlx = mlx_init(game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		error_exit("MLX42 initialization failed");
	count_coins(game);
}

void	count_coins(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	game->total_coins = count;
}
