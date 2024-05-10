/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:07:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/10 18:04:41 by phenriq2         ###   ########.fr       */
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
	get_next_line(-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_rstrip(line);
		if (line[0] != '\0' && is_map_line(line))
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
	get_next_line(-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_rstrip(line);
		if (line[0] != '\0' && is_map_line(line))
			i++;
		free(line);
	}
	close(fd);
	get_map()->max_y = i;
}

// void	normalize_map(void);

void	map_builder(void)
{
	get_map_size_y();
	get_map()->map_str = ft_calloc(get_map()->max_y + 1, sizeof(char *));
	get_map()->map_str[get_map()->max_y] = NULL;
	map_generate();
	printf("max_x: %d\n", get_map()->max_x);
	printf("max_y: %d\n", get_map()->max_y);
	ft_print_map();
	map_validation();
	// normalize_map();
}