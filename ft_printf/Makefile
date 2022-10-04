# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 20:02:17 by yotsubo           #+#    #+#              #
#    Updated: 2022/10/04 03:11:41 by yotsubo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT 	= libft.a
LIBFT_PATH = ./libft/
SRCS	= ft_printf.c print_args_utils.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(LIBFT_PATH)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)


clean :
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re : fclean all

.PHONY : all .c.o clean fclean re
