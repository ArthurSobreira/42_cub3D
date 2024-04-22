/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/22 11:56:12 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_map(char *line)
{
	size_t	index;

	index = 0;
	while (line[index])
	{
		if (!ft_strchr(PERMITED_MAP_CHARS, line[index]))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

char	**get_parser_infos(t_cub3d *core)
{
	char	**parser_infos;
	char	*line;
	int		fd;
	size_t	index;

	if (core->error)
		return (NULL);
	line = NULL;
	index = 0;
	parser_infos = (char**)ft_calloc(sizeof(char *), PARSER_INFOS_LEN);
	fd = open(core->map_path, O_RDONLY);
	if (fd < 0)
		ft_error(ERROR_INVALID_MAP_PATH);
	while (line && index < PARSER_INFOS_LEN)
	{
		line = get_next_line(fd);
		if (line && *line && ft_strchr("RNSWEFC", *line))
		{
			parser_infos[index] = line;
			index++;
		}
		free(line);
	}
	if (index != PARSER_INFOS_LEN)
		ft_error(ERROR_INCOMPLETE_MAP);
	close(fd);
	return (parser_infos);
}

int	main(int argc, char *argv[])
{
	t_cub3d	*core;
	int	fd;
	int	i;

	core = get_core();
	core->map_path = argv[1];
	if (argc != 2 || !valid_map_name(core->map_path))
		ft_error(ERROR_INVALID_MAP_PATH);
	i = 0;
	get_parser_infos(core);
	constructor_map();
	get_map()->map_str = ft_calloc(sizeof(char *), (lenfd() + 1));
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
	valid_open_map();
	ft_free_matrix(get_map()->map_str);
	close(fd);
	printf("ok\n");
	return (EXIT_SUCCESS);	
}
