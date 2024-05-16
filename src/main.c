/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 18:59:09 by phenriq2         ###   ########.fr       */
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

static void	mlx_cursor(void)
{
	mlx_texture_t		*texture;
	mlx_win_cursor_t	*cursor;
	t_mlx				*mlx;

	mlx = get_mlx();
	texture = mlx_load_png(CURSOR_PATH);
	cursor = mlx_create_cursor(texture);
	mlx_set_cursor(mlx->win_ptr, cursor);
	mlx_cursor_hook(mlx->win_ptr, my_cursor, NULL);
}

void	mlx_process(void)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	mlx_loop_hook(mlx->win_ptr, render, mlx);
	mlx_image_to_window(mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_cursor();
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
	init_player();
	mlx_process();
	clear_all();
}

// print_parser_infos(core->parser_infos);
// constructor_map();
// continua no proximo episodio
