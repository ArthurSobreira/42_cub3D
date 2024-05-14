/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/14 18:43:00 by arsobrei         ###   ########.fr       */
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

static void	mlx_process(void)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	mlx_loop_hook(mlx->win_ptr, render, mlx);
	mlx_image_to_window(mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, &my_keyhook, mlx);
	mlx_loop(mlx->win_ptr);
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
	map_builder();
	mlx_process();
	clear_all();
}
// print_parser_infos(core->parser_infos);
// constructor_map();
// continua no proximo episodio
