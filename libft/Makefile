# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-gef <lvan-gef@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/25 16:26:47 by lvan-gef      #+#    #+#                  #
#    Updated: 2023/04/14 18:12:39 by lvan-gef      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# compiler stuff
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

# dirs
OBJDIR = obj/
LLDIR = ll/
MEMDIR = mem/
PRINTDIR = printer/
STRDIR = str/
GNLDIR = gnl/
PRINTFDIR = printf/

# c files
LLFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
MEMFILES = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
PRINTFILES = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STRFILES = ft_strjoin.c ft_strlcat.c ft_itoa.c ft_atoi.c ft_isdigit.c ft_strlcpy.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_strnstr.c ft_strchr.c ft_striteri.c ft_isascii.c ft_isalnum.c ft_split.c ft_isalpha.c ft_strrchr.c ft_strlen.c ft_isprint.c ft_strtrim.c ft_substr.c ft_strmapi.c ft_toupper.c ft_is_whitespace.c ft_split_ws.c
GNLFILES = get_next_line.c get_next_line_utils.c
PRINTFFILES = ft_formatter.c ft_printf.c ft_writers.c

# objects
LLOBJ = $(LLFILES:%.c=$(OBJDIR)%.o)
MEMOBJ = $(MEMFILES:%.c=$(OBJDIR)%.o)
PRINTOBJ = $(PRINTFILES:%.c=$(OBJDIR)%.o)
STROBJ = $(STRFILES:%.c=$(OBJDIR)%.o)
GNLOBJ = $(GNLFILES:%.c=$(OBJDIR)%.o)
PRINTFOBJ = $(PRINTFFILES:%.c=$(OBJDIR)%.o)

INCLUDE = headers/libft.h
NAME = libft.a
LIB = ar rcs

.PHONY: all clean fclean re

$(NAME): $(LLOBJ) $(MEMOBJ) $(PRINTOBJ) $(STROBJ) $(GNLOBJ) $(PRINTFOBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJDIR)*

all: $(NAME)

# linked list
$(OBJDIR)%.o: $(LLDIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ $<

# mem
$(OBJDIR)%.o: $(MEMDIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ $<

# print
$(OBJDIR)%.o: $(PRINTDIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ $<

# put char
$(OBJDIR)%.o: $(STRDIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ $<

# gnl
$(OBJDIR)%.o: $(GNLDIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ $<

# printf
$(OBJDIR)%.o: $(PRINTFDIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
