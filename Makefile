NAME = pipex
B_NAME = pipex

CC = gcc
GFLAGS = -Wall -Werror -Wextra -g

SRCDIR = src/
OBJDIR = obj/

B_SRCDIR = src_bonus/
B_OBJDIR = obj_bonus/

SRCFILES = free_it.c get_cmd.c handle_cmd.c handle_exit.c handle_print.c init.c main.c parse_arg.c paths.c pipes.c utils.c
SRCOBJ = $(SRCFILES:%.c=$(OBJDIR)%.o)

B_SRCFILES = free_it.c get_cmd.c get_filename.c handle_cmd.c handle_doc.c handle_exit.c handle_print.c init.c main.c parse_arg.c paths.c pipes.c utils.c
B_SRCOBJ = $(B_SRCFILES:%.c=$(B_OBJDIR)%.o)

LIBFT = ./libft
HEADERS = -I include/pipex.h -I $(LIBFT)/headers
B_HEADERS = -I include_bonus/pipex_bonus.h -I $(LIBFT)/headers

.PHONY: all libft bonus clean fclean re

all: libft $(NAME)

$(NAME): $(SRCOBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(GFLAGS) $(SRCOBJ) $(HEADERS) $(LIBFT)/libft.a -o $(NAME)

bonus: $(B_SRCOBJ)
	$(MAKE) -C $(LIBFT)
	@if [ ! -f $(B_NAME) ]; then \
		$(CC) $(GFLAGS) $(B_SRCOBJ) $(B_HEADER) $(LIBFT)/libft.a -o $(B_NAME); \
	fi

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p ${OBJDIR}
	$(CC) -c $(GFLAGS) -o $@ $<

$(B_OBJDIR)%.o: $(B_SRCDIR)%.c
	@mkdir -p $(B_OBJDIR)
	$(CC) -c $(GFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJDIR)
	rm -rf $(B_OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all

tester: $(NAME)
	cd tester; \
	docker build -t test_grind . && docker run --ulimit nofile=1024:1024 -it test_grind
