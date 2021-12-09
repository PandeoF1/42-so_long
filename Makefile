BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m

SRCS		= so_long.c srcs/ft_init_xpm.c srcs/ft_min.c srcs/ft_sprite.c srcs/ft_get_file.c srcs/ft_split_ln.c srcs/ft_check_file.c srcs/ft_close.c srcs/ft_event.c srcs/ft_init_map.c srcs/ft_strcmp.c srcs/ft_strlcpy.c srcs/ft_strrchr.c srcs/ft_strlen.c srcs/ft_printf.c srcs/ft_putchar.c srcs/ft_putnbr_base.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_putmemory.c
NAME		= so_long
minilibx	= mlbx/libmlx.a
OBJS_DIR	= objs/
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra
MLB_FLAGS	= -I -g -L /usr/X11/lib -Lincludes -L./mlbx -lmlx -Imlx -lXext -lX11 -lz -lm

$(OBJS_DIR)%.o : %.c includes/so_long.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "${BLU}[BUILD]${RST} $@"

$(NAME): $(OBJECTS_PREFIXED) mlx
<<<<<<< HEAD
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(MLB_FLAGS)
=======
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS)
>>>>>>> main
	@echo "\n\033[0;32mso_long compiled !\033[0m\n"

all: $(NAME)

mlx:
	@make -C mlbx

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@make clean -C mlbx
	@rm -f $(NAME)
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean all

.PHONY:		all clean fclean re