/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/07 17:30:22 by phenriq2         ###   ########.fr       */
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
	if (argc != 2 || !valid_map_name(core->map_path))
		ft_error(ERROR_INVALID_MAP_PATH);
	core->texture_count = 0;
	core->color_count = 0;
	get_parser_infos();
	print_parser_infos(core->parser_infos);
	clear_all();
	// constructor_map();
	// continua no proximo episodio
}
