/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/22 11:35:08 by arsobrei         ###   ########.fr       */
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
	while (i < lenfd())
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
	return (EXIT_SUCCESS);	
}
