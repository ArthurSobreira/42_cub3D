/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:21:58 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/29 15:03:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_bool	xy_process(char **map, int i, int j)
{
	if (map[i][j] == '0' || ft_strchr("NSWE", map[i][j]))
	{
		if (i - 1 < 0 || map[i - 1][j] == ' ' || map[i - 1][j] == '\0')
			return (FALSE);
		if (i + 1 >= get_map()->max_y || map[i + 1][j] == ' ' || map[i
			+ 1][j] == '\0')
			return (FALSE);
		if (j - 1 < 0 || map[i][j - 1] == ' ' || map[i][j - 1] == '\0')
			return (FALSE);
		if (j + 1 >= get_map()->max_x || map[i][j + 1] == ' ' || map[i][j
			+ 1] == '\0')
			return (FALSE);
	}
	return (TRUE);
}

static int	permited_map_chars(void)
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
			if (!ft_strchr(" 10NSWE", map[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	closed_map_validation(void)
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
			if (xy_process(map, i, j) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	number_players_validation(void)
{
	char	**map;
	int		i;
	int		j;
	int		player_count;

	map = get_map()->map_str;
	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(PERMITED_PLAYER_CHARS, map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (FALSE);
	return (TRUE);
}

void	map_validation(void)
{
	if (!permited_map_chars())
		ft_error(ERROR_MAP_CHARS);
	if (!closed_map_validation())
		ft_error(ERROR_MAP_CLOSED);
	if (!number_players_validation())
		ft_error(ERROR_MAP_PLAYER);
	if (!player_locale_x_valid())
		ft_error(ERROR_MAP_PLAYER);
}
