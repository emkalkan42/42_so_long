# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 15:34:18 by emkalkan          #+#    #+#              #
#    Updated: 2024/02/06 22:25:53 by emkalkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Imlx -g -fPIE

MLXFLAGS=	-L ./libs/libx -lmlx -lXext -lX11

LIBS	=	 ./libs/libft/libft.a

SRCS	=	 src/typecheck.c src/so_long.c src/wallcheck.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C  ./libs/libx
			make -C  ./libs/libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

clean:
			make clean -C  ./libs/libx
			make clean -C  ./libs/libft
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

