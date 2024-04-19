/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/19 11:54:56 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_map(void)
{
	char	**map;
}

int	arrumar_depois(void)
{
	int	fd;
	int	i;

	i = 0;
	constructor_map();
	get_map()->map_str = ft_calloc(sizeof(char *), (lenfd() + 1));
	fd = open("./maps/map1.cub", O_RDONLY);
	while (i < map->max_y - 1)
	{
		get_map()->map_str[i] = get_next_line(fd);
		i++;
	}
	get_map()->map_str[i] = get_next_line(fd);
	ft_print_map();
	valid_open_map();
	ft_free_matrix(get_map()->map_str);
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
