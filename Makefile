NAME = minishell

FLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=address

INCLUDE = -I minishell.h

SRCS =	main.c exit.c parsing.c parsing2.c parsing3.c parsing4.c environment.c command.c test.c \
		parsing_utils.c command2.c \
		utils/ft_calloc.c utils/ft_bzero.c utils/ft_memmove.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strcmp.c \
		utils/ft_strlen.c utils/get_next_line_utils.c utils/get_next_line.c utils/ft_split.c utils/ft_strncmp.c \
		utils/ft_substr.c 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
			@rm -rf minishell
			@gcc -o $(NAME) $(INCLUDE) $(OBJS) $(FLAGS)
	
all : $(NAME)

clang : $(OBJS) 
	@clang -o $(NAME) $(INCLUDE) $(OBJS) -g

clean :
		rm -f $(OBJS)
		
fclean : clean
		rm -f $(NAME)
		
re : fclean all