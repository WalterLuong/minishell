# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wluong <wluong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/07 09:43:12 by wluong            #+#    #+#              #
#    Updated: 2021/10/20 04:48:19 by wluong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libft.a

SRCS		=		ft_memset.c \
					ft_bzero.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_isstrdigit.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_strcmp.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_strtrim.c \
					ft_split.c \
					ft_new_split.c \
					ft_splitset.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_strjoin.c \
					ft_substr.c \
					ft_memcpy.c \
					ft_is_var_name.c \
					ft_listadd_back.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \

OBJS		=		$(SRCS:.c=.o)

AR			=		ar rc
RM			=		rm -f
CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror

%.o:				%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)

	@echo "\n\033[1;33mCompilation de la libft ⌛\033[0;m\n"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@bash ../.script.sh
	@echo
	@echo "\033[1;32mLIBFT COMPILÉE ✓\n\033[0;m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

