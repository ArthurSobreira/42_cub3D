/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/18 16:38:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define PERMITED_MAP_CHARS " 01NSEW"

typedef struct s_core	t_core;
typedef void			(*t_set_max)(size_t n);

typedef struct s_map
{
	char				**map_str;
	t_set_max			set_max_x;
	t_set_max			set_max_y;
	int					max_x;
	int					max_y;
}						t_map;

void					set_max_x(size_t x);
void					set_max_y(size_t y);
t_map					*get_map(void);
size_t					maxcol(void);
int						lenfd(void);
void					valid_open_map_x(void);
void					valid_open_map_y(void);
void					ft_print_map(void);
void					ft_error(char *msg);
void					constructor_map(void);
void					fill_with_spaces(void);
int						set_max_xy(void);

#endif
