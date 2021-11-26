BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m

SRCS		= main.c srcs/ft_check_file.c srcs/ft_close.c srcs/ft_event.c srcs/ft_init_map.c srcs/ft_strcmp.c srcs/ft_strlcpy.c srcs/ft_strrchr.c srcs/ft_strlen.c
OBJS		= ${SRCS:.c=.o}
GCC			= gcc
GCC_FLAGS	= -Wall -Wextra /usr/X11/include-Werror #-fsanitize=address -fdiagnostics-color 
LIBX		= -I  -g -L /usr/X11/lib -Lincludes \
				-L./minilibx -lmlx -Imlx \
				-lXext -lX11 -lz -lm 
NAME		= so_long

all: mkdir ${NAME}

.c.o:
	@${GCC} -c $< -o objs/${<:.c=.o}
	@echo "${BLU}[BUILD]${RST} ${<:.c=.o}"

${NAME}: ${OBJS}
	${GCC} -o ${NAME} objs/${OBJS} ${LIBX}
	@echo "\n\033[0;32mso_long compiled !\033[0m\n"

mkdir:
	@mkdir -p objs
	@mkdir -p objs/utils
	@echo "${GRN}[MKDIR]${RST} done"

clean:
	@rm -f *.o
	@rm -rf objs
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@rm -f ${NAME}
	@echo "${GRN}[FCLEAN]${RST} done"

run: re
	@echo "${BLU}[RUN]${RST}"
	@./${NAME}

re: fclean all