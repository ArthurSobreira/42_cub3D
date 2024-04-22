/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/22 12:03:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	*core;
	int		fd;
	int		i;

	core = get_core();
	core->map_path = argv[1];
	if (argc != 2 || !valid_map_name(core->map_path))
		ft_error(ERROR_INVALID_MAP_PATH);
	i = 0;
	get_parser_infos(core);
	constructor_map();
	// continua no proximo episodio
}

// int	main(void)
// {
// 	t_map	*map;
// 	int		i;

// 	i = -1;
// 	constructor_map();
// 	map = get_map();
// 	set_max_y(lenfd());
// 	set_max_x(maxcol());
// 	build_map();
// 	ft_print_map();
// 	valid_open_map();
// 	ft_free_matrix(get_map()->map_str);
// 	close(fd);
// 	printf("ok\n");
// 	return (EXIT_SUCCESS);
// }
