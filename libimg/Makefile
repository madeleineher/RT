# library name
NAME = libimg.a

# dir, path
SRCDIR = srcs
INCDIR = includes
OBJDIR = objs

LIBFT_PATH = ../libft

# compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I ./$(INCDIR) -I $(LIBFT_PATH)/includes
LIBS = -lpthread -L $(LIBFT_PATH) -lft

# srcs
SRCS = for_each_pixel.c\
	handle_error.c\
	buffer2img.c\
	img2buffer.c\
	rgb.c\

SRC_FILTER = gaussian_blur.c\
	sephia.c\
	negative.c\
	gray_scale.c\

SRC_EDGE_DETECT = sobel.c\
	non_maximum_suppression.c\
	max_gradient.c\
	hysteresis_thresholding.c\
	gradient2hex.c\
	canny_edge_detect.c\

# objs
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_FILTER:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_EDGE_DETECT:.c=.o))

# compile objs
HEADERS = ./$(INCDIR)/libimg.h

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/filter/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/edge_detect/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# build
all : $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

$(OBJDIR) :
	mkdir -p $(OBJDIR)

.PHONY : all clean fclean re
