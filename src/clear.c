/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:54:25 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/02 13:12:20 by arsobrei         ###   ########.fr       */
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
}
