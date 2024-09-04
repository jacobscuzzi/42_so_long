NAME 			= so_long

CC				= clang

FLAG			= -Wall -Wextra -Werror

LIBFT_PATH		= libft/

LIBFT			= libft/libft.a

LIBFT_HEADER	= libft/includes/

STANDARD_FLAGS 	= -Wall -Werror -Wextra -I./includes

MLX_FLAGS	= -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

REMOVE = rm -f

SRCS_DIR = ./srcs/

MLX_DIR         = ./mlx

FILES			= \
				main.c map_init.c map_read.c \
				map_tools.c map_check.c so_long.c \
				mlx_tools.c mlx_hooks.c graphics.c

SRCS			= $(addprefix $(SRCS_DIR), $(FILES))

all : ${NAME}

${MLX}

${LIBFT}:
		make -C $(LIBFT_PATH)

$(NAME): $(LIBFT)
		@make -C $(MLX_DIR)
		$(CC) $(SRCS) $(LIBFT) ${STANDARD_FLAGS} ${MLX_FLAGS} -o ${NAME}

vallgrind:
		valgrind --leak-check=full ./so_long map/map_standard.bar
clean:
		make clean -C libft
		@make clean -C $(LIBFT_PATH)
		@make clean -C $(MLX_DIR)

fclean:
		${REMOVE} ${NAME} ${NAME_BONUS}
		@make fclean -C $(LIBFT_PATH)
		@make clean -C $(MLX_DIR)
		@echo "${NAME}: ${NAME} were deleted${RESET}"

re:			clean all

rebonus:	fclean ${NAME_BONUS}

run:		${NAME}
			${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:		all clean fclean re rebonus valgrind run run_bonus
