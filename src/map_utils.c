/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:51:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/18 16:37:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_max_xy(void)
{
	int		fd;
	char	*buf;
	int		lines;
	int		col;

	fd = open("./maps/map1.cub", O_RDONLY);
	lines = 0;
	col = 0;
	buf = get_next_line(fd);
	while (buf)
	{
		lines++;
		if (col < ft_strlen(buf))
			col = ft_strlen(buf);
		free(buf);
		buf = get_next_line(fd);
	}
	get_map()->set_max_x(col);
	get_map()->set_max_y(lines);
	close(fd);
}

void	valid_open_map_x(void)
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
			{
				if ((j - 1 >= 0 && map[i][j - 1] == ' ') ||
					(j + 1 <= get_map()->max_x && map[i][j + 1] == ' '))
					ft_error("Map is not closed");
			}
			printf("i: %d, j: %d c:[%c]\n", i, j, map[i][j]);
			j++;
		}
		i++;
	}
}

void	valid_open_map_y(void)
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
				if ((i - 1 >= 0 && map[i - 1][j] == ' ') ||
					(i + 1 <= get_map()->max_y && map[i + 1][j] == ' '))
					ft_error("Map is not closed");
			j++;
		}
		i++;
	}
}

// if ((i - 1 >= 0 && map[i - 1][j] == ' ') ||
// 					(i + 1 <= get_map()->max_y && map[i + 1][j] == ' ') ||
// 					(j - 1 >= 0 && map[i][j - 1] == ' ') ||
// 					(j + 1 <= get_map()->max_x && map[i][j + 1] == ' '))
// 					ft_error("Map is not closed");

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
		// printf("\n");
	}
	printf("\n");
}
