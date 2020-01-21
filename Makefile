NAME = rt

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft
LIBVECTOR_PATH = ./libvector
LIBIMG_PATH = ./libimg
PARSER_PATH = ./parser
SDL_PATH = ./SDL2

INC = -I includes\
	-I $(LIBFT_PATH)/includes\
	-I $(LIBVECTOR_PATH)\
	-I $(PARSER_PATH)/includes\
	-I $(LIBIMG_PATH)/includes\
	-I $(SDL_PATH)/include\

LIB = -L $(LIBFT_PATH) -lft\
	-L $(PARSER_PATH) -lparse\
	-L $(LIBVECTOR_PATH) -lvector\
	-L $(LIBIMG_PATH) -limg\
	-L $(SDL_PATH)/lib -lSDL2\

CC = gcc

SRC_DIR = srcs

OBJ_DIR = objects

SRC_CEL_SHADING = cel_shading.c\
	face.c\

SRC_INTERSECT_NORMAL = box.c\
	pyramid.c\
	rectangle.c\
	ring.c\
	triangle.c\
	sphere.c\
	cone.c\
	cylinder.c\
	ellipsoid.c\
	paraboloid.c\
	plane.c\
	common.c\

SRC_LIGHT = distant_light.c\
	spherical_light.c\

SRC_SET_LIGHT = distant_light.c\
	spherical_light.c\

SRC_RENDER = anti_aliasing.c\
	multithread.c\
	render.c\

SRC_ROTATE = box.c\
	q_rotate.c\
	quaternion_operator.c\
	rotate_object.c\
	sphere.c\
	rectangle.c\
	cone.c\
	cylinder.c\
	plane.c\
	pyramid.c\
	ring.c\
	triangle.c\
	paraboloid.c\
	ellipsoid.c\

SRC_SET_OBJECT = box.c\
	common.c\
	cone.c\
	cylinder.c\
	plane.c\
	pyramid.c\
	rectangle.c\
	ring.c\
	sphere.c\
	triangle.c\
	paraboloid.c\
	ellipsoid.c\

SRC_SHADING = diffuse_specular.c\
	reflection.c\
	refraction.c\
	shading.c\
	shadow.c\

SRC_TEXEL = bump_mapping.c\
	texel.c\
	texture_mapping.c\
	set_texels.c\

SRC_TRACE = ray.c\
	trace.c\
	trace_record.c\

SRC_TRANSLATE = translate_object.c\
	box.c\
	cone.c\
	cylinder.c\
	plane.c\
	pyramid.c\
	rectangle.c\
	ring.c\
	sphere.c\
	triangle.c\
	paraboloid.c\
	ellipsoid.c\

SRC_UV_MAPPING = cone.c\
	cylinder.c\
	rectangle.c\
	sphere.c\

SRC_SETTING = env.c\
	event_loop.c\
	key_input.c\
	camera.c\
	ambient.c\
	ray_grid_props.c\

SRCS = color_op.c\
	mat3_op.c\
	handle_fail.c\
	buffer2img.c\
	main.c\

# objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/intersect_normal_, $(SRC_INTERSECT_NORMAL:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_LIGHT:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/set_, $(SRC_SET_LIGHT:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_RENDER:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/rot_, $(SRC_ROTATE:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/set_, $(SRC_SET_OBJECT:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_SHADING:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_TEXEL:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_TRACE:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/transl_, $(SRC_TRANSLATE:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/uv_, $(SRC_UV_MAPPING:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_CEL_SHADING:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_SETTING:.c=.o))

# compile objs
HEADERS = ./includes/raycast.h\
	./includes/rt.h\
	./includes/rt_struct.h\
	./$(LIBFT_PATH)/includes/libft.h\
	./$(LIBVECTOR_PATH)/libvector.h\
	./$(PARSER_PATH)/includes/parse.h\
	./$(LIBIMG_PATH)/includes/libimg.h\

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/intersect_normal_%.o : $(SRC_DIR)/intersect_normal/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/light/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/set_%.o : $(SRC_DIR)/set_light/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/render/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/set_%.o : $(SRC_DIR)/render/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/rot_%.o : $(SRC_DIR)/rotate/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/set_%.o : $(SRC_DIR)/set_object/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/shading/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/texel/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/trace/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/transl_%.o : $(SRC_DIR)/translate/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/uv_%.o : $(SRC_DIR)/uv_mapping/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/cel_shading/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/setting/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# command
ROOT_DIR = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
CONTENTS = contents
OUTPUT_DIR = outputs
SDL = $(ROOT_DIR)/SDL2 $(ROOT_DIR)/SDL2-2.0.10
NODE_MODULES = interface/node_modules

all: $(NAME)

$(NAME) : deps $(OBJ_DIR) $(OBJS) $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJS) -o $(NAME)

$(OBJ_DIR) : 
	mkdir -p $@

deps : $(SDL) $(NODE_MODULES) $(CONTENTS)
	make -C $(LIBFT_PATH) all
	make -C $(LIBVECTOR_PATH) all
	make -C $(LIBIMG_PATH) all
	make -C $(PARSER_PATH) all

$(SDL) :
	if [ ! -d ./SDL2-2.0.10 ]; \
	then tar -xvzf libsdl;\
	fi;
	if [ ! -d ./SDL2 ]; \
	then cd SDL2-2.0.10 ; ./configure --prefix $(ROOT_DIR)/SDL2 ;\
	make -j8 ; make install; fi;

$(NODE_MODULES) :
	cd interface && npm install

$(CONTENTS) :
	tar -xvzf contents.tar
	mkdir -p ./interface/public/textures
	cp -R contents/* ./interface/public/textures/

$(OUTPUT_DIR) :
	mkdir -p $@

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(LIBVECTOR_PATH) clean
	make -C $(LIBIMG_PATH) clean
	make -C $(PARSER_PATH) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NODE_MODULES)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(LIBVECTOR_PATH) fclean
	make -C $(LIBIMG_PATH) fclean
	make -C $(PARSER_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
