# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:45:56 by tnard             #+#    #+#              #
#    Updated: 2021/11/04 10:53:22 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #
SRCS    = get_next_line.c get_next_line_utils.c
SRCSO = $(SRCSB)
NAME = get_next_line.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror -DBUFFER_SIZE=42

$(OBJS_DIR)%.o : %.c get_next_line.h
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)other
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "\n\033[0;32mgetnextline.a compiled !\033[0m\n"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re