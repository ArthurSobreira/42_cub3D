/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:55:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/15 15:07:57 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == ESC && (keydata.action == P || keydata.action == RE))
	{
		clear_all();
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(mlx->win_ptr, W) || \
		mlx_is_key_down(mlx->win_ptr, UP))
		get_player()->y -= 4;
	if (mlx_is_key_down(mlx->win_ptr, D) || \
		mlx_is_key_down(mlx->win_ptr, RIGHT))
		get_player()->x += 4;
	if (mlx_is_key_down(mlx->win_ptr, A) || \
		mlx_is_key_down(mlx->win_ptr, LEFT))
		get_player()->x -= 4;
	if (mlx_is_key_down(mlx->win_ptr, S) || \
		mlx_is_key_down(mlx->win_ptr, DOWN))
		get_player()->y += 4;
}
