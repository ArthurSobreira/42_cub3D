/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:07:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/23 17:49:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_alloc(void)
{
	t_map	*map;
	char	*spaces;
	int		index;

	map = get_map();
	index = 0;
	map->set_max_x(maxcol());
	map->set_max_y(lenfd());
	spaces = ft_calloc(map->max_x, sizeof(char));
	ft_memset(spaces, ' ', map->max_x);
	map->map_str = ft_calloc(map->max_y, sizeof(char *));
	while (index < map->max_y - 1)
	{
		map->map_str[index] = ft_calloc(map->max_x + 1, sizeof(char));
		ft_memcpy(map->map_str[index], spaces, map->max_x);
		index++;
	}
	free(spaces);
	ft_print_map();
}

void	map_builder(void)
{
	int		fd;
	char	*line;
	int		index;

	fd = open("./assets/maps/map1.cub", O_RDONLY);
	map_alloc();
	line = get_next_line(fd);
	index = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = ' ';
		ft_memcpy(get_map()->map_str[index], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		index++;
	}
	printf("\n");
	ft_print_map();
	close(fd);
}
