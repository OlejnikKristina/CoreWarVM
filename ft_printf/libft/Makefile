NAME			= libft.a
CFLAGS			= -Wall -Werror -Wextra

GNL				:= favorite/get_next_line
FAVORITE		:= atoi itoa ftoa itoa_base
MEM				:= bzero memalloc memcpy memccpy memcmp memchr memdel memmove memset
OTHER			:= count_digit foreach isalnum isprint isalpha isascii \
				isdigit range recursive_factorial tolower toupper
PUT				:= putchar putchar_fd putendl_fd putendl putnbr_fd putnbr putstr_fd putstr
STR				:= sqrt strcat strcmp strcpy strdup strlen strncat strncmp \
				strncpy strnstr strrchr strstr strchr strlcat strnew strdel strclr \
				striter striteri strmap strmapi strequ strnequ strsub strsplit strjoin \
				superjoin strrev
SPECIFIC_NAME	:= other/kr_count_words other/space favorite/findchr favorite/itoa64

OBJ			:=  $(addsuffix .o, $(addprefix ft_, $(FAVORITE) $(LST) $(MEM) $(OTHER) $(STR) $(PUT))) \
				findchr.o kr_count_words.o space.o itoa64.o get_next_line.o

FAVORITE	:= $(addprefix favorite/, $(addprefix ft_, $(FAVORITE)))
MEM			:= $(addprefix mem/, $(addprefix ft_, $(MEM)))
OTHER		:= $(addprefix other/, $(addprefix ft_, $(OTHER)))
PUT			:= $(addprefix put/, $(addprefix ft_, $(PUT)))
STR			:= $(addprefix str/, $(addprefix ft_, $(STR)))

SRC			:=  $(FAVORITE) $(LST) $(MEM) $(OTHER) $(PUT) \
				$(STR) $(SPECIFIC_NAME) $(GNL)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[0;32mlibft.a successfully created\033[0m"
	@ranlib $(NAME)

$(OBJ):
	@clang $(CFLAGS) -c $(addsuffix .c, $(SRC)) -I includes/
clean:
	@rm -f $(OBJ)
#	@echo "\033[0;33mRemove objects files from libft\033[0m"
fclean: clean
	@rm -f $(NAME)

re: fclean all

so:
	gcc -shared -o $(NAME) $(OBJ)

.PHONY: clean fclean all re
