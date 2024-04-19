/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/19 18:13:26 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ERROR_INVALID_MAP_PATH "Error\nInvalid map path\n"
# define ERROR_INCOMPLETE_MAP "Error\nIncomplete map file\n"
# define PERMITED_MAP_CHARS " 01NSEW"
# define PARSER_INFOS_LEN 6
# define TEXTURES_LEN 5
# define COLORS_LEN 2

typedef struct s_core	t_core;
typedef void			(*t_set_max)(size_t n);

enum	e_colors
{
	CEILING,
	FLOOR
};

typedef struct s_map
{
	char		**map_str;
	t_set_max	set_max_y;
	t_set_max	set_max_x;
	int			max_x;
	int			max_y;
}				t_map;

typedef struct s_cub3d
{
	t_map		*map;
	char		*map_path;
	char		*textures[TEXTURES_LEN];
	uint32_t	colors[COLORS_LEN];
}				t_cub3d;

void					set_max_x(size_t x);
void					set_max_y(size_t y);
t_map					*get_map(void);
size_t					maxcol(void);
int						lenfd(void);
void					valid_open_map(void);
void					ft_print_map(void);
void					ft_error(char *msg);
void					constructor_map(void);

#endif
