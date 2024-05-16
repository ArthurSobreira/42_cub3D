/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 10:46:22 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_direction(void)
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
				get_player()->direction = map[i][j];
			j++;
		}
		i++;
	}
}

static void	set_degrees(void)
{
	if (get_player()->direction == 'N')
		get_player()->degree = PI_270;
	else if (get_player()->direction == 'S')
		get_player()->degree = HALF_PI;
	else if (get_player()->direction == 'W')
		get_player()->degree = TWO_PI;
	else if (get_player()->direction == 'E')
		get_player()->degree = 0;
}

void	start_player(void)
{
	set_direction();
	set_degrees();
	get_player()->dx = cos(get_player()->degree);
	get_player()->dy = sin(get_player()->degree);
}
