/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:07 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/30 22:56:09 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg)
{
	t_cub3d	*core;

	core = get_core();
	ft_putstr_fd(msg, 2);
	clear_all();
	exit(EXIT_FAILURE);
}
