##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_CORE			=	core/

PATH_GAMES			=	games/

PATH_GRAPHICALS		=	graphicals/

################# COMPILATION #################
.PHONY: all core games graphicals re clean fclean debug

all:
	make -C	$(PATH_CORE)
	make -C	$(PATH_GAMES)
	make -C	$(PATH_GRAPHICALS)

core:
	make -C	$(PATH_CORE)

games:
	make -C	$(PATH_GAMES)

graphicals:
	make -C	$(PATH_GRAPHICALS)

re:	fclean all

clean:
	@(make clean -C $(PATH_CORE)) > /dev/null
	@(make clean -C $(PATH_GAMES)) > /dev/null
	@(make clean -C $(PATH_GRAPHICALS)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_CORE)) > /dev/null
	@(make fclean -C $(PATH_GAMES)) > /dev/null
	@(make fclean -C $(PATH_GRAPHICALS)) > /dev/null

debug:
	@(make debug -C $(PATH_CORE)) > /dev/null
	@(make debug -C $(PATH_GAMES)) > /dev/null
	@(make debug -C $(PATH_GRAPHICALS)) > /dev/null
