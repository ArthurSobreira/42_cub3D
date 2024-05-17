/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:24:01 by arsobrei          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/05/17 18:40:40 by phenriq2         ###   ########.fr       */
=======
/*   Updated: 2024/05/17 12:10:40 by arsobrei         ###   ########.fr       */
>>>>>>> 19fad299a38b858d8bba80e05fa1b5132a954222
=======
/*   Updated: 2024/05/17 17:48:53 by arsobrei         ###   ########.fr       */
>>>>>>> 516b80a95388c083619f532ad182e77f686b1664
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

typedef struct s_map
{
	char				**map_str;
	t_wall				**map;
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

typedef struct s_point
{
	float				coord_x;
	float				coord_y;
	uint32_t			color;
}						t_point;

/* 	@brief: Structs for calculations

	@r: ray
	@mx: map x
	@my: map y
	@mp: map position
	@dof: direction of field
	@atan: angle tangent
	@rx: ray x
	@ry: ray y
	@ra: ray angle
	@xo: x offset
	@yo: y offset */

typedef struct s_math
{
	int					dof;
	float				atan;
	float				ntan;
	float				rx;
	float				ry;
	float				rvx;
	float				rvy;
	float				ra;
	float				xo;
	float				yo;
	float				dist;
}						t_math;

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
	char				*parser_infos[PARSER_INFOS_LEN];
	char				*map_path;
	char				*temp_map_path;
	short				texture_count;
	short				color_count;
	t_bool				map_flag;
	t_bool				bad_flag;
}						t_cub3d;

#endif