/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/18 16:03:39 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	int		fd;
	int		i;
	t_map	*map;

	constructor_map();
	i = 0;
	map = get_map();
	map->map_str = ft_calloc(sizeof(char *), (lenfd() + 1));
	fd = open("./maps/map1.cub", O_RDONLY);
	while (i < lenfd())
	{
		map->map_str[i] = get_next_line(fd);
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
	return (0);
}
