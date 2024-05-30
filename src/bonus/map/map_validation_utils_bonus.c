/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:43:55 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/29 15:03:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	player_locale_x_valid(void)
{
	char	**map;
	int		i;
	int		j;

	map = get_map()->map_str;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (!xy_process(map, i, j))
					return (FALSE);
				get_player()->pos_y = i * MAP_CUB;
				get_player()->pos_x = j * MAP_CUB;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
