NAME	= cub3D


SRCS_PATH = srcs/
OBJS_PATH = objs/
DEPS_PATH = deps/

SRCS 	= main.c parsing/parsing.c parsing/get_map.c error.c
OBJS 	= $(SRCS:%.c=$(OBJS_PATH)%.o)
DEPS	= $(SRCS:%.c=$(DEPS_PATH)%.d)

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

INCLUDES = -I mlx_linux -I libft -I includes -I usr/include

all: 	${NAME}

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(DEPS_PATH)%.d
		@mkdir -p $(@D)
		${CC} ${CFLAGS} ${INCLUDES} -MMD -MF $(DEPS_PATH)$*.d -c $< -o $@

$(DEPS_PATH)%.d: $(SRCS_PATH)%.c;
		@mkdir -p $(@D)

${NAME}: Makefile ${OBJS}
		@echo "----Compiling lib----\n"
		@make -C libft --no-print-directory
		@echo "\n----Compiling mlx----\n"
		@make -C mlx_linux --no-print-directory
		@echo "\n----Compiling cub3D----\n"
		$(CC) $(CFLAGS) ${OBJS} -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz ${INCLUDES} -o ${NAME}
		@echo "\nCub3d Compiled!\n"

-include $(DEPS)

clean:
		@make clean -C libft --no-print-directory
		@make clean -C mlx_linux --no-print-directory
		@rm -rf ${OBJS_PATH}
		@rm -rf ${DEPS_PATH}

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@echo "Deleting everything!\n"

re:		fclean all

bonus: ${NAME_BONUS}

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus