/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/07 17:32:21 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TEST_PATH_IMG "./assets/textures/minecraft_diamond.png"
# define MAX_Y 100
# define MAX_X 100
# define MAP_I 6

# define ERROR_INVALID_TEXTURE "\033[0;31mError\nInvalid Texture :(\033[0m\n"
# define ERROR_INVALID_COLOR "\033[0;31mError\nInvalid Color :(\033[0m\n"
# define ERROR_INVALID_MAP_PATH "Error\nInvalid Map Path :(\n"
# define ERROR_INCOMPLETE_MAP "Error\nIncomplete Map File :(\n"
# define PERMITED_MAP_CHARS " 01NSEW"
# define PERMITED_PLAYER_CHARS "NSEW"
# define PARSER_INFOS_LEN 6
# define TEXTURES_LEN 4
# define COLORS_LEN 2
# define WIDTH 1280
# define HEIGHT 720
# define ESC MLX_KEY_ESCAPE
# define UP MLX_KEY_UP
# define DOWN MLX_KEY_DOWN
# define LEFT MLX_KEY_LEFT
# define RIGHT MLX_KEY_RIGHT
# define W MLX_KEY_W
# define S MLX_KEY_S
# define A MLX_KEY_A
# define D MLX_KEY_D
# define Q MLX_KEY_Q
# define P MLX_PRESS
# define RE MLX_REPEAT

typedef struct s_core	t_core;
typedef void			(*t_set_max)(size_t n);

// enum					e_colors
// {
// 	CEILING,
// 	FLOOR
// };

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
	CEILING,
}						t_colors;

typedef struct s_map
{
	char				**map_str;
	t_set_max			set_max_y;
	t_set_max			set_max_x;
	int					max_x;
	int					max_y;
}						t_map;

typedef struct s_cub3d
{
	t_map				*map;
	char				*map_path;
	char				*temp_map_path;
	short				texture_count;
	short				color_count;
	char				*parser_infos[PARSER_INFOS_LEN];
	t_bool				bad_flag;
}						t_cub3d;

typedef struct s_mlx
{
	void				*mlx;
	mlx_image_t			*img[4];
	mlx_texture_t		*texture[4];
	uint32_t			ceil;
	uint32_t			floor;
}						t_mlx;

void					set_max_x(size_t x);
void					set_max_y(size_t y);
t_map					*get_map(void);
t_cub3d					*get_core(void);
void					valid_open_map(void);
void					ft_print_map(void);
void					ft_error(char *msg);
void					constructor_map(void);
t_bool					valid_map_name(char *map_name);
void					map_validation(void);
int						player_locale_y_valid(void);
int						player_locale_x_valid(void);
void					mlx_teste(void);
t_mlx					*get_mlx(void);
void					constructor_gnl(void);
t_cub3d					*get_core(void);
t_map					*get_map(void);

void					set_max_x(size_t x);
void					set_max_y(size_t y);
size_t					maxcol(void);
int						lenfd(void);
void					valid_open_map(void);
void					ft_print_map(void);
void					ft_error(char *msg);
void					constructor_map(void);
// void			fill_with_spaces(void);

void					get_parser_infos(void);
void					parser_line(char **parser_infos, char *line,
							t_bool *is_map_flag);
t_bool					valid_map_name(char *map_name);
t_bool					is_map(char *line);
t_bool					is_texture(char *line);
t_bool					is_color(char *line);
void					normalize_element(char *start);
short					parser_texture(char **s_line, char **parser_infos);
short					parser_color(char **s_line, char **parser_infos);
void					ft_free_local_matrix(char **matrix);
void					clear_all(void);
void					print_parser_infos(char **parser_infos);

#endif
