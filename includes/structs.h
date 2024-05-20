/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:02:29 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/20 15:37:30 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_core	t_core;
typedef struct s_map	t_map;
typedef struct s_wall	t_wall;
typedef struct s_mlx	t_mlx;

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

typedef enum e_axis
{
	VERTICAL,
	HORIZONTAL
}						t_axis;

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
	mlx_texture_t		*cursor_texture;
	mlx_win_cursor_t	*cursor;
	uint32_t			ceil_color;
	uint32_t			floor_color;
}						t_mlx;

typedef struct s_player
{
	double				pos_x;
	double				pos_y;
	double				delta_y;
	double				delta_x;
	double				angle;
	char				direction;
}						t_player;

typedef struct s_math
{
	double				atan;
	double				ntan;
	double				ray_x;
	double				ray_y;
	double				ray_ang;
	double				x_offset;
	double				y_offset;
	double				horz_dist;
	double				horz_x;
	double				horz_y;
	double				vert_dist;
	double				vert_x;
	double				vert_y;
	double				dist;
	t_bool				collision;
}						t_math;

typedef struct s_point
{
	float				coord_x;
	float				coord_y;
	uint32_t			color;
}						t_point;

typedef struct s_bres
{
	float				delta_x;
	float				delta_y;
	int					initial_x;
	int					initial_y;
	int					x_increment;
	int					y_increment;
	int					decision;
}						t_bres;

typedef struct s_cub3d
{
	void 				(*get_parser_infos)(void);
    void 				(*map_builder)(void);
    void 				(*init_player)(void);
    void 				(*mlx_process)(void);
    void 				(*clear_all)(void);
	char				*parser_infos[PARSER_LEN];
	char				*map_path;
	char				*temp_map_path;
	short				texture_count;
	short				color_count;
	t_bool				draw_map;
	t_bool				map_flag;
	t_bool				bad_flag;
}						t_cub3d;

#endif