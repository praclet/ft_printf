NAME		:=	libftprintf.a

SRCS		:=	conversion.c		\
				arg_affectation.c	\
				ft_printf.c			\
				itoa_base.c			\
				list.c				\
				padding.c			\
				parser.c

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

AR			:=	ar
ARFLAGS		:=	rs

RM			:=	rm -f

##########################################################

OBJS		:=	$(SRCS:.c=.o)
DEPS		:=	$(OBJS:.o=.d)

.SILENT		:
.PHONY		:	all clean fclean re libft

%.d			:	%.c
	$(CC) -MM $< | sed -e '1s%^%$@ %' > $@
	echo './$@ generated.'

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@
	echo './$@ generated.'

$(NAME)(%.o)	:	%.o
	$(AR) $(ARFLAGS) $(NAME) $%
	echo './$% added to $(NAME).'

all $(NAME)	bonus	:	libft $(patsubst %,$(NAME)(%),$(OBJS))
	echo './$(NAME) completed.'

libft :
	$(MAKE) -C libft
	echo 'libft objects added to $(NAME).'

ifneq ($(MAKECMDGOALS),fclean)
-include $(DEPS)
endif

clean		:
	$(RM) $(OBJS)
	echo 'Object files deleted.'
	$(RM) $(DEPS)
	echo 'Dependancy files deleted.'

fclean		:	clean
	$(RM) $(NAME)
	echo './$(NAME) deleted.'

re			:	fclean all
