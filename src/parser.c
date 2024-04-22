/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:01:54 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/22 16:54:28 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	valid_map_name(char *map_name)
{
	size_t	length;
	int		fd;
	char	*first_line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	length = ft_strlen(map_name);
	if (ft_strncmp(map_name + length - 4, ".cub", 4) || length < 5)
		return (FALSE);
	first_line = get_next_line(fd);
	if (!first_line || !*first_line)
	{
		free(first_line);
		return (FALSE);
	}
	free(first_line);
	close(fd);
	return (TRUE);
}

char	**get_parser_infos(t_cub3d *core)
{
	char	**parser_infos;
	char	*line;
	int		fd;
	size_t	index;

	line = NULL;
	index = 0;
	parser_infos = (char **)ft_calloc(sizeof(char *), PARSER_INFOS_LEN);
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
