/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:15:44 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/10 16:18:49 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	constructor_map(void)
{
	// int fd;

	// fd = open(get_core()->map_path, O_RDONLY);
	// if (fd < 0)
	// 	ft_error("Error opening map file");
	
	get_map()->max_y = 0;
	get_map()->max_x = 0;
	get_map()->set_max_x = &set_max_x;
	get_map()->set_max_y = &set_max_y;
	// close(fd);
	// get_next_line(-1);
}

void	constructor_gnl(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(get_core()->map_path, O_RDONLY);
	get_map()->map_str = ft_calloc(get_map()->max_y, sizeof(char *));
	get_next_line(-1);
	while (i < get_map()->max_y - 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_rstrip(line);
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		get_map()->map_str[i] = ft_strdup(line);
		free(line);
		i++;
	}
	get_map()->map_str[i] = NULL;
	close(fd);
}
