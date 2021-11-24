BLU		= \033[0;34m
GRN		= \033[0;32m
RED		= \033[0;31m
RST		= \033[0m

SRCS		= main.c utils/ft_strcmp.c utils/ft_strlcpy.c utils/ft_strrchr.c utils/ft_strlen.c
OBJS		= ${addprefix ./, ${SRCS:.c=.o}}
GCC		= gcc 
GCC_FLAGS	= -Wall -Wextra -Werror -fsanitize=address -fdiagnostics-color 
LIBX		= -I /usr/X11/include -g -L /usr/X11/lib -Lincludes \
				-L./minilibx -lmlx -Imlx \
				-lXext -lX11 -lz -lm 
NAME            = so_long

all: ${NAME}

.c.o:
	@${GCC} -c $< -o ${<:.c=.o}
	@echo "${BLU}[BUILD]${RST} ${<:.c=.o}"

${NAME}: ${OBJS} ./getnextline/get_next_line.h ./getnextline/get_next_line.h
	$(MAKE) -C ./getnextline #relink pas
	${GCC} -o ${NAME} ${OBJS} ${LIBX} ./getnextline/get_next_line.a -I./getnextline
	@echo "\n\033[0;32mso_long compiled !\033[0m\n"

clean:
	@rm -f *.o
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@rm -f ${NAME}
	@echo "${GRN}[FCLEAN]${RST} done"

run: re
	@echo "${BLU}[RUN]${RST}"
	@./${NAME}

re: fclean all