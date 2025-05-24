/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:46:26 by jukerste          #+#    #+#             */
/*   Updated: 2025/05/24 18:18:20 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(const char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while (line = get_next_line(fd))
	{
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}

char	**read_map(const char *filename)
{
	int		i;
	int		fd;
	int		total_lines;
	char	**map;

	
}