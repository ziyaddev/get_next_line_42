# Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re
# $(NAME) : 
# all : 
# clean : used to remove obj files
# fclean : used to remove bin & obj files
# re : redo make by cleaning everything generated & run "all" rule

# All source files you need to compile your project must be explicitly named in your Makefile.

# Special variables
# $@ : target name
# $< : first prerequisite name
# $^ : prerequisite list
# $? : updated prerequisite name list
# $* : filename without extension

# Program name libft.a
# Turn in files Makefile, libft.h, ft_*.c
# Makefile NAME, all, clean, fclean, re

# You must use the command ar to create your library. Using the libtool command is forbidden.

# gcc -c	compile source files to object files without linking

###################################################
##               MAKEFILE PRINCIPLE              ##
##target: prerequisites                          ##
##        recipe                                 ##
###################################################


###################################################
##                  DIRECTORIES                  ##
###################################################

LIBFTDIR	=	./libft


###################################################
##                   VARIABLES                   ##
###################################################

CFLAGS		=	-Wall -Werror -Wextra -g3  # -D BUFFER_SIZE=n
CC			=	cc

SRC			=	get_next_line.h			\
				get_next_line_utils.c	\
				get_next_line.c

OBJ			=	$(SRC:.c=.o)

NAME		=	gnl.a

###################################################
##                     RULES                     ##
###################################################

all: $(NAME)

# Generate ".a" archive which is used in conjunction with the .h file
# Add libft archive to the current project archive
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

# Compile program and generate a.out
main:
	$(CC) $(CFLAGS) $(SRC)
	./a.out

# Run normimnette
norme:
	norminette ./

# Check leaks with valgrind
valgrnd: main
	valgrind ./a.out

# Preprocess file
preprocessor: $(NAME)
	$(CC) -E ft_printf.c $(NAME) > main_preprocessor

# Clean generated objects
clean:
	$(RM) $(OBJ)

# Clean all generated files
fclean: clean
	$(RM) $(NAME)

# redo compilation
re: fclean all

.PHONY: all norme main valgrnd preprocessor clean fclean re
