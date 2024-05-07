/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:07 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/07 17:33:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg)
{
	t_cub3d	*core;

	core = get_core();
	if (!core->bad_flag)
		ft_putstr_fd(msg, STDERR_FILENO);
	if (get_map()->map_str)
		ft_free_matrix(get_map()->map_str);
	clear_all();
	exit(EXIT_FAILURE);
}
