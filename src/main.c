/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/01 18:30:53 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_map(void)
{
	int	i;

	i = 0;
	while (get_map()->map_str[i])
	{
		if (get_map()->map_str[i])
			printf("%s\n", get_map()->map_str[i]);
		free(get_map()->map_str[i]);
		i++;
	}
}

static void	exit_program(void)
{
	ft_free_map();
	// mlx_terminate(get_mlx()->mlx);
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
	constructor_gnl();
	// map_builder();
	map_validation();
	ft_print_map();
	// mlx_teste();
	exit_program();
	return (EXIT_SUCCESS);
}
// get_parser_infos(core);
// continua no proximo episodio
