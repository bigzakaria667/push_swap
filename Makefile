# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 17:53:01 by zel-ghab          #+#    #+#              #
#    Updated: 2025/04/11 17:02:25 by zel-ghab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################
## ARGUMENTS

NAME 		= push_swap
CC		= cc
CFLAGS		= -Wall -Wextra -Werror

###########################################
## LIBRAIRIES

PRINTF      = ./functions/ft_printf
LIBFT       = ./functions/libft
IFLAGS      = -I $(PRINTF) -I $(LIBFT)
LDFLAGS     = -L $(PRINTF) -L $(LIBFT) -lft -lftprintf

###########################################
## SOURCES

SRC_FILES	= push_swap.c \
		  sorting/cheapest.c \
		  sorting/instructions.c \
		  management/parsing.c \
		  management/stack.c \
		  management/node.c \
		  management/target.c \
		  management/free.c \
		  management/refresh.c \
		  management/utils.c \
		  movement/ft_swap.c \
		  movement/ft_push.c \
		  movement/ft_rotate.c \
		  movement/ft_rrotate.c \

OBJ_FILES	= $(SRC_FILES:.c=.o)

###########################################
## RULES

all : ${NAME}

${NAME} : ${OBJ_FILES}
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJ_FILES} ${LDFLAGS} -o ${NAME}
	@echo "✅ Successful compilation !"

%.o : %.c
	@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean :
	@rm -f ${OBJ_FILES} movement/*.o management/*.o sorting/*.o
	@make -s clean -C $(LIBFT)
	@make -s clean -C $(PRINTF)
	@echo "🧹 All objects files deleted."

fclean : clean
	@make -s fclean -C $(LIBFT)
	@make -s fclean -C $(PRINTF)
	@rm -rf ${NAME}
	@echo "🧹 Reset!"

re : fclean all

.PHONY: all clean fclean re
