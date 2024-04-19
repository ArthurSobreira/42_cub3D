/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:51:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/19 17:51:58 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	lenfd(void)
{
	int		fd;
	char	*buf;
	int		lines;

	fd = open("./maps/map1.cub", O_RDONLY);
	lines = 0;
	buf = "get";
	while (buf)
	{
		buf = get_next_line(fd);
		lines++;
		free(buf);
	}
	close(fd);
	return (lines);
}

size_t	maxcol(void)
{
	size_t	max;
	int		fd;
	char	*line;
	int		i;

	max = 0;
	i = -1;
	fd = open("./maps/map1.cub", O_RDONLY);
	line = "get";
	while (++i < lenfd() - 1)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) > max)
			max = ft_strlen(line);
		free(line);
	}
	close(fd);
	return (max);
}

void	valid_open_map(void)
{
	char	**map;
	int		i;
	int		j;

	map = get_map()->map_str;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				if ((i - 1 >= 0 && (map[i - 1][j] == ' ' || map[i
							- 1][j] == '\0')) ||
					(i + 1 <= get_map()->max_y && (map[i + 1][j] == ' ' || map[i
								+ 1][j] == '\0')) ||
					(j - 1 >= 0 && map[i][j - 1] == ' ') ||
					(j + 1 <= get_map()->max_x && (map[i][j + 1] == ' '
								|| map[i][j + 1] == '\0')))
					ft_error("Map is not closed");
			j++;
		}
		i++;
	}
}

void	ft_print_map(void)
{
	int		i;
	int		j;
	char	**map;

	map = get_map()->map_str;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}
