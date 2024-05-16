/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:47:12 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 18:57:37 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TEST_PATH_IMG "./assets/textures/minecraft_diamond.png"
# define MAX_Y 100
# define MAX_X 100
# define MAP_I 6

/* Error Defines */
# define ERROR_MAP_CHARS "\033[0;31mError\nMap Contains Invalid Characters :(\033[0m\n"
# define ERROR_MAP_CLOSED_X "\033[0;31mError\nMap is not Closed in X Axis :(\033[0m\n"
# define ERROR_MAP_CLOSED_Y "\033[0;31mError\nMap is not Closed in Y Axis :(\033[0m\n"
# define ERROR_MAP_PLAYER "\033[0;31mError\nMap Contains Invalid Player :(\033[0m\n"
# define ERROR_INVALID_TEXTURE "\033[0;31mError\nInvalid Texture :(\033[0m\n"
# define ERROR_INVALID_COLOR "\033[0;31mError\nInvalid Color :(\033[0m\n"
# define ERROR_INVALID_MAP_PATH "\033[0;31mError\nInvalid Map Path :(\033[0m\n\n"
# define ERROR_INCOMPLETE_MAP "\033[0;31mError\nIncomplete Map File :(\033[0m\n\n"
# define ERROR_MLX_INIT "\033[0;31mError\nMLX Init Failed :(\033[0m\n"
# define ERROR_TEXTURE_INIT "\033[0;31mError\nTexture Load Failed :(\033[0m\n"
# define ERROR_IMAGE_INIT "\033[0;31mError\nImage Load Failed :(\033[0m\n"
# define CURSOR_PATH "./assets/textures/aim2.png"

/* Utils Defines */
# define PERMITED_MAP_CHARS " 01NSEW"
# define PERMITED_PLAYER_CHARS "NSEW"
# define PARSER_INFOS_LEN 6
# define TEXTURES_LEN 4
# define COLORS_LEN 2
# define MAP_CUB 32
# define WINDOW_NAME "cub4D - 42"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MOVE_SPEED 4

/* Color Defines */
# define COLOR_BORDER 0x3d3d3dff
# define COLOR_WALL 0x616060ff
# define COLOR_FLOOR 0xd1d1d1ff
# define COLOR_PLAYER 0xff0000ff

/* Key Defines */
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

/* Math Defines */
# define PI 3.14159265358979323846
# define TWO_PI 6.28318530717958647692
# define PI_OVER_TWO 1.57079632679489661923
# define THREE_PI_OVER_TWO 4.71238898038468985769

#endif