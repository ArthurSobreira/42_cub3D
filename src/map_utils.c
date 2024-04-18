/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:51:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/18 11:36:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	lenfd(void)
{
	int		bytes;
	int		fd;
	char	buf[1];
	int		lines;

	bytes = 0;
	lines = 1;
	fd = open("./maps/map1.cub", O_RDONLY);
	bytes = read(fd, buf, 1);
	while (bytes)
	{
		if (buf[0] == '\n')
			lines++;
		bytes = read(fd, buf, 1);
	}
	close(fd);
	get_map()->set_max_y(lines);
	return (lines);
}

size_t	maxcol(void)
{
	int		i;
	size_t	max;
	t_map	*map_struct;

	i = 0;
	max = 0;
	map_struct = get_map();
	while (map_struct->map_str[i])
	{
		if (ft_strlen(map_struct->map_str[i]) > max)
			max = ft_strlen(map_struct->map_str[i]);
		i++;
	}
	map_struct->set_max_x(max);
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
				if ((i - 1 >= 0 && map[i - 1][j] == ' ') ||
					(i + 1 <= get_map()->max_y && map[i + 1][j] == ' ') ||
					(j - 1 >= 0 && map[i][j - 1] == ' ') ||
					(j + 1 <= get_map()->max_x && map[i][j + 1] == ' '))
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
	}
	printf("\n");
}
