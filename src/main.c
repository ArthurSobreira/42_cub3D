/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/10 16:22:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_program(void)
{
	// mlx_terminate(get_mlx()->mlx);
	ft_free_matrix(get_map()->map_str);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_cub3d	*core;

	core = get_core();
	core->map_path = argv[1];
	if (argc != 2 || !valid_map_name(core->map_path))
		ft_error(ERROR_INVALID_MAP_PATH);
	constructor_map();
	// ft_print_map();
	// mlx_teste();
	exit_program();
	return (EXIT_SUCCESS);
}
	// constructor_gnl();
	// get_map()->max_y = ft_matrix_len(get_map()->map_str);
// map_builder();
	// map_validation();
// get_parser_infos(core);
// continua no proximo episodio
