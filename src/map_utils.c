/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:51:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/01 18:18:33 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_open_map(void)
{
	char	**map;
	int		i;
	int		j;

	map = get_map()->map_str;
	i = MAP_I;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				if ((i - 1 >= 0 && (map[i - 1][j] == ' ' || map[i
							- 1][j] == '\0')) ||
					(i + 1 <= get_map()->max_y && (map[i + 1][j] == ' ' || map[i
								+ 1][j] == '\0')) ||
					(j - 1 >= 0 && map[i][j - 1] == ' ') ||
					(j + 1 <= get_map()->max_x && (map[i][j + 1] == ' '
								|| map[i][j + 1] == '\0')))
					ft_error("Map is not closed");
			j++;
		}
		i++;
	}
}

void	ft_print_map(void)
{
	int		i;
	char	**map;

	map = get_map()->map_str;
	i = MAP_I;
	while (map[i])
	{
		printf("[%s]\n", map[i]);
		i++;
	}
	printf("[%d]\n", i);
	printf("%p\n", map[i]);
}
