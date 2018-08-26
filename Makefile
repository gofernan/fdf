NAME = fdf
CC = clang
CFLAGS = -Wall -Wextra -Werror -Lminilibx -lmlx -lm -Iminilibx -framework OpenGL -framework AppKit
SDIR = srcs
ODIR = objs
IDIR = include
LDIR = libft
_SRCS = main.c \
		get_next_line.c \
		retrieve_data.c \
		#srcs/fill_map.c
SRCS = $(patsubst %, $(SDIR)/%, $(_SRCS))
_OBJS = $(_SRCS:.c=.o)
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))
_DEPS = fdf.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))
_LIBFT = libft.a
LIBFT = $(patsubst %, $(LDIR)/%, $(_LIBFT))
LIBFT_LIB = -L$(LDIR) -lft
RM = /bin/rm -f
DONE = echo "\033[0;32m[ ✔ ] Done\033[0m"

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c $(LIBFT) $(DEPS)
	$(CC) -c $< -I$(IDIR) -o $@

$(NAME): $(OBJS)
	@echo "\033[1;33mCompiling fdf...\033[0m"
	@$(CC) -o $@ $< $(CFLAGS) $(LIBFT_LIB) -I$(IDIR)
	@$(DONE)

$(LIBFT):
	@echo "\033[1;33mCompiling libft...\033[0m"
	@$(MAKE) -C $(LDIR)
	@$(DONE)

clean:
	@echo "\033[1;33mCleaning fdf object files...\033[0m"
	@$(RM) $(OBJS)
	@$(DONE)
	@echo "\033[1;33mCleaning libft object files...\033[0m"
	@$(MAKE) -C $(LDIR) clean
	@$(DONE)

fclean:
	@echo "\033[1;33mCleaning fdf...\033[0m"
	@$(RM) $(NAME)
	@$(DONE)
	@echo "\033[1;33mCleaning fdf object files...\033[0m"
	@$(RM) $(OBJS)
	@$(DONE)
	@echo "\033[1;33mCleaning libft & libft object files...\033[0m"
	@$(MAKE) -C $(LDIR) fclean
	@$(DONE)

re: fclean all

.PHONY: all clean fclean re
