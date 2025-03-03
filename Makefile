##
## EPITECH PROJECT, 2024
## makefile
## File description:
## make moi des files
##

NAME	=	myhunter

SRCS	=	src/my_hunter.c\
			src/set_all.c \
			src/animations.c \
			src/score.c \
			src/some_sounds.c \
			src/events.c \
			src/bonus.c \
			src/more_setup.c \

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			gcc -o $(NAME) $(SRCS) -lcsfml-graphics \
			-lcsfml-window -lcsfml-system -lcsfml-audio -I include/

CFLAGS	:	-Wall -Wextra -Wshadow

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm $(NAME)

re		:	fclean all
