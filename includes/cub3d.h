/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/30 22:50:03 by arsobrei         ###   ########.fr       */
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

# define ERROR_INVALID_MAP_PATH "\033[0;31mError\nInvalid Map Path :(\033[0;31m\n"
# define ERROR_INCOMPLETE_MAP "\033[0;31mError\nIncomplete Map File :(\033[0;31m\n"
# define ERROR_INVALID_TEXTURE "\033[0;31mError\nInvalid Texture :(\033[0;31m\n"
# define PERMITED_MAP_CHARS " 01NSEW"
# define PARSER_INFOS_LEN 7
# define TEXTURES_LEN 4
# define COLORS_LEN 2

typedef struct s_core	t_core;
typedef void			(*t_set_max)(size_t n);

typedef	enum	e_textures
{
	NORTH,
	SOUTH,
	WEST,
	EAST
} 	t_textures;

typedef	enum	e_colors
{
	CEILING = 4,
	FLOOR
}	t_colors;

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
	char		*temp_map_path;
	short		texture_count;
	short		color_count;
	char 		*parser_infos[PARSER_INFOS_LEN];
	uint32_t	colors[COLORS_LEN];
	t_bool		error;
}				t_cub3d;

t_cub3d			*get_core(void);
t_map			*get_map(void);

void			set_max_x(size_t x);
void			set_max_y(size_t y);
size_t			maxcol(void);
int				lenfd(void);
void			valid_open_map(void);
void			ft_print_map(void);
void			ft_error(char *msg);
void			constructor_map(void);
// void			fill_with_spaces(void);

void			get_parser_infos(void);
t_bool			valid_map_name(char *map_name);
t_bool			is_map(char *line);
t_bool			is_texture(char *line);
t_bool			is_color(char *line);
void			normalize_element(char *start);
short			parser_texture(char **s_line, char **parser_infos);

void	ft_free_local_matrix(char **matrix);
void	clear_all(void);
void	print_parser_infos(char **parser_infos);

#endif
