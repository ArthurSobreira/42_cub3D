/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:43:55 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/28 12:40:57 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	player_locale_x_valid(void)
{
	char	**map;
	t_map	*map_struct;
	int		i;
	int		j;

	map = get_map()->map_str;
	map_struct = get_map();
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if ((j + 1 < map_struct->max_x && map[i][j + 1] == ' ') || (j
						- 1 >= 0 && map[i][j - 1] == ' ') || j == 0)
					return (FALSE);
				get_player()->pos_y = i * MAP_CUB;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	player_locale_y_valid(void)
{
	char	**map;
	t_map	*map_struct;
	int		i;
	int		j;

	map = get_map()->map_str;
	map_struct = get_map();
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if ((i + 1 < map_struct->max_y && map[i + 1][j] == ' ') || (i
						- 1 >= 0 && map[i - 1][j] == ' ') || i == 0)
					return (FALSE);
				get_player()->pos_x = j * MAP_CUB;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
