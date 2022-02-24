NAME	= push_swap
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
LIBFTPATH	= ./

# **************************************************************************
HD	= push_swap.h

# SRC		= pushswap.c
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

# **************************************************************************
all: $(NAME)

$(NAME): $(OBJ) $(HD)
	$(CC) $(CFLAG) -L$(LIBFTPATH) -l$(LIBFTLIB) $(OBJ) -o $(NAME)
# $(CC) $(CFLAG) -std=c90 $(OBJ) -o $(NAME)
# $(CC) $(CFLAG) $(OBJ) -o $(NAME)

# **************************************************************************
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

# **************************************************************************
.PHONY: all clean fclean re

# **************************************************************************

nono: sub_nono
	$(NORM) $(NFLAG) $(SRC)
	$(NORM) $(NFLAG) $(HD)

test:
	echo $(SRC)