/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:46:26 by jukerste          #+#    #+#             */
/*   Updated: 2025/05/25 13:29:54 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines_map(int fd)
{
	int		i;
	char	*lines;

	i = 0;
	while ((lines = get_next_line(fd)))
	{
		free(lines);
		i++;
	}
	return (i);
}

char	**read_map(int fd, int size)
{
	char	**map;
	int		i;

	map = ft_calloc(size + 1, sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(map[i]);
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	map[size] = NULL;
	return (map);
}
