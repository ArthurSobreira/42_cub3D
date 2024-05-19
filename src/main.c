/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/19 17:03:20 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_parser_infos(char **parser_infos)
{
	int	i;

	i = 0;
	while (i < PARSER_INFOS_LEN)
	{
		printf("%s\n", parser_infos[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_cub3d	*core;

	core = get_core();
	core->map_path = argv[1];
	core->texture_count = 0;
	core->color_count = 0;
	core->map_flag = TRUE;
	core->bad_flag = FALSE;
	if (argc != 2 || !valid_map_name(core->map_path))
		ft_error(ERROR_INVALID_MAP_PATH);
	get_parser_infos();
	map_builder();
	init_player();
	mlx_process();
	clear_all();
}

// print_parser_infos(core->parser_infos);
// constructor_map();
// continua no proximo episodio
