/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/14 18:42:26 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "defines.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_core	t_core;

enum					e_rgb
{
	RED,
	GREEN,
	BLUE,
	ALPHA
};

typedef enum e_textures
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}						t_textures;

typedef enum e_colors
{
	FLOOR = 4,
	CEIL,
}						t_colors;

typedef struct s_map
{
	char				**map_str;
	int					max_x;
	int					max_y;
}						t_map;

typedef struct s_mlx
{
	mlx_t				*win_ptr;
	mlx_image_t			*img_ptr;
	mlx_texture_t		*textures[4];
	uint32_t			ceil_color;
	uint32_t			floor_color;
}						t_mlx;

typedef struct s_cub3d
{
	char				*map_path;
	char				*temp_map_path;
	short				texture_count;
	short				color_count;
	char				*parser_infos[PARSER_INFOS_LEN];
	t_bool				bad_flag;
}						t_cub3d;

/* Getters Functions */
t_map					*get_map(void);
t_cub3d					*get_core(void);
t_mlx					*get_mlx(void);

/* Parser Functions */
void					get_parser_infos(void);
void					parser_line(char **parser_infos, char *line,
							t_bool *is_map_flag);
short					parser_texture(char **s_line, char **parser_infos);
short					parser_color(char **s_line, char **parser_infos);
void					normalize_element(char *start);
t_bool					valid_map_name(char *map_name);
t_bool					is_map(char *line);
t_bool					is_texture(char *line);
t_bool					is_color(char *line);

/* Graphic Functions */
t_mlx					*init_mlx(void);
void					get_color(t_mlx *mlx, t_colors identifier);
uint32_t				create_rgb(char *r, char *g, char *b);
void					render(void *param);
void					render_background(t_mlx *mlx);

/* Utils Functions */
void					free_local_matrix(char **matrix);
void					clear_mlx(void);
void					clear_all(void);
void					print_parser_infos(char **parser_infos);
void					ft_error(char *msg);

/* Map Functions */
void					ft_print_map(void);
void					map_builder(void);
t_bool					is_map_line(char *line);
int						player_locale_y_valid(void);
int						player_locale_x_valid(void);
void					map_validation(void);
void					map_cpy(void);

/* keyhook */

void					my_keyhook(mlx_key_data_t keydata, void *param);

#endif
