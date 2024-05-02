/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:50:08 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/02 13:04:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_teste(void)
{
	t_mlx		*mlx;
	mlx_image_t	*img;

	mlx = get_mlx();
	mlx->mlx = mlx_init(WIDTH, HEIGHT, "mlx_tester", TRUE);
	img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->texture = mlx_load_png(TEST_PATH_IMG);
	mlx->img = mlx_texture_to_image(get_mlx()->mlx, mlx->texture);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	mlx_delete_texture(mlx->texture);
	mlx_delete_image(mlx->mlx, img);
}
