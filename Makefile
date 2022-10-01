NAME=miniRT

NORM=./libft ./vector_lib ./parser ./objects ./render ./src
INC=-I ./vector_lib -I./parser 

SRC=./objects/camera.c\
	./objects/cyl_caps.c\
	./objects/cyl.c\
	./objects/plan.c\
	./objects/sphere.c\
	./parser/check_camera.c\
	./parser/check_cylindre.c\
	./parser/check_lumiere_amb.c\
	./parser/check_lumiere.c\
	./parser/check_plane.c\
	./parser/check_scene.c\
	./parser/check_sphere.c\
	./parser/get_fix_obj.c\
	./parser/get_var_obj.c\
	./parser/get_scene.c\
	./parser/pars_utils.c\
	./parser/parser.c\
	./parser/print_debug.c\
	./render/get_closest.c\
	./render/light.c\
	./render/render.c\
	./src/key_hook.c\
	./src/main.c\
	./src/utils.c\
	./vector_lib/operator.c\
	./vector_lib/utils.c\
	./vector_lib/vector_ope.c\
	./vector_lib/x_operator.c

LIBFT=./libft/libft.a
LIBFT_DIR=./libft

MLX=./mlx/libmlx.a
MLX_DIR=./mlx
MLX_FLAGS= -framework OpenGL -framework Appkit

CC=gcc

CFLAGS=-Wall -Wextra -Werror $(INC) 
DEBUG_CFLAGS = -g3 -fsanitize=address -fno-omit-frame-pointer

# regular expression replacement
OBJECTS=$(patsubst %.c,%.o,$(SRC))

all: $(NAME)

# debug: fclean
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: MLX_FLAGS += $(DEBUG_CFLAGS)
debug: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	$(CC) -o $@ $^ $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(MLX):
	@ $(MAKE) -C $(MLX_DIR) 

# only want the .c file dependency here, thus $< instead of $^.
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

norm:
	norminette -d $(NORM)

run: all
	./$(NAME)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean re diff debug norm run
