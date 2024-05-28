/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:28:20 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 12:38:08 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	normalize_element(char *start)
{
	char	*end;

	end = start;
	while (*end && *end == ' ')
		end++;
	if (start != end)
		ft_memmove(start, end, ft_strlen(end) + 1);
	while (*start)
	{
		if (*start == ' ')
		{
			end = start + 1;
			while (*end && *end == ' ')
				end++;
			if (start + 1 != end)
				ft_memmove(start + 1, end, ft_strlen(end) + 1);
		}
		if ((*start == '\n' || *start == '\r') && start[1] == '\0')
			*start = 0;
		if (*start)
			start++;
	}
}

t_bool	valid_map_name(char *map_name)
{
	size_t	length;
	int		fd;

	length = ft_strlen(map_name);
	if (!ft_strnstr(map_name, ".cub", length))
		return (FALSE);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
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

t_bool	is_texture(char *line)
{
	size_t	index;

	index = 0;
	while (line[index] && line[index] == ' ')
		index++;
	if ((line[index] == 'N' && line[index + 1] == 'O') || \
		(line[index] == 'S' && line[index + 1] == 'O') || \
		(line[index] == 'W' && line[index + 1] == 'E') || \
		(line[index] == 'E' && line[index + 1] == 'A'))
		return (TRUE);
	return (FALSE);
}

t_bool	is_color(char *line)
{
	size_t	index;

	index = 0;
	while (line[index] && line[index] == ' ')
		index++;
	if (line[index] == 'F' || line[index] == 'C')
		return (TRUE);
	return (FALSE);
}
