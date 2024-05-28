NAME = cub3D
NAME_BONUS = cub3D_bonus
CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math \
	-fno-stack-protector
MFLAGS = -Iinclude -ldl -lglfw -pthread -lm 
TEMP_PATH = ./temp/

# Paths for libraries
LIB_PATH = ./libs/libft/
LIB_NAME = libft.a
MLX_PATH = ./libs/MLX42/build/
MLX_HEADERS = ./libs/MLX42/include/MLX42/
MLX_NAME = libmlx42.a

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths Definitions
BIN_PATH = ./bin/
SOURCES_PATH = ./src/
MANDATORY_PATH = mandatory/
BONUS_PATH = bonus/
HEADER_PATH = ./includes/
GRAPHICS_PATH = graphics/
HOOKS_PATH = hooks/
MAP_PATH = map/
MATH_PATH = math/
PARSER_PATH = parser/
UTILS_PATH = utils/

SOURCES = main.c \
	$(GRAPHICS_PATH)draw_line.c \
	$(GRAPHICS_PATH)init_graphics.c \
	$(GRAPHICS_PATH)init_utils.c \
	$(GRAPHICS_PATH)pixel_utils.c \
	$(GRAPHICS_PATH)render.c \
	$(HOOKS_PATH)hooks_movement.c \
	$(HOOKS_PATH)hooks_rotation.c \
	$(HOOKS_PATH)keyhooks.c \
	$(MAP_PATH)map_builder.c \
	$(MAP_PATH)map_utils.c \
	$(MAP_PATH)map_validation_utils.c \
	$(MAP_PATH)map_validation.c \
	$(MATH_PATH)draw_walls.c \
	$(MATH_PATH)ray_casting.c \
	$(MATH_PATH)ray_utils.c \
	$(MATH_PATH)wall_utils.c \
	$(PARSER_PATH)parser_colors.c \
	$(PARSER_PATH)parser_textures.c \
	$(PARSER_PATH)parser_utils.c \
	$(PARSER_PATH)parser.c \
	$(UTILS_PATH)clear.c \
	$(UTILS_PATH)getters.c \
	$(UTILS_PATH)utils.c \

BONUS_SOURCES = main_bonus.c \
	$(GRAPHICS_PATH)draw_line_bonus.c \
	$(GRAPHICS_PATH)init_graphics_bonus.c \
	$(GRAPHICS_PATH)init_utils_bonus.c \
	$(GRAPHICS_PATH)pixel_utils_bonus.c \
	$(GRAPHICS_PATH)render_utils_bonus.c \
	$(GRAPHICS_PATH)render_bonus.c \
	$(HOOKS_PATH)cursorhooks_bonus.c \
	$(HOOKS_PATH)hooks_movement_bonus.c \
	$(HOOKS_PATH)hooks_rotation_bonus.c \
	$(HOOKS_PATH)keyhooks_bonus.c \
	$(MAP_PATH)map_builder_bonus.c \
	$(MAP_PATH)map_utils_bonus.c \
	$(MAP_PATH)map_validation_utils_bonus.c \
	$(MAP_PATH)map_validation_bonus.c \
	$(MATH_PATH)draw_walls_bonus.c \
	$(MATH_PATH)ray_casting_bonus.c \
	$(MATH_PATH)ray_utils_bonus.c \
	$(MATH_PATH)wall_utils_bonus.c \
	$(PARSER_PATH)parser_colors_bonus.c \
	$(PARSER_PATH)parser_textures_bonus.c \
	$(PARSER_PATH)parser_utils_bonus.c \
	$(PARSER_PATH)parser_bonus.c \
	$(UTILS_PATH)clear_bonus.c \
	$(UTILS_PATH)getters_bonus.c \
	$(UTILS_PATH)utils_bonus.c \

OBJECTS = $(addprefix $(BIN_PATH), \
	$(addprefix $(MANDATORY_PATH), $(SOURCES:%.c=%.o)))

BONUS_OBJECTS = $(addprefix $(BIN_PATH), \
	$(addprefix $(BONUS_PATH), $(BONUS_SOURCES:%.c=%.o)))

BIN_DIRS = $(MANDATORY_PATH) $(BONUS_PATH) \
	$(MANDATORY_PATH)$(GRAPHICS_PATH) \
	$(MANDATORY_PATH)$(HOOKS_PATH) \
	$(MANDATORY_PATH)$(MAP_PATH) \
	$(MANDATORY_PATH)$(MATH_PATH) \
	$(MANDATORY_PATH)$(PARSER_PATH) \
	$(MANDATORY_PATH)$(UTILS_PATH) \
	$(BONUS_PATH)$(GRAPHICS_PATH) \
	$(BONUS_PATH)$(HOOKS_PATH) \
	$(BONUS_PATH)$(MAP_PATH) \
	$(BONUS_PATH)$(MATH_PATH) \
	$(BONUS_PATH)$(PARSER_PATH) \
	$(BONUS_PATH)$(UTILS_PATH)

all: libft mlx $(BIN_PATH) $(NAME)

mlx:
ifeq ($(wildcard $(MLX_PATH)/$(MLX_NAME)),)
	@mkdir -p $(MLX_PATH)
	@cd $(MLX_PATH) && cmake ..
	@cmake --build $(MLX_PATH) -j4
	@echo $(CYAN)" --------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|  MLX  Was Compiled Successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------"$(COLOR_LIMITER)
	@echo " "
endif

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@make -C $(LIB_PATH) --no-print-directory
	@make get_next_line -C $(LIB_PATH) --no-print-directory
	@make ft_printf -C $(LIB_PATH) --no-print-directory
	@echo $(CYAN)" --------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|  LIBFT  Was Compiled Successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------"$(COLOR_LIMITER)
	@echo " "
endif

$(BIN_PATH)%.o: $(SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH) -I $(MLX_HEADERS)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" ----------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| CUB3D executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"----------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(RFLAGS) $(MLX_PATH)$(MLX_NAME) \
		-L $(LIB_PATH) -lft $(MFLAGS)
	@echo " "

bonus: libft mlx $(BIN_PATH) $(NAME_BONUS)

$(BIN_PATH)%.o: $(SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH) -I $(MLX_HEADERS)
	@echo " "

$(NAME_BONUS): $(BONUS_OBJECTS)
	@echo $(CYAN)" ----------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| CUB3D_BONUS executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"----------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJECTS) $(RFLAGS) $(MLX_PATH)$(MLX_NAME) \
		-L $(LIB_PATH) -lft $(MFLAGS)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(foreach dir,$(BIN_DIRS),$(BIN_PATH)$(dir))

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@make clean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@echo $(RED)[Removing $(NAME_BONUS) executable]$(COLOR_LIMITER)
	@echo $(RED)[Removing $(TEMP_PATH)]$(COLOR_LIMITER)
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(MLX_PATH)
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(TEMP_PATH)

re: fclean
	@make --no-print-directory

re_bonus: fclean
	@make bonus --no-print-directory

make_temp:
	@mkdir -p $(TEMP_PATH)

valgrind: all make_temp 
	@valgrind -s --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all \
	--track-origins=yes \
	--suppressions=./suppresion.supp \
	--log-file=$(TEMP_PATH)valgrind.log \
	./$(NAME) ./assets/maps/sage.cub 

.PHONY: all clean fclean re libft make_temp valgrind
