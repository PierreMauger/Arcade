##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	src/Sfml.cpp

#################### NAMES ######################
NAME			=	arcade_sfml.so

##################### OBJ #######################
OBJ				=	$(SRC:.cpp=.o)

##################### FLAGS #####################
CXXFLAGS		=	-fPIC -I include -I ../../include -lsfml-graphics -lsfml-window -lsfml-system -W -Wall -Wextra

CXXFLAGS_DEBUG	=	-g

################## COMPILATION ##################
$(NAME):	$(OBJ)
	@(g++ -shared $(OBJ) -o $(NAME) $(CXXFLAGS)) > /dev/null
	mkdir -p ../../lib/
	cp $(NAME) ../../lib/$(NAME)

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
