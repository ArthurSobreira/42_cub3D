/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:47:12 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/13 12:55:14 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TEST_PATH_IMG "./assets/textures/minecraft_diamond.png"
# define MAX_Y 100
# define MAX_X 100
# define MAP_I 6

# define ERROR_INVALID_TEXTURE "\033[0;31mError\nInvalid Texture :(\033[0m\n"
# define ERROR_INVALID_COLOR "\033[0;31mError\nInvalid Color :(\033[0m\n"
# define ERROR_INVALID_MAP_PATH "\033[0;31mError\nInvalid Map Path :(\033[0m\n\n"
# define ERROR_INCOMPLETE_MAP "\033[0;31mError\nIncomplete Map File :(\033[0m\n\n"
# define ERROR_MLX_INIT "\033[0;31mError\nMLX Init Failed :(\033[0m\n"
# define ERROR_TEXTURE_INIT "\033[0;31mError\nTexture Load Failed :(\033[0m\n"
# define ERROR_IMAGE_INIT "\033[0;31mError\nImage Load Failed :(\033[0m\n"
# define PERMITED_MAP_CHARS " 01NSEW"
# define PERMITED_PLAYER_CHARS "NSEW"

# define PARSER_INFOS_LEN 6
# define TEXTURES_LEN 4
# define COLORS_LEN 2
# define WINDOW_NAME "cub4D - 42"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

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

#endif