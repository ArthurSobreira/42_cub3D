NAME = cub3D
LIBFT = libs/libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
MFLAGS = -Iinclude -ldl -lglfw -pthread -lm
MLX = ./libs/MLX42/build/libmlx42.a
MLX_PATH = libs/MLX42
TEMP_PATH = ./temp/

# Paths for libraries
LIB_PATH = ./libs/libft
LIB_NAME = libft.a

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths Definitions
HEADER_PATH = ./includes
BIN_PATH = ./bin/
SOURCES_PATH = ./src/
PARSER_PATH = parser/
MAP_PATH = map/

SOURCES = main.c \
	$(PARSER_PATH)parser_colors.c \
	$(PARSER_PATH)parser_textures.c \
	$(PARSER_PATH)parser_utils.c \
	$(PARSER_PATH)parser.c \
	$(MAP_PATH)map_builder.c \
	$(MAP_PATH)map_utils.c \
	$(MAP_PATH)map_validation_utils.c \
	$(MAP_PATH)map_validation.c \
	clear.c \
	error.c \
	getters.c \
	mlx_tester.c

OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))

all: libft $(MLX) $(BIN_PATH) $(NAME)

$(MLX):
	@mkdir -p $(MLX_PATH)/build
	@cd $(MLX_PATH)/build && cmake ..
	@cmake --build $(MLX_PATH)/build -j4
	@echo $(CYAN)" --------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|  MLX  Was Compiled Successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------"$(COLOR_LIMITER)
	@echo " "


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
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" ----------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| CUB3D executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"----------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(RFLAGS) $(MLX) -L $(LIB_PATH) -lft $(MFLAGS)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(BIN_PATH)$(PARSER_PATH)
	@mkdir -p $(BIN_PATH)$(MAP_PATH)

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@make clean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@echo $(RED)[Removing $(TEMP_PATH)]$(COLOR_LIMITER)
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf ./tests/$(NAME)
	@rm -rf ./libs/MLX42/build
	@rm -rf $(NAME)
	@rm -rf $(TEMP_PATH)

re: fclean
	@make --no-print-directory

make_temp:
	@mkdir -p $(TEMP_PATH)

valgrind: all make_temp 
	@valgrind -s -q --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes \
	--suppressions=./suppresion.supp \
	--log-file=$(TEMP_PATH)valgrind.log \
	./$(NAME) ./assets/maps/map.cub 

.PHONY: all clean fclean re libft make_temp valgrind
