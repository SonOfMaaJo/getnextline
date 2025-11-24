CC = cc
FLAGS = -Wall -Wextra -Werror -I -D BUFFER_SIZE=42
SRCS = srcs
SRCS_FILE = $(shell find $(SRCS) -name "*.c")
INCLUDES = includes
NAME = prog

all : $(NAME)

$(NAME) : $(SRCS_FILE)
	$(CC) $(FLAGS) $(INCLUDES) $^ -o $@

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY : all clean fclean re

	
	
