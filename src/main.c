/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/22 11:15:02 by phenriq2         ###   ########.fr       */
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
	fd = open("./maps/map1.cub", O_RDONLY);
	map->map_str = malloc(sizeof(char *) * map->max_y);
	while (i < map->max_y)
	{
		map->map_str[i] = malloc(sizeof(char) * map->max_x);
		i++;
	}
	i = 0;
	while (i < map->max_y - 1)
	{
		line = get_next_line(fd);
		line[ft_strlen(line) - 1] = '\0';
		ft_memcpy(map->map_str[i], line, ft_strlen(line));
		i++;
		free(line);
	}
	line = get_next_line(-1);
	map->map_str[lenfd() - 1] = NULL;
	close(fd);
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
	build_map();
	ft_print_map();
	ft_free_matrix(map->map_str);
	return (0);
}
