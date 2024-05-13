/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:54:25 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/13 13:58:43 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_local_matrix(char **matrix)
{
	size_t	index;

	index = 0;
	while (index < PARSER_INFOS_LEN)
	{
		if (matrix[index])
			free(matrix[index]);
		index++;
	}
}

void	clear_all(void)
{
	t_cub3d	*core;

	core = get_core();
	ft_free_local_matrix(core->parser_infos);
	if (get_map()->map_str)
		ft_free_matrix(get_map()->map_str);
	if (get_mlx()->win_ptr)
	{
		mlx_terminate(get_mlx()->win_ptr);
		free(get_mlx());
	}
}
