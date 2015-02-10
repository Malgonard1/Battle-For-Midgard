##
## Makefile for  in /home/hajem_s/3semaine/colle/malong_a/quete1
## 
## Made by HAJEM Souheil
## Login   <hajem_s@etna-alternance.net>
## 
## Started on  Fri Oct 31 09:39:31 2014 HAJEM Souheil
## Last update Sat Nov  1 18:01:03 2014 HAJEM Souheil
##

NAME= ragnarok

CC= gcc

CFLAGS+= -W -pedantic -ansi -Wall -Werror

LDFLAGS= -L. -lmy

OBJS= $(SRCS:.c=.o)

RM= rm -f

SRCS=	main.c\
	command_hero.c\
	command_hero2.c\
	command_ennemy.c\
	command_check.c\
	read_lines.c\
	init_characters.c\

$(NAME) :	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all :		$(NAME)

clean :
		$(RM) $(OBJS)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)

re:		fclean all