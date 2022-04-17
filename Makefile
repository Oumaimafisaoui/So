########################################################################
####################### My Makefile ##############################
########################################################################

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror  
# Makefile settings
NAME = so_long
BONAME = so_long_bonus
HEADER = so_long.h
LONGSRC = so_long.c get_next_line.c get_next_line_utils.c parsing_checking_map.c utils.c graphics.c \
check_objects.c put_elements.c put_elements2.c mouvements.c exit_program.c init_all.c utils2.c utils3.c \
announce.c
BONSRC = ./bonus/so_long_bonus.c \
		./bonus/get_next_line.c\
		 ./bonus/get_next_line_utils.c ./bonus/parsing_checking_map_bonus.c ./bonus/utils_bonus.c ./bonus/graphics_bonus.c \
./bonus/check_objects_bonus.c ./bonus/put_elements_bonus.c ./bonus/put_elements2_bonus.c ./bonus/mouvements_bonus.c ./bonus/exit_program_bonus.c ./bonus/init_all_bonus.c ./bonus/utils2_bonus.c ./bonus/utils3_bonus.c ./bonus/announce_bonus.c \


############## The referencing #############

LONGOBJ = ${LONGSRC:.c=.o}
BONOBJ = ${BONSRC:.c=.o}

# UNIX-based OS variables & settings

RM = rm -rf

all: $(NAME)
########################################################################
####################### Targets beginning here #########################
########################################################################


$(NAME): $(LONGOBJ) $(HEADER)
	$(CC) $(LONGOBJ) $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus : $(BONAME)

$(BONAME) : $(BONOBJ) $(HEADER)
	$(CC) $(BONSRC) $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(BONAME)


# Building rule for .o files and its .c


################### Cleaning rules for Unix-based OS ###################

clean:
			$(RM) $(LONGOBJ) $(BONOBJ)

fclean:		clean
			$(RM) so_long so_long_bonus

re:			fclean all

.PHONY:		all clean fclean re 