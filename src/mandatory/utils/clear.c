/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:54:25 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 18:50:47 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_local_matrix(char **matrix)
{
	size_t	index;

	index = 0;
	while (index < PARSER_LEN)
	{
		if (matrix[index])
			free(matrix[index]);
		index++;
	}
}

void	clear_mlx(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	if (mlx->img_ptr)
		mlx_delete_image(mlx->win_ptr, mlx->img_ptr);
	if (mlx->textures[NORTH])
		mlx_delete_texture(mlx->textures[NORTH]);
	if (mlx->textures[SOUTH])
		mlx_delete_texture(mlx->textures[SOUTH]);
	if (mlx->textures[WEST])
		mlx_delete_texture(mlx->textures[WEST]);
	if (mlx->textures[EAST])
		mlx_delete_texture(mlx->textures[EAST]);
	if (mlx->win_ptr)
		mlx_terminate(mlx->win_ptr);
}

void	clear_all(void)
{
	t_cub3d	*core;

	core = get_core();
	clear_mlx();
	free_local_matrix(core->parser_infos);
	if (get_map()->map_str)
		ft_free_matrix(get_map()->map_str);
	if (!get_core()->bad_flag)
		ft_putstr_fd(SUCCESS_MESSAGE, STDOUT_FILENO);
}
