/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:28:20 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/22 12:32:07 by arsobrei         ###   ########.fr       */
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
