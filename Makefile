NAME = get_next_line

HEADER = get_next_line.h

SOURCES = get_next_line_utils.c
		  get_next_line.c

# SOURCES_BONUS = ft_lstnew_bonus.c\
# 				ft_lstadd_front_bonus.c\
# 				ft_lstsize_bonus.c\
# 				ft_lstlast_bonus.c\
# 				ft_lstadd_back_bonus.c\
# 				ft_lstiter_bonus.c\
# 				ft_lstclear_bonus.c\
# 				ft_lstdelone_bonus.c\
# 				ft_lstmap_bonus.c\


OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

# OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -I$(HEADER)

CC = gcc

.PHONY: all clean fclean re 

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(NAME) $@ $?

%.o : %.c $(HEADER) 
	$(CC) $(FLAGS) -c $< -o $@

# bonus :
# 	make OBJECTS="$(OBJECTS_BONUS)" all

clean : $(SOURCES)
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
