# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 12:36:18 by amansour          #+#    #+#              #
#    Updated: 2017/09/21 18:53:50 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
SRCLIBPATH = ./srclib
SRCPATH = ./src
OBJLIBPATH = ./objlib
OBJPATH = ./obj

SRCLIB_NAME = ft_isdigit.c ft_strlen.c ft_wstrlen.c\
	ft_putchar.c ft_strjoin.c\
	ft_strnew.c ft_putstr.c\
	ft_strcpy.c ft_strdup.c\
	ft_bzero.c ft_memalloc.c\
	ft_memset.c ft_upcase.c\
	join.c convert_unicode.c\
	ft_strcat.c ft_strcut.c ft_strncpy.c\


SRC_NAME = ft_printf.c no_printed_conv.c test.c util.c ft_itoa_base.c\
		printed_conv.c display.c conversion.c\

INCLUDS = includes/ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(SRCLIB_NAME:.c=.o)
SRC = $(addprefix $(SRCPATH)/, $(SRC_NAME))
LIB = $(addprefix $(SRCLIBPATH)/, $(SRCLIB_NAME))
OBJ = $(addprefix $(OBJPATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIBPATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME) : $(OBJ) $(OBJLIB)
	ar rc $(NAME) $(OBJ) $(OBJLIB)
	ranlib $(NAME)
	@echo "__, ___      __, __, _ _, _ ___ __,"
	@echo "|_   |       |_) |_) | |\ |  |  |_ "
	@echo "|    |       |   | \ | | \|  |  |  "
	@echo "~    ~  ~~~~ ~   ~ ~ ~ ~  ~  ~  ~  "
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@mkdir $(OBJPATH) 2> /dev/null || true
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDS)

$(OBJLIBPATH)/%.o: $(SRCLIBPATH)/%.c
	@mkdir $(OBJLIBPATH) 2> /dev/null || true
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDS)

clean:
	rm -rf $(OBJPATH) $(OBJLIBPATH)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	rm -rf $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme: 
	@norminette $(SRC) $(LIB) $(INCLUDS)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"
