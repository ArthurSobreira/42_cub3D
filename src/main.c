/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/18 16:42:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_map(void)
{
	char	**map;
}

int	arrumar_depois(void)
{
	int		fd;
	int		i;
	char	*line;
	t_map	*map;

	i = 0;
	map = get_map();
	map->map_str = ft_calloc(sizeof(char *), (lenfd() + 1));
	fd = open("./maps/map1.cub", O_RDONLY);
	while (i < map->max_y - 1)
	{
		line = get_next_line(fd);
		map->map_str[i] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		i++;
	}
	map->map_str[i] = get_next_line(fd);
	map->set_max_x(maxcol());
	map->set_max_y(lenfd());
	ft_print_map();
	fill_with_spaces();
	ft_print_map();
	valid_open_map_x();
	// valid_open_map_y();
	maxcol();
	ft_free_matrix(map->map_str);
	close(fd);
	printf("ok\n");
}

int	main(void)
{
	constructor_map();
	set_max_xy();
	arrumar_depois();
	return (0);
}
