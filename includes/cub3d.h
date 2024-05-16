/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 18:17:58 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "defines.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* Getters Functions */
t_map		*get_map(void);
t_cub3d		*get_core(void);
t_mlx		*get_mlx(void);
t_player	*get_player(void);

/* Parser Functions */
void		get_parser_infos(void);
void		parser_line(char **parser_infos, char *line,
						t_bool *is_map_flag);
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
void		draw_minimap(t_mlx *mlx);
void		draw_player(int x, int y, uint32_t color);
void		draw_direction(t_player *player);
void		draw_square(t_mlx *mlx, int x, int y, uint32_t color);
void		init_bres(t_bres *bres_info, t_point initial_point, \
							t_point end_point);
void		bresenham(t_point inital_point, t_point end_point,\
							int thickness);
void		bresenham_high(t_point initial_point, t_point end_point, \
							int thickness);
void		bresenham_low(t_point initial_point, t_point end_point, \
							int thickness);

/* Utils Functions */
void		free_local_matrix(char **matrix);
void		clear_mlx(void);
void		clear_all(void);
void		print_parser_infos(char **parser_infos);
void		ft_error(char *msg);

/* Map Functions */
void		ft_print_map(void);
void		map_builder(void);
t_bool		is_map_line(char *line);
int			player_locale_y_valid(void);
int			player_locale_x_valid(void);
void		map_validation(void);
void		map_cpy(void);

/* keyhook */

void		my_keyhook(mlx_key_data_t keydata, void *param);

/* Player Functions */
void		init_player(void);
void		set_player_direction(void);
void		draw_player(int x, int y, uint32_t color);
void		move_right(void);
void		move_left(void);

#endif
