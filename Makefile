# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 13:38:08 by jmoucach          #+#    #+#              #
#    Updated: 2019/01/21 14:37:52 by jmoucach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRC= ./main.c\
	 ./init.c\
	 ./info.c\
	 ./map.c\
	 ./draw.c\
	 ./hook_deal.c\
	 ./image.c
OBJ= $(SRC:.c=.o)
LIB= -L minilibx_macos -lmlx\
	 -L libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIB) -framework OpenGL -framework AppKit


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
