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
.PHONY		:	all clean fclean re

%.d			:	%.c
	$(CC) -MM $< | sed -e '1s%^%$@ %' > $@
	echo './$@ generated.'

$(NAME)(%.o)	:	%.c
	$(CC) $(CFLAGS) -c $< -o $%
	echo './$% generated.'
	$(AR) $(ARFLAGS) $(NAME) $%
	echo './$% added to $(NAME).'

$(NAME)		:	$(patsubst %,$(NAME)(%),$(OBJS))
	echo './$(NAME) completed.'

all			:	$(NAME)

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
