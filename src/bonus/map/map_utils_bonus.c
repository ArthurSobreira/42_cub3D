/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:51:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/28 12:40:46 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_bool	in_map_line(void)
{
	static int	map_started = 0;

	if (map_started < 6)
	{
		map_started++;
		return (FALSE);
	}
	return (TRUE);
}

t_bool	in_map_line2(void)
{
	static int	map_started = 0;

	if (map_started < 6)
	{
		map_started++;
		return (FALSE);
	}
	return (TRUE);
}

void	map_cpy(void)
{
	char	**map;
	char	**map_cpy;
	int		i;

	map = get_map()->map_str;
	map_cpy = ft_calloc(get_map()->max_y + 1, sizeof(char *));
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_calloc(get_map()->max_x + 1, sizeof(char));
		ft_memset(map_cpy[i], '1', get_map()->max_x);
		map_cpy[i][get_map()->max_x] = '\0';
		ft_memcpy(map_cpy[i], map[i], ft_strlen(map[i]));
		map_cpy[i] = ft_replace(map_cpy[i], " ", "1");
		i++;
	}
	ft_free_matrix(map);
	get_map()->map_str = map_cpy;
}
