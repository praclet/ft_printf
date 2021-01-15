NAME		:=	libft.a

SRCS		:=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c
SRCSBONUS	:=	ft_lstadd_back.c ft_lstadd_front.c \
	ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
	ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

AR			:=	ar
ARFLAGS		:=	rs

RM			:=	rm -f

##########################################################

OBJS		:=	$(SRCS:.c=.o)
OBJSBONUS	:=	$(SRCSBONUS:.c=.o)
DEPS		:=	$(OBJS:.o=.d)
DEPSBONUS	:=	$(OBJSBONUS:.o=.d)

%.d			:	%.c
	$(CC) -MM $< | sed -e 's%^%$@ %' > $@
	echo './$@ generated.'

$(NAME)(%.o)	:	%.c
	$(CC) $(CFLAGS) -c $< -o $%
	echo './$% generated.'
	$(AR) $(ARFLAGS) $(NAME) $%
	echo './$% added to $(NAME).'

$(NAME)		:	Makefile $(patsubst %,$(NAME)(%),$(OBJS))
	echo './$(NAME) completed.'

.PHONY		:	all
all			:	$(NAME)

.PHONY		:	bonus
bonus		:	$(patsubst %,$(NAME)(%),$(OBJSBONUS))
	echo 'Bonus completed.'

$(OBJS) $(DEPS) $(OBJSBONUS) $(DEPSBONUS)	: Makefile

ifneq ($(MAKECMDGOALS),fclean)
-include $(DEPS)
-include $(DEPSBONUS)
endif

.PHONY		:	clean
clean		:
	$(RM) $(OBJS)
	$(RM) $(OBJSBONUS)
	echo 'Object files deleted.'
	$(RM) $(DEPS)
	$(RM) $(DEPSBONUS)
	echo 'Dependancy files deleted.'

.PHONY		:	fclean
fclean		:	clean
	$(RM) $(NAME)
	echo './$(NAME) deleted.'

.PHONY		:	re
re			:	fclean all

.SILENT		:
