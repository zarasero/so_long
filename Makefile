# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zserobia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 18:35:20 by zserobia          #+#    #+#              #
#    Updated: 2024/08/10 18:35:26 by zserobia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Имя исполняемого файла
NAME = so_long

# Исходные файлы
SOURCES = util.c util_2.c move.c main.c graphic.c flood_fill.c \
			check_argum.c clean.c check_argum_2.c \
			move_2.c util_3.c graphic_2.c util_4.c
# Объектные файлы
OBJECTS = $(SOURCES:.c=.o)

# Флаги компилятора
CFLAGS = -Wall -Werror -Wextra -I./minilibx-linux -g3

# Линковочные флаги для MinilibX
LIBS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

# Компилятор
CC = cc

# Основная цель
all: $(NAME)

# Правило для создания исполняемого файла
$(NAME): $(OBJECTS)
	@echo "Linking $@"
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

# Правило для создания объектного файла из исходного
%.o: %.c
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектных файлов
clean:
	@echo "Cleaning object files"
	rm -f $(OBJECTS)

# Очистка всех файлов, включая исполняемый
fclean: clean
	@echo "Cleaning executable"
	rm -f $(NAME)

# Полная пересборка
re: fclean all

# Указание, что цели не являются файлами
.PHONY: all clean fclean re

