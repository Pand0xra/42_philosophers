CC		= cc
CFLAGS	= -Wall -Wextra -Werror -MMD -MP
NAME	= philo
SRCS 	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
INC		= -I. -I$(LIBFT_PATH)
RM		= rm -rf

LIBFT_PATH	= ../libft
LIBFT		= $(LIBFT_PATH)/libft.a
LIBS		= -L $(LIBFT_PATH) -lft

RESET			= \033[0m
GREEN			= \033[32;01m
BLUE			= \033[34;01m
RED				= \033[31;01m
YELLOW			= \033[0;93m
CYAN			= \033[0;96m

.PHONY: 		all clean fclean re

all: 			$(NAME)

$(LIBFT):
				@echo "$(BLUE)----Compiling lib----$(RESET)"
				@$(MAKE) bonus -C $(LIBFT_PATH) > /dev/null 2>&1
				@echo "$(GREEN)libft Compiled!$(RESET)"

$(NAME): 		$(OBJS) $(LIBFT)
				@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME) $(LIBS) > /dev/null 2>&1
				@echo "\033[33mPhilosophers Is Compiled! \033[31mᕦ(♥\033[32m_\033[31m♥\033[32m)ᕤ"

%.o: 			%.c
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

clean:
				@$(RM) $(OBJS) $(OBJS:.o=.d)
				@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null 2>&1
				@echo "$(CYAN)Cleaned all .o files.$(RESET)"

fclean: 		clean
				@$(RM) $(NAME)
				@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null 2>&1
				@echo "$(CYAN)Cleaned $(NAME) and libft.$(RESET)"
				
re:				fclean all

-include $(OBJS:.o=.d)
