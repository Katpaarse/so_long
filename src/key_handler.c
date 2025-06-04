/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:12:23 by jukerste          #+#    #+#             */
/*   Updated: 2025/06/04 20:23:41 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dy, int dx)
{
	int new_y;
	int new_x;

	new_y = game->player_y + dy;
	new_x = game->player_x + dx;
    if (game->map[new_y][new_x] == '1')
        return ;
    if (game->map[new_y][new_x] == 'C')
    {
        game->coins_collected++;
        game->map[new_y][new_x] = '0';
    }
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->coins_collected == game->total_coins)
        {
            mlx_image_to_window(game->mlx, game->img_floor, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
            mlx_image_to_window(game->mlx, game->img_player, new_x * TILE_SIZE, new_y * TILE_SIZE);
            game->map[game->player_y][game->player_x] = '0';
            game->player_x = new_x;
            game->player_y = new_y;
            ft_printf("You win the game!\n");
            mlx_close_window(game->mlx);
            return ;
        }
        else
            return ;
    }
    mlx_image_to_window(game->mlx, game->img_floor, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
    mlx_image_to_window(game->mlx, game->img_player, new_x * TILE_SIZE, new_y * TILE_SIZE);
    game->map[game->player_y][game->player_x] = '0';
    if (game->map[new_y][new_x] != 'E')
        game->map[new_y][new_x] = 'P';
    game->player_x = new_x;
    game->player_y = new_y;
    game->move_count++;
    ft_printf("Moves: %d\n", game->move_count);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_A)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S)
		move_player(game, 1, 0);
	else if (keydata.key == MLX_KEY_D)
		move_player(game, 0, 1);
}
