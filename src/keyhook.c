/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:55:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/14 17:07:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == ESC && (keydata.action == P || keydata.action == RE))
	{
		clear_all();
		exit(EXIT_SUCCESS);
	}
	if ((keydata.key == UP || keydata.key == W) && (keydata.action == P
			|| keydata.action == RE))
		return ;
	if ((keydata.key == RIGHT || keydata.key == D) && (keydata.action == P
			|| keydata.action == RE))
		return ;
	if ((keydata.key == LEFT || keydata.key == A) && (keydata.action == P
			|| keydata.action == RE))
		return ;
	if ((keydata.key == DOWN || keydata.key == S) && (keydata.action == P
			|| keydata.action == RE))
		return ;
}
