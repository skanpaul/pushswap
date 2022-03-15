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

SRC 	= 	check_param.c                   manage_arg_doublequote.c        rev_rot_part2.c \
			display_part1.c                 manage_parameter.c              rotate_part1.c \
			display_part2.c                 ps_add_elem_to_bottom.c         rotate_part2.c \
			do_rotation.c                   ps_add_elem_to_top.c            sort_chunk_a.c \
			do_rotation_index.c             ps_del_elem.c                   sort_chunk_b_group.c \
			do_swap.c                       ps_del_list.c                   sort_from_split_to_a.c \
			ft_atoil.c                      ps_get_elem.c                   sort_from_split_to_b.c \
			ft_prinft_error.c               ps_get_last_elem.c              sort_n_elem.c \
			get_chunk_size.c                ps_get_position.c               sort_small_chunk_a.c \
			has_element_part1.c             ps_new_elem.c                   sort_small_chunk_b_to_a.c \
			has_element_part2.c             ps_new_elem_at_bottom.c         sort_sub_chunk_a.c \
			init_push_swap.c                ps_rem_elem_from_bottom.c       sort_sub_chunk_b_group.c \
			is_bigger_than_int.c            ps_rem_elem_from_top.c          sort_sub_rot_chunk_a.c \
			is_chunk_in_order.c             ps_size.c                       split_to_a.c \
			is_countable.c                  push.c                          split_to_b.c \
			is_duplicated.c                 push_swap.c                     swap.c \
			is_in_order.c                   quicksort_vpi.c                 vpi.c \
			is_same_chunk_id_whole_stack.c  rev_rot_part1.c
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
