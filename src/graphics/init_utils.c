/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:22:48 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 12:26:58 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	create_rgb(char *r, char *g, char *b)
{
	uint32_t	rgb;

	rgb = 0b00000000;
	rgb |= ft_atoi(r) << 24;
	rgb |= ft_atoi(g) << 16;
	rgb |= ft_atoi(b) << 8;
	rgb |= 0b11111111;
	return (rgb);
}

void	get_color(t_mlx *mlx, t_colors identifier)
{
	char	**splited_color;
	char	*r;
	char	*g;
	char	*b;

	if (identifier == FLOOR)
		splited_color = ft_split(get_core()->parser_infos[FLOOR], ',');
	else
		splited_color = ft_split(get_core()->parser_infos[CEIL], ',');
	if (!splited_color[0] || !splited_color[1] || !splited_color[2])
		ft_error(ERROR_INVALID_COLOR);
	r = splited_color[0];
	g = splited_color[1];
	b = splited_color[2];
	if (identifier == FLOOR)
		mlx->floor_color = create_rgb(r, g, b);
	else
		mlx->ceil_color = create_rgb(r, g, b);
	ft_free_matrix(splited_color);
}

void	set_player_direction(void)
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
