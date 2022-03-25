##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	src/Core.cpp				\
					src/Error.cpp				\

SRC				+=	main.c

#################### NAMES ######################
NAME			=	arcade

##################### OBJ #######################
OBJ				=	$(SRC:.cpp=.o)

##################### FLAGS #####################
CXXFLAGS		=	-I include -Wall -Wextra -W

CXXFLAGS_DEBUG	=	-g

################## COMPILATION ##################
$(NAME):	$(OBJ)
	@(g++ $(OBJ) -o $(NAME) $(CXXFLAGS)) > /dev/null
	cp $(NAME) ../$(NAME)

all:	$(NAME)

debug:	CXXFLAGS += $(CXXFLAGS_DEBUG)
debug:	re

re:	fclean all

clean:
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@rm -f $(NAME)
