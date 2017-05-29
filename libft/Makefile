#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 19:37:51 by dzui              #+#    #+#              #
#    Updated: 2016/11/25 19:37:58 by dzui             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
		ft_strtrim.c \
		ft_strsub.c \
		ft_strsplit.c \
		ft_strnew.c \
		ft_strequ.c \
		ft_strmapi.c \
		ft_strmap.c \
		ft_strjoin.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strnequ.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_memdel.c \
		ft_memalloc.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_isspace.c \
		ft_islower.c \
		ft_isupper.c \
		ft_capitalize.c \
		ft_isany.c

OBJ = $(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) -I libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
