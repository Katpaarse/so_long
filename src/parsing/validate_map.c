/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:32:33 by jukerste          #+#    #+#             */
/*   Updated: 2025/05/29 15:17:15 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_is_rectangle(char **map)
{
	int	height;
	int	width;

	width = (int)ft_strlen(map[0]);
	height = 1;
	while (map[height])
	{
		if ((int)ft_strlen(map[height]) != width)
			return (0);
		height++;
	}
	return (1);
}

static int	map_has_valid_walls(char **map)
{
	int	width;
	int	height;
	int	x;
	int	y;

	height = 0;
	while (map[height])
		height++;
	width = (int)ft_strlen(map[0]) - 1;
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	map_elements(char **map)
{
	int	x;
	int	y;
	int	p;
	int	e;
	int	c;
	
	p = 0;
	c = 0;
	e = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p++;
			else if (map[y][x] == 'E')
				e++;
			else if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (p == 1 && e == 1 && c >= 1);
}

void	validate_map(char **map)
{
	if (!map_is_rectangle(map))
		error_exit("Map is not a rectangle");
	if (!map_has_valid_walls(map))
		error_exit("Map does not have valid walls");
	if (!map_elements(map))
		error_exit("Map must contain 1 P, 1 E and at least 1 C");
	if (!valid_flood_fill(map))
		error_exit("Not all collectables or exit are reachable");
}
