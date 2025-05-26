/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:00:59 by jukerste          #+#    #+#             */
/*   Updated: 2025/05/26 16:22:39 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "MLX42/MLX42.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

#ifndef TILE_SIZE
# define TILE_SIZE 64
#endif

typedef struct s_game
{
	char		**map;
	int			x;
	int			y;
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_side_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collectible;
}	t_game;

int		count_lines_map(int fd);
char	**read_map(int fd, int size);
void	validate_map(char **map);
int		valid_flood_fill(char **map);
void	error_exit(char *msg);
void	free_map(char **map);
void	game_initializer(t_game *game);
void	render_map(t_game *game);
void	load_images(t_game *game);
char	**parse_map(const char *filename);

#endif
