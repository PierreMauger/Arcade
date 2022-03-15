##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=

SRC				+=	src/main.cpp						\

#################### NAMES ######################
NAME 			=	nanotekspice

##################### OBJ #######################
OBJ				=	$(SRC:.cpp=.o)

##################### FLAGS #####################
CXXFLAGS		=	-I include -Wall -Wextra -W

CXXFLAGS_DEBUG	=	-g

# CXX = clang++

################## COMPILATION ##################
$(NAME):	$(OBJ)
	@(g++ $(OBJ) -o $(NAME)) > /dev/null

all:	$(NAME)

debug:	CXXFLAGS += $(CXXFLAGS_DEBUG)
debug:	all

re:	fclean all

clean:
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@(rm -f $(NAME)) > /dev/null
