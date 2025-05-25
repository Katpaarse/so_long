/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:00:59 by jukerste          #+#    #+#             */
/*   Updated: 2025/05/25 18:22:18 by jukerste         ###   ########.fr       */
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
# define TILE_SIZE 32
#endif

typedef struct s_game
{
	char	**map;
	int		x;
	int		y;
	mlx_t	*mlx;
}	t_game;

int		count_lines_map(int fd);
char	**read_map(int fd, int size);
void	validate_map(char **map);
int		valid_flood_fill(char **map);
void	error_exit(char *msg);
void	free_map(char **map);
void	game_initializer(t_game *game);

#endif
