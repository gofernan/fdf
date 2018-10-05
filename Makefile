NAME = fdf
CC = clang
#CFLAGS = -Wall -Wextra -Werror -lm -Iinclude -Lminilibx -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -lm -Iinclude -lmlx -framework OpenGL -framework AppKit
SDIR = srcs
ODIR = objs
IDIR = include
LDIR = libft
_SRCS = main.c \
		get_next_line.c \
		retrieve_data.c \
		errors.c \
		create_map.c \
		img_transform.c \
		transformations.c \
		transformations2.c \
		key_press.c \
		mouse_events.c \
		utils.c \
		draws.c \
		bresenham.c \
		draw_info.c \
		center.c \
		colors.c

SRCS = $(patsubst %, $(SDIR)/%, $(_SRCS))
_OBJS = $(_SRCS:.c=.o)
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))
_DEPS = fdf.h \
		get_next_line.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))
_LIBFT = libft.a
LIBFT = $(patsubst %, $(LDIR)/%, $(_LIBFT))
LIBFT_LIB = -L$(LDIR) -lft
RM = /bin/rm -f
DONE = echo "\033[0;32m[ ✔ ] Done\033[0m"

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c $(LIBFT) $(DEPS)
	$(CC) -c -Wall -Wextra -Werror $< -g -I$(IDIR) -o $@

$(NAME): $(OBJS)
	@echo "\033[1;33mCompiling fdf...\033[0m"
	$(CC) -o $@ -g $^ -I$(IDIR) $(CFLAGS) $(LIBFT_LIB)
	@$(DONE)

$(LIBFT):
	@echo "\033[1;33mCompiling libft...\033[0m"
	$(MAKE) -C $(LDIR)
	@$(DONE)

clean:
	@echo "\033[1;33mCleaning fdf object files...\033[0m"
	$(RM) $(OBJS)
	@$(DONE)
	@echo "\033[1;33mCleaning libft object files...\033[0m"
	$(MAKE) -C $(LDIR) clean
	@$(DONE)

fclean:
	@echo "\033[1;33mCleaning fdf...\033[0m"
	$(RM) $(NAME)
	@$(DONE)
	@echo "\033[1;33mCleaning fdf object files...\033[0m"
	$(RM) $(OBJS)
	@$(DONE)
	@echo "\033[1;33mCleaning libft & libft object files...\033[0m"
	$(MAKE) -C $(LDIR) fclean
	@$(DONE)

re: fclean all

.PHONY: all clean fclean re
