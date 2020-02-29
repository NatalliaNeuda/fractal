NAME = fract_ol

FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wextra -Wall
SOURCES =  *.c
LIBRARIES = libft/libft.a minilibx_macos/libmlx.a


all:
	@echo "Building minilibx.a library..."
	@make -C libft/ all
	@make -C minilibx_macos/
	@echo "\033[35mdone!\033[0m"
	@echo "Creating $(NAME) executable..."
	gcc  $(SOURCES) -o $(NAME) $(LIBRARIES)  $(FRAEMWORKS) 
	@echo "\033[35mdone!\033[0m"

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@echo "\033[45m$(NAME) executable removed!\033[0m"
	@make -C libft/ fclean

re: fclean all