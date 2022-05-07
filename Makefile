# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:33:02 by f██████           #+#    #+#              #
#    Updated: 2022/05/07 12:44:04 by f██████          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# minimal color codes
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

OBJS_PS = $(SRCS_PS:.c=.o)
SRCS_PS = $(addprefix $(SRC_DIR)/, \
main.c show_stack.c fill_stack.c indexing_stack.c push_index.c is_sorted.c radix.c sort_2.c sort_3.c sort_4.c sort_5.c \
)

OBJS_PST = $(SRCS_PST:.c=.o)
SRCS_PST = $(addprefix $(SRC_DIR)/tools/, \
cleaning.c init_s_stack.c auto_fill_stack.c sa.c sb.c pa.c pb.c ra.c rb.c rra.c rrb.c ss.c rr.c rrr.c \
)

OBJS_UTEST = $(SRC_UTEST:.c=.o)
SRC_UTEST = $(addprefix ./.utests/, \
main.c test_sa.c test_sb.c test_pa.c test_pb.c test_ra.c test_rb.c test_rra.c test_rrb.c \
)

SRC_DIR	= ./sources
INC_DIR	= ./includes/
CC = gcc
MF = Makefile

ifeq ($(DEBUG), 1)
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
else
FLAGS = -Wall -Wextra -Werror
endif

LIBFT_PATH = ./libft/libft.a
LIBTEST_PATH = ./libft/libtest.a
NAME = push_swap
PS_HEADER_FILE = $(INC_DIR)/push_swap.h
UTEST_NAME = utest
UTEST_HEADER_FILE = $(INC_DIR)/utest.h

all: lib_ft $(NAME)

$(NAME) : $(MF) $(OBJS_PS) $(OBJS_PST) $(LIBFT_PATH)
	@$(CC) $(FLAGS) $(OBJS_PS) $(OBJS_PST) $(LIBFT_PATH) -o $(NAME) 
	@echo "\n${GREEN}> Compilation of push_swap is success 🎉${END}"

./.utests/%.o: ./.utests/%.c $(UTEST_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR) 

%.o: %.c $(PS_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

clean:
	@make clean -C ./libft
	@rm -f $(OBJS_PS)
	@rm -f $(OBJS_UTEST)
	@rm -f $(OBJS_PST)
	@echo "${YELLOW}> All objects files of push_swap have been deleted ❌${END}"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@rm -f $(UTEST_NAME)
	@echo "${YELLOW}> Cleaning of push_swap has been done ❌${END}"

re: fclean all

lib_ft:
	@make -C ./libft DEBUG=$(DEBUG)

lib_test:
	@make test -C ./libft DEBUG=$(DEBUG)

test: lib lib_test $(UTEST_NAME)

$(UTEST_NAME) : $(MF) $(OBJS_PST) $(OBJS_UTEST) $(LIBTEST_PATH) $(LIBFT_PATH)
	@$(CC) $(FLAGS) $(OBJS_PST) $(OBJS_UTEST) $(LIBTEST_PATH) $(LIBFT_PATH) -o $(UTEST_NAME)
	@echo "\n${GREEN}> Compilation of unit tests is success 🎉${END}"

.PHONY:	all bonus clean fclean re lib