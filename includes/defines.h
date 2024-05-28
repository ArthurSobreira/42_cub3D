/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:47:12 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/28 12:13:52 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* Utils Defines */
# define PERMITED_MAP_CHARS " 01NSEW"
# define PERMITED_PLAYER_CHARS "NSEW"
# define PARSER_LEN 6
# define TEXTURES_LEN 4
# define COLORS_LEN 2
# define MAP_CUB 16
# define WINDOW_NAME "cub4D - 42"
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define WIDTH_2 540
# define HEIGHT_2 360
# define MOVE_SPEED 4
# define ROTATE_SPEED 0.02
# define DIRECTION_OFFSET 4
# define DIRECTION_LEN 11

/* Color Defines */
# define COLOR_BORDER 0x3d3d3dff
# define COLOR_WALL 0x616060ff
# define COLOR_FLOOR 0xd1d1d1ff
# define COLOR_PLAYER 0xff0000ff
# define COLOR_DIRECTION 0x2b2b2bff
# define COLOR_RAY 0x919191ff

/* Key Defines */
# define ESC MLX_KEY_ESCAPE
# define UP MLX_KEY_UP
# define DOWN MLX_KEY_DOWN
# define LEFT MLX_KEY_LEFT
# define RIGHT MLX_KEY_RIGHT
# define TAB MLX_KEY_TAB
# define W MLX_KEY_W
# define S MLX_KEY_S
# define A MLX_KEY_A
# define D MLX_KEY_D
# define R MLX_KEY_R
# define Q MLX_KEY_Q
# define P MLX_PRESS
# define RE MLX_REPEAT

/* Math Defines */
# define PI 3.14159265358979323846
# define TWO_PI 6.28318530717958647692
# define PI_OVER_TWO 1.57079632679489661923
# define THREE_PI_OVER_TWO 4.71238898038468985769
# define PLAYER_HALF_FOV 30
# define RAYS_PER_FOV 1080
# define BITSHIFT 4
# define ANG_1 0.0174533
# define PRECISION 0.0001
# define ANG_INCREMENT 0.0556
# define WIDTH_INCREMENT 0.6667
# define HEIGHT_INCREMENT 0.5

/* String Defines */
# define ERROR_MAP_CHARS "\033[0;31mError\nMap Contains Invalid Characters\033[0m\n"
# define ERROR_MAP_CLOSED "\033[0;31mError\nMap is not Closed\033[0m\n"
# define ERROR_MAP_PLAYER "\033[0;31mError\nMap Contains Invalid Player :(\033[0m\n"
# define ERROR_INVALID_TEXTURE "\033[0;31mError\nInvalid Texture :(\033[0m\n"
# define ERROR_INVALID_COLOR "\033[0;31mError\nInvalid Color :(\033[0m\n"
# define ERROR_INVALID_MAP_PATH "\033[0;31mError\nInvalid Map Path :(\033[0m\n"
# define ERROR_INCOMPLETE_MAP "\033[0;31mError\nIncomplete Map File :(\033[0m\n"
# define ERROR_MLX_INIT "\033[0;31mError\nMLX Init Failed :(\033[0m\n"
# define ERROR_TEXTURE_INIT "\033[0;31mError\nTexture Load Failed :(\033[0m\n"
# define ERROR_IMAGE_INIT "\033[0;31mError\nImage Load Failed :(\033[0m\n"
# define SUCCESS_MESSAGE "\033[32;3mCub3D closed, Thank You :)\033[0m\n"
# define CURSOR_PATH "./assets/textures/aim.png"

#endif