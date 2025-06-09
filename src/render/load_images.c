/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:37:46 by jukerste          #+#    #+#             */
/*   Updated: 2025/06/09 16:08:19 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	mlx_texture_t	*texture;

	load_wall_images(game);
	texture = mlx_load_png("src/assets/Floor.png");
	game->img_floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("src/assets/Player.png");
	game->img_player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("src/assets/Collectible.png");
	game->img_collectible = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("src/assets/Exit.png");
	game->img_exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (game->img_wall == NULL || game->img_floor == NULL
		|| game->img_player == NULL || game->img_exit == NULL
		|| game->img_collectible == NULL)
		error_exit("Failed to load one or more images");
}

void	load_wall_images(t_game *game)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("src/assets/Wall.png");
	game->img_wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("src/assets/Wall_side_right.png");
	game->img_side_wall_right = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("src/assets/Wall_side_left.png");
	game->img_side_wall_left = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("src/assets/Wall_side.png");
	game->img_side_wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
