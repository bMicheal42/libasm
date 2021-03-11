# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmicheal <bmicheal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 12:17:44 by bmicheal          #+#    #+#              #
#    Updated: 2021/01/07 13:21:57 by bmicheal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s

OBJS		=		$(SRCS:.s=.o)
NA_FLAG		=		-f macho64
FLAGS		=		-Wall -Wextra -Werror
NAME		=		libasm.a
EXE			=		a.out

%.o:		%.s
			nasm $(NA_FLAG) $<

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME) $(EXE)

re:			fclean $(NAME)

test:		$(NAME)
			gcc $(FLAGS) main.c $(OBJS)
			./a.out

.PHONY:		clean fclean re test