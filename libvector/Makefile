# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 20:04:08 by mhernand          #+#    #+#              #
#    Updated: 2019/09/06 16:06:10 by mhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a

HEADER = libvector.h

CFLAGS = -Wall -Werror -Wextra

SRCS = 	vector_add.c\
		vector_crossproduct.c\
		vector_dotproduct.c\
		vector_fromcoord.c\
		vector_frompoints.c\
		vector_norm.c\
		vector_norm2.c\
		vector_normalise.c\
		vector_scalar.c\
		vector_sub.c

OBJECTS = $(SRCS:.c=.o)

superfast:
	@make -j8 all

all:
	@make $(NAME)

$(NAME):$(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJECTS)
	
fclean: clean 
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all
