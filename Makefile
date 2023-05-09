NAME    = fractol
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -I ./include/fractol.h

LIBFT  	= ./lib/libft/
MLX    := ./lib/MLX/

SRCS 	= $(wildcard ./source/*.c)
OS := $(shell uname -s)

MLX_DIR = lib/MLX/libmlx.a
LIBFLAGS = -I../lib/MLX/libmlx_linux.a -L lib/MLX/ -lmlx -lX11 -lXext -lm -g

OBJS 	=  $(SRCS:.c=.o)
# Color Codes 

SUBM_STATE := $(shell find lib/libft -type f && lib/MLX -type f)

ifeq ($(SUBM_STATE),)
SUBM_FLAG	= submodule
else 
SUBM_FLAG	= 
endif

NC		:= \033[m
B_RED	:= \033[1;31m
RED 	:= \033[0;31m
B_GREEN	:= \033[1;32m
GREEN 	:= \033[0;33m
B_BLUE 	:= \033[1;34m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m
WHCOLOR	:= \033[0;40m

UNAME = $(shell uname -s)

VALGRIND = valgrind -q --leak-check=full --track-origin=yes

all: $(SUBM_FLAG) libft mlx $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

submodule:
	git submodule init
	git submodule update

libft:
	@echo "____!!!$(BLUE)----- Compiling Libft------$(NC)"
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBFT) bonus
	@echo "Compilation of Libft:	\033[1;32mOK\033[m"


mlx:
	@echo "____!!!$(BLUE)----- Compiling mlx ------$(NC)"
	@$(MAKE) -C $(MLX)
	@echo "Creation of MLX:	\033[1;32mOK\033[m"



$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) $(MLX_DIR) $(LIBFT)libft.a -o $(NAME)
	@echo "Compilation of Fractol:	\033[1;32mSUCCESS\033[m"



# Clean up your trashes 

clean:
	@echo "$(GREEN)♻️ ${B_RED} Trashing Away objects..... $(GREEN)♻️ "
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(MLX) clean
	@sleep 0.5
	@echo "	$(B_RED) Cleaning Done $(NC)"

fclean: clean
	@rm -f $(NAME) 
	@echo "$(GREEN)♻️ ${B_RED} Trashing Away all objects and library...."
	
re: fclean all

.phony: all libft clean fclean mlx