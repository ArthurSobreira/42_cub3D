/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/19 18:00:20 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_map(void)
{
	t_map	*map;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map = get_map();
	printf("max_y: %d\n", map->max_y);
	fd = open("./maps/map1.cub", O_RDONLY);
	while (i < map->max_y - 1)
	{
		line = get_next_line(fd);
		line[ft_strlen(line) - 1] = ' ';
		ft_memcpy(map->map_str[i], line, ft_strlen(line));
		printf("line: [%s]\n", map->map_str[i]);
		i++;
		free(line);
	}
}

int	main(void)
{
	t_map	*map;
	int		i;

	i = -1;
	constructor_map();
	map = get_map();
	set_max_y(lenfd());
	set_max_x(maxcol());
	printf("max_x: %d\n", map->max_x);
	printf("max_y: %d\n", map->max_y);
	return (0);
}
