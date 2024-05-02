/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:44:04 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/02 13:09:13 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	match_texture(char *identifier, t_textures match, \
												short *texture_count)
{
	static char		*parser_checker[TEXTURES_LEN] = {
		"NO", "SO", "WE", "EA"
	};

	if (ft_strcmp(identifier, parser_checker[match]) == 0)
	{
		parser_checker[match] = NULL;
		if (*texture_count > TEXTURES_LEN)
			return (FALSE);
		*texture_count += 1;
		return (TRUE);
	}
	return (FALSE);
}

short	parser_texture(char **s_line, char **parser_infos)
{
	static short	texture_count = 0;
	char			*identifier;
	char			*texture;

	identifier = s_line[0];
	texture = s_line[1];
	if (is_texture(identifier))
	{
		if (match_texture(identifier, NORTH, &texture_count))
			parser_infos[NORTH] = ft_strdup(texture);
		else if (match_texture(identifier, SOUTH, &texture_count))
			parser_infos[SOUTH] = ft_strdup(texture);
		else if (match_texture(identifier, WEST, &texture_count))
			parser_infos[WEST] = ft_strdup(texture);
		else if (match_texture(identifier, EAST, &texture_count))
			parser_infos[EAST] = ft_strdup(texture);
	}
	else
		ft_error(ERROR_INVALID_TEXTURE);
	return (texture_count);
}
