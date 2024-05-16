/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:21:58 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 12:32:55 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (!ft_strchr(PERMITED_MAP_CHARS, map[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	closed_map_x_validation(void)
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
			if (map[i][j] == '0')
				if ((j + 1 < map_struct->max_x && map[i][j + 1] == ' ') || (j
						- 1 >= 0 && map[i][j - 1] == ' ') || j == 0)
					return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	closed_map_y_validation(void)
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
			if (map[i][j] == '0')
				if ((i + 1 < map_struct->max_y - 1 && map[i + 1][j] == ' ')
					|| (i - 1 >= 0 && map[i - 1][j] == ' ') || i == 0)
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
	t_map	*map_struct;
	int		i;
	int		j;
	int		player_count;

	map = get_map()->map_str;
	map_struct = get_map();
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
	if (!closed_map_x_validation())
		ft_error(ERROR_MAP_CLOSED_X);
	if (!closed_map_y_validation())
		ft_error(ERROR_MAP_CLOSED_Y);
	if (!number_players_validation())
		ft_error(ERROR_MAP_PLAYER);
	if (!player_locale_x_valid())
		ft_error(ERROR_MAP_PLAYER);
	if (!player_locale_y_valid())
		ft_error(ERROR_MAP_PLAYER);
}
