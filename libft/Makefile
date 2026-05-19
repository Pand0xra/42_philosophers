CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
	ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
	ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
	ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_strtrim.c \
	ft_putnbr_fd.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c \
	ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
	ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_striteri.c \
	ft_printf.c ft_printf_utils.c ft_strcmp.c
BSRC=ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJ=$(SRC:.c=.o)
BOBJ=$(BSRC:.c=.o)
NAME=libft.a
AR=ar rcs
RM=rm -rf

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $(OBJ)

bonus: $(BOBJ) $(OBJ)
	$(AR) $(NAME) $^
 
%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
