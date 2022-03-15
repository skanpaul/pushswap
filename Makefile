NAME	= push_swap
PROJECTPATH = ./
# **************************************************************************
CC		= gcc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f
AR 		= ar -rcs
NORM	= norminette
NFLAG	= -R CheckForbiddenSourceHeader
# **************************************************************************
LIBFTNAME	= libft.a
LIBFTHD		= libft.h
LIBFTLIB	= ft
LIBFTPATH	= ./libft/

# **************************************************************************
HD	= push_swap.h

SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

# **************************************************************************
all: $(NAME) 

$(NAME): $(OBJ) sub_all
	cp ${LIBFTPATH}${LIBFTNAME} ${PROJECTPATH}
	$(CC) $(CFLAG) -L$(LIBFTPATH) -l$(LIBFTLIB) $(OBJ) -o $(NAME)

# **************************************************************************
clean: sub_clean
	$(RM) $(OBJ)
	
fclean: clean sub_fclean
	$(RM) $(NAME)
	$(RM) $(LIBFTNAME)

re: fclean all sub_re

# **************************************************************************
.PHONY: all clean fclean re

# **************************************************************************
sub_all:
	${MAKE} all -C ${LIBFTPATH}

sub_clean:
	${MAKE} clean -C ${LIBFTPATH}

sub_fclean:
	${MAKE} fclean -C ${LIBFTPATH}

sub_re:
	${MAKE} re -C ${LIBFTPATH}
