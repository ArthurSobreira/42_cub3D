/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:51:41 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/14 13:40:12 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_open_map(void)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)get_map()->map_str;
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
	char	**map;
	int		i;

	map = get_map()->map_str;
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

t_bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(" 01NSEW", line[i]) == NULL)
			return (FALSE);
		i++;
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
