/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 13:31:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "MLX42.h"
# include "libft.h"
# include "defines.h"
# include "structs.h"

/* Getters Functions */
t_map		*get_map(void);
t_cub3d		*get_core(void);
t_mlx		*get_mlx(void);
t_player	*get_player(void);
t_math		*get_math(void);

/* Parser Functions */
void		get_parser_infos(void);
void		parser_line(char **parser_infos, char *line, t_bool *is_map_flag);
short		parser_texture(char **s_line, char **parser_infos);
short		parser_color(char **s_line, char **parser_infos);
void		normalize_element(char *start);
t_bool		valid_map_name(char *map_name);
t_bool		is_map(char *line);
t_bool		is_texture(char *line);
t_bool		is_color(char *line);

/* Graphic Functions */
t_mlx		*init_mlx(void);
void		mlx_process(void);
void		get_color(t_mlx *mlx, t_colors identifier);
void		render(void *param);
void		draw_background(t_mlx *mlx);
void		init_bres(t_bres *bres_info, t_point initial_point,
				t_point end_point);
void		plot_pixel(t_mlx *mlx, int x, int y, uint32_t color);
void		plot_thick_pixel(t_point point, int thickness);
void		bresenham(t_point inital_point, t_point end_point, int thickness);
void		bresenham_high(t_point initial_point, t_point end_point,
				int thickness);
void		bresenham_low(t_point initial_point, t_point end_point,
				int thickness);

/* Utils Functions */
void		init_cub(t_cub3d *core, char *argv[]);
void		ft_error(char *msg);
void		free_local_matrix(char **matrix);
void		clear_mlx(void);
void		clear_all(void);

/* Map Functions */
void		map_builder(void);
t_bool		in_map_line(void);
t_bool		in_map_line2(void);
int			player_locale_y_valid(void);
int			player_locale_x_valid(void);
void		map_validation(void);
void		map_cpy(void);

/* Keyhook Functions */
void		my_cursor(double x, double y, void *param);
void		my_keyhook(mlx_key_data_t keydata, void *param);
t_col		wall_collision(t_player	*player, float x, float y);
void		move_right(void);
void		move_left(void);
void		move_w(void);
void		move_a(void);
void		move_s(void);
void		move_d(void);

/* Player Functions */
void		init_player(void);
void		set_player_direction(void);
void		draw_player(int x, int y, uint32_t color);

/* Ray Casting Functions */
void		init_axis(t_math *math, t_player *player, t_axis axis);
void		casting_rays(t_math *math, t_map *map, t_player *player);
void		cat_horizontal_rays(t_math *math, t_map *map, t_player *player);
void		cat_vertical_rays(t_math *math, t_map *map, t_player *player);
void		update_distance(double horizontal_dist, double vertical_dist);
void		trace_ray(t_math *math, t_map *map, t_axis axis);
void		check_wall_collision(t_axis axis);
void		draw_walls(t_math *math, int current_ray);
void		normalize_angle(double *angle);
t_bool		is_nouth_wall(t_math *math);
t_bool		is_south_wall(t_math *math);
t_bool		is_west_wall(t_math *math);
t_bool		is_east_wall(t_math *math);

#endif
