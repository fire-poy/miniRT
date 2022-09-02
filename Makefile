NAME=mini_rt
CODEDIRS=. ./vector_lib
INCDIRS=. ./vector_lib/

MLX=./mlx/libmlx.a
MLX_DIR=./mlx
MLX_FLAGS= -framework OpenGL -framework Appkit

CC=gcc
# automatically add the -I onto each include directory
CFLAGS=-Wall -Wextra -Werror $(foreach D,$(INCDIRS),-I$(D)) 
DEBUG_CFLAGS = -g3 -fsanitize=address -fno-omit-frame-pointer

# for-style iteration (foreach) and regular expression completions (wildcard)
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
# regular expression replacement
OBJECTS=$(patsubst %.c,%.o,$(CFILES))

all: $(NAME)

debug: fclean
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: MLX_FLAGS += $(DEBUG_CFLAGS)
debug: $(NAME)

$(NAME): $(OBJECTS) $(MLX)
	$(CC) -o $@ $^ $(MLX_FLAGS)

$(MLX):
	@ $(MAKE) -C $(MLX_DIR) 

# only want the .c file dependency here, thus $< instead of $^.
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)
# 	$(MAKE) -C $(MLX_DIR) clean

fclean:	clean
	rm -f $(NAME)
#	 $(MAKE) -C $(MLX_DIR) clean

re:	fclean all

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

norm:
	norminette -d $(CODEDIRS)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean re diff
