
BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m

SRCS        = main.c srcs/ft_get_file.c srcs/ft_split_ln.c srcs/ft_check_file.c srcs/ft_close.c srcs/ft_event.c srcs/ft_init_map.c srcs/ft_strcmp.c srcs/ft_strlcpy.c srcs/ft_strrchr.c srcs/ft_strlen.c srcs/ft_printf.c srcs/ft_putchar.c srcs/ft_putnbr_base.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_putmemory.c
NAME		= so_long
minilibx	= minilibx/libmlx.a
OBJS_DIR	= objs/
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -I -g -L /usr/X11/lib -Lincludes -L./minilibx -lmlx -Imlx -lXext -lX11 -lz -lm 

$(OBJS_DIR)%.o : %.c includes/so_long.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) -c $< -o $@
	@echo "${BLU}[BUILD]${RST} $@"

$(NAME): $(minilibx) $(OBJECTS_PREFIXED)
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS)
	@echo "\n\033[0;32mso_long compiled !\033[0m\n"

all: $(NAME)

$(minilibx):
	@$(MAKE) -C minilibx

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@$(MAKE) clean -C minilibx
	@rm -f $(NAME)
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean all

.PHONY:		all clean fclean re