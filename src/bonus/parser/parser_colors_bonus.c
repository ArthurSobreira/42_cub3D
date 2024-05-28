/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:59:32 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 12:38:15 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_bool	match_color(char *identifier, t_colors match, \
											short color_count)
{
	static char		*parser_checker[COLORS_LEN] = {
		"F", "C"
	};

	if (ft_strcmp(identifier, parser_checker[match - 4]) == 0)
	{
		parser_checker[match - 4] = NULL;
		if (color_count > COLORS_LEN)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	is_valid_color(char *color)
{
	char	**colors_matrix;
	size_t	index;

	index = 0;
	colors_matrix = ft_split(color, ',');
	if (!colors_matrix || ft_matrix_len(colors_matrix) != 3)
	{
		ft_free_matrix(colors_matrix);
		return (FALSE);
	}
	while (colors_matrix[index])
	{
		normalize_element(colors_matrix[index]);
		if (!ft_isnumber(colors_matrix[index]) || \
			ft_atoi(colors_matrix[index]) > 255 || \
			ft_atoi(colors_matrix[index]) < 0)
		{
			ft_free_matrix(colors_matrix);
			return (FALSE);
		}
		index++;
	}
	ft_free_matrix(colors_matrix);
	return (TRUE);
}

short	parser_color(char **s_line, char **parser_infos)
{
	static short	color_count = 0;
	char			*identifier;
	char			*color;

	identifier = s_line[0];
	color = s_line[1];
	if (is_color(identifier))
	{
		color_count++;
		if (match_color(identifier, FLOOR, color_count) && \
			is_valid_color(color))
			parser_infos[FLOOR] = ft_strdup(color);
		else if (match_color(identifier, CEIL, color_count) && \
			is_valid_color(color))
			parser_infos[CEIL] = ft_strdup(color);
		else
		{
			color_count -= 2;
			get_core()->bad_flag = TRUE;
			ft_putstr_fd(ERROR_INVALID_COLOR, 2);
		}
	}
	else
		ft_error(ERROR_INVALID_COLOR);
	return (color_count);
}
