/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/22 16:45:04 by phenriq2         ###   ########.fr       */
=======
/*   Updated: 2024/04/22 16:46:16 by phenriq2         ###   ########.fr       */
>>>>>>> feature/map_constructor
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	*core;

	core = get_core();
	core->map_path = argv[1];
	if (argc != 2 || !valid_map_name(core->map_path))
		ft_error(ERROR_INVALID_MAP_PATH);
	get_parser_infos(core);
	constructor_map();
<<<<<<< HEAD
}
	// continua no proximo episodio
=======
	map_builder();
	map_validation();
	ft_free_matrix(get_map()->map_str);
	return (EXIT_SUCCESS);
}
// continua no proximo episodio
>>>>>>> feature/map_constructor
