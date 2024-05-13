/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/13 13:29:53 by arsobrei         ###   ########.fr       */
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
	t_mlx	*mlx;

	core = get_core();
	core->map_path = argv[1];
	if (argc != 2 || !valid_map_name(core->map_path))
		ft_error(ERROR_INVALID_MAP_PATH);
	core->texture_count = 0;
	core->color_count = 0;
	get_parser_infos();
	map_builder();
	mlx = init_mlx();
	
	render_background(mlx);
	mlx_image_to_window(mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_loop(mlx->win_ptr);

	// print_parser_infos(core->parser_infos);
	// constructor_map();
	clear_all();
}
// continua no proximo episodio
