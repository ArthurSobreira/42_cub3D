/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:01:54 by arsobrei          #+#    #+#             */
/*   Updated: 2024/10/01 17:26:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_parser_infos(void)
{
	t_cub3d		*core;
	t_bool		is_map_flag;
	int			fd;
	char		*line;

	core = get_core();
	fd = open(core->map_path, O_RDONLY);
	if (fd < 0)
		ft_error(ERROR_INVALID_MAP_PATH);
	is_map_flag = FALSE;
	get_next_line(CLEAR_STATIC);
	while (!is_map_flag && !core->bad_flag)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error(ERROR_INCOMPLETE_MAP);
		parser_line(core->parser_infos, line, &is_map_flag);
		free(line);
	}
	get_next_line(CLEAR_STATIC);
	close(fd);
	if (core->texture_count != TEXTURES_LEN)
		ft_error(ERROR_INVALID_TEXTURE);
	if (core->color_count != COLORS_LEN)
		ft_error(ERROR_INVALID_COLOR);
}

void	parser_line(char **parser_infos, char *line, t_bool *is_map_flag)
{
	t_cub3d		*core;
	char		**splited_line;

	if (*line == '\0' || *line == '\n')
		return ;
	if (!is_color(line) && !is_texture(line))
	{
		*is_map_flag = TRUE;
		return ;
	}
	core = get_core();
	splited_line = ft_split(line, ' ');
	normalize_element(line);
	if (!splited_line)
		ft_error(ERROR_INCOMPLETE_MAP);
	else if (is_texture(splited_line[0]))
		core->texture_count = parser_texture(splited_line, parser_infos);
	else if (is_color(splited_line[0]))
		core->color_count = parser_color(splited_line, parser_infos);
	else
		ft_error(ERROR_INCOMPLETE_MAP);
	ft_free_matrix(splited_line);
}
