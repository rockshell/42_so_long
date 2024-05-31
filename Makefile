# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 15:48:54 by akulikov          #+#    #+#              #
#    Updated: 2024/05/18 15:49:53 by akulikov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX42 = MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

# Find all .c files in src and src/utils
SRC = $(wildcard src/*.c src/utils/*.c)
# Replace src and src/utils with obj to get the .o files
OBJ = $(patsubst src/%.c,obj/%.o,$(patsubst src/utils/%.c,obj/utils/%.o,$(SRC)))

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX42)

# Compile .c files in src to .o files in obj
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# Compile .c files in src/utils to .o files in obj/utils
obj/utils/%.o: src/utils/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -rf obj/*.o obj/utils/*.o obj/utils obj

fclean: clean
	rm -f $(NAME)

re: fclean all
