CC = cc
CFLAGS = -Wall -Werror -Wextra -Wshadow -Wpedantic

# Root source directory
SRC = src/

# dirs
OBJDIR = obj/

LLDIR = $(SRC)ll/
MEMDIR = $(SRC)mem/
PRINTDIR = $(SRC)printer/
STRDIR = $(SRC)str/
GNLDIR = $(SRC)gnl/
PRINTFDIR = $(SRC)ft_printf/

# c files
LLFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
MEMFILES = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
PRINTFILES = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STRFILES = ft_strjoin.c ft_strlcat.c ft_itoa.c ft_atoi.c ft_isdigit.c ft_strlcpy.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_strnstr.c ft_strchr.c ft_striteri.c ft_isascii.c ft_isalnum.c ft_split.c ft_isalpha.c ft_strrchr.c ft_strlen.c ft_isprint.c ft_strtrim.c ft_substr.c ft_strmapi.c ft_toupper.c ft_atoli.c ft_iswhitespace.c ft_split_ws.c ft_atof.c
GNLFILES = get_next_line.c get_next_line_utils.c
PRINTFFILES = ft_formatter.c ft_printf.c ft_writers.c

# objects
LLOBJ = $(LLFILES:%.c=$(OBJDIR)ll/%.o)
MEMOBJ = $(MEMFILES:%.c=$(OBJDIR)mem/%.o)
PRINTOBJ = $(PRINTFILES:%.c=$(OBJDIR)printer/%.o)
STROBJ = $(STRFILES:%.c=$(OBJDIR)str/%.o)
GNLOBJ = $(GNLFILES:%.c=$(OBJDIR)gnl/%.o)
PRINTFOBJ = $(PRINTFFILES:%.c=$(OBJDIR)ft_printf/%.o)

HEADERS = -I include
NAME = libft.a
LIB = ar rcs

.PHONY: all clean fclean re

$(NAME): $(LLOBJ) $(MEMOBJ) $(PRINTOBJ) $(STROBJ) $(GNLOBJ) $(PRINTFOBJ) $(INCLUDE)
	$(LIB) $(NAME) $(LLOBJ) $(MEMOBJ) $(PRINTOBJ) $(STROBJ) $(GNLOBJ) $(PRINTFOBJ) -s

all: $(NAME)

# linked list
$(OBJDIR)ll/%.o: $(LLDIR)%.c
	@mkdir -p $(OBJDIR)ll
	$(CC) $(HEADERS) -c $(CFLAGS) -o $@ $<

# mem
$(OBJDIR)mem/%.o: $(MEMDIR)%.c
	@mkdir -p $(OBJDIR)mem
	$(CC) $(HEADERS) -c $(CFLAGS) -o $@ $<

# print
$(OBJDIR)printer/%.o: $(PRINTDIR)%.c
	@mkdir -p $(OBJDIR)printer
	$(CC) $(HEADERS) -c $(CFLAGS) -o $@ $<

# str
$(OBJDIR)str/%.o: $(STRDIR)%.c
	@mkdir -p $(OBJDIR)str
	$(CC) $(HEADERS) -c $(CFLAGS) -o $@ $<

# gnl
$(OBJDIR)gnl/%.o: $(GNLDIR)%.c
	@mkdir -p $(OBJDIR)gnl
	$(CC) $(HEADERS) -c $(CFLAGS) -o $@ $<

# printf
$(OBJDIR)ft_printf/%.o: $(PRINTFDIR)%.c
	@mkdir -p $(OBJDIR)ft_printf
	$(CC) $(HEADERS) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
