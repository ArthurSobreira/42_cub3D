/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:07:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/18 14:15:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_generate(void)
{
	int		fd;
	char	*line;
	int		max_x;
	int		i;

	i = 0;
	max_x = 0;
	fd = open(get_core()->map_path, O_RDONLY);
	get_next_line(CLEAR_STATIC);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_rstrip(line);
		if (line[0] != '\0' && in_map_line2())
		{
			get_map()->map_str[i++] = ft_strdup(line);
			if (max_x < (int)ft_strlen(line))
				max_x = ft_strlen(line);
		}
		free(line);
	}
	close(fd);
	get_map()->max_x = max_x;
}

void	get_map_size_y(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(get_core()->map_path, O_RDONLY);
	get_next_line(CLEAR_STATIC);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_rstrip(line);
		if (line[0] != '\0' && in_map_line())
			i++;
		free(line);
	}
	close(fd);
	get_map()->max_y = i;
}

void	map_builder(void)
{
	t_map	*map;

	map = get_map();
	get_map_size_y();
	map->map_str = ft_calloc(map->max_y + 1, sizeof(char *));
	map->map_str[map->max_y] = NULL;
	map_generate();
	ft_print_map();
	map_validation();
	map_cpy();
}
