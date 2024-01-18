CSRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
			libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c \
			libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
			libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
			libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
			libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
			libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
			srcs/client.c srcs/utils.c
COBJS = $(CSRCS:.c=.o)
SSRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
			libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c \
			libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
			libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
			libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
			libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
			libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
			srcs/server.c srcs/utils.c
SOBJS = $(SSRCS:.c=.o)
CBSRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
			libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c \
			libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
			libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
			libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
			libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
			libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
			srcs/client_bonus.c srcs/utils.c
CBOBJS = $(CBSRCS:.c=.o)
SBSRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
			libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c \
			libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
			libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
			libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
			libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
			libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
			srcs/server_bonus.c srcs/utils.c
SBOBJS = $(SBSRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
RM = rm -f

CLIENT = client
SERVER = server
BCLIENT = client_bonus
SCLIENT = server_bonus

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(COBJS)
	@printf "\033[0;32m [..]   Compiling client...\033[0m\n"
	@$(CC) $(CFLAGS) $(COBJS) -o $(CLIENT)
	@printf "\033[0;32m [OK]   Compiled client ✅\033[0m\n"

$(SERVER): $(SOBJS)
	@printf "\033[0;32m [..]   Compiling server...\033[0m\n"
	@$(CC) $(CFLAGS) $(SOBJS) -o $(SERVER)
	@printf "\033[0;32m [OK]   Compiled server ✅\033[0m\n"

bonus: $(BCLIENT) $(SCLIENT)

$(BCLIENT): $(CBOBJS)
	@printf "\033[0;32m [..]   Compiling bonus client...\033[0m\n"
	@$(CC) $(CFLAGS) $(CBOBJS) -o $(BCLIENT)
	@printf "\033[0;32m [OK]   Compiled bonus client ✅\033[0m\n"

$(SCLIENT): $(SBOBJS)
	@printf "\033[0;32m [..]   Compiling bonus server...\033[0m\n"
	@$(CC) $(CFLAGS) $(SBOBJS) -o $(SCLIENT)
	@printf "\033[0;32m [OK]   Compiled bonus server ✅\033[0m\n"

clean:
	@printf "\033[0;31m [..]   Cleaning...\033[0m\n"
	@$(RM) $(COBJS) $(SOBJS) $(CBOBJS) $(SBOBJS)
	@printf "\033[0;31m [OK]   Cleaned ✅\033[0m\n"

fclean: clean
	@printf "\033[0;31m [..]   Full cleaning...\033[0m \n"
	@$(RM) $(CLIENT) $(SERVER) $(BCLIENT) $(SCLIENT)
	@printf "\033[0;31m [OK]   Full cleaned ✅\033[0m\n"

re: fclean all

.PHONY: all clean fclean re