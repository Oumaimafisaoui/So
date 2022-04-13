########################################################################
####################### My Makefile ##############################
########################################################################

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror  
# Makefile settings
NAME = so_long
HEADER = so_long.h
LONGSRC = so_long.c get_next_line.c get_next_line_utils.c parsing_checking_map.c utils.c graphics.c check_objects.c put_elements.c put_elements2.c mouvements.c exit_program.c


############## The referencing #############

LONGOBJ = ${LONGSRC:.c=.o}


# UNIX-based OS variables & settings

RM = rm -rf

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(NAME)


$(NAME): $(LONGOBJ) $(HEADER)
	$(CC) $(LONGOBJ) $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Building rule for .o files and its .c


################### Cleaning rules for Unix-based OS ###################

clean:
			$(RM) $(LONGOBJ)

fclean:		clean
			$(RM) so_long

re:			fclean all

.PHONY:		all clean fclean re 