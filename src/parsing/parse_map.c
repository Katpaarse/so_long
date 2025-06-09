/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:46:26 by jukerste          #+#    #+#             */
/*   Updated: 2025/06/09 20:44:03 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines_map(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
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
			while (i > 0)
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

char	**parse_map(const char *filename)
{
	int		fd;
	int		count_lines;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count_lines = count_lines_map(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = read_map(fd, count_lines);
	close(fd);
	return (map);
}
