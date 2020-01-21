# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 18:09:31 by jebae             #+#    #+#              #
#    Updated: 2019/12/20 04:47:37 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler
CC = gcc

# lib name
NAME = libft.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)

# srcs
SRC_MEMORY = ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_swap.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_memnegate.c\

SRC_STRING = ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_isdigit.c\
	ft_atoi.c\
	ft_atof.c\
	ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_boyer_moore.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_hexatoi.c\
	ft_ishexdigit.c\
	ft_iswhitespace.c\
	ft_to_utf8.c\
	ft_utf8_byte_len.c\

SRC_IO = ft_putchar.c\
	ft_putchar_fd.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	put_color_str.c\

SRC_LST = ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstsort.c\
	ft_lstrev.c\
	ft_sorted_lstadd.c\
	ft_sorted_lstpop.c\
	ft_lstlen.c\
	ft_lstiter_with_arg.c\

SRC_FILE = get_file_content.c\

SRC_QUEUE = queue_init.c\
	queue_push.c\
	queue_pop.c\

SRC_BTREE = btree_create_node.c\
	btree_insert_data.c\
	btree_bfs.c\
	btree_apply_inorder.c\
	btree_apply_postorder.c\
	btree_delone.c\
	btree_del.c\
	btree_search_one.c\
	btree_remove_if.c\
	btree_foreach.c\
	btree_foreach_with_arg.c\

SRC_SET = set_init.c\
	set_add.c\
	set_remove_if.c\
	set_del.c\
	set_foreach.c\
	set_foreach_with_arg.c\
	set_length.c\

SRC_MATH = ft_pow.c\
	ft_bit_reverse.c\
	ft_int_log2.c\
	ft_extract_double.c\
	ft_is_inf.c\
	ft_is_nan.c\
	ft_extract_ldouble.c\
	ft_is_inf_l.c\
	ft_is_nan_l.c\
	ft_min_int.c\
	ft_max_int.c\
	ft_abs_double.c\
	ft_swap_double.c\

SRC_GNL = get_next_line.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_MEMORY:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_STRING:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_IO:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_LST:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_FILE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_QUEUE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_BTREE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_SET:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_MATH:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_GNL:.c=.o))

# compile objs
HEADERS = $(INCDIR)/libft.h\
	$(INCDIR)/get_next_line.h\

$(OBJDIR)/%.o : $(SRCDIR)/memory/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/string/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/io/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/linked_list/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/file/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/queue/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/binary_tree/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/set/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/math/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/get_next_line/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# build
all : $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR) :
	mkdir -p $(OBJDIR)

# commands
clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
