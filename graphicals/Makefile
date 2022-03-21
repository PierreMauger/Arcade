##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_NCURSES		=	ncurses/

PATH_SDL			=	sdl/

PATH_SFML			=	sfml/

################# COMPILATION #################
.PHONY: all ncurses sdl sfml re clean fclean debug

all:
	make -C	$(PATH_NCURSES)
	make -C	$(PATH_SDL)
	make -C	$(PATH_SFML)

ncurses:
	make -C	$(PATH_NCURSES)

sdl:
	make -C	$(PATH_SDL)

sfml:
	make -C	$(PATH_SFML)

re:	fclean all

clean:
	@(make clean -C $(PATH_NCURSES)) > /dev/null
	@(make clean -C $(PATH_SDL)) > /dev/null
	@(make clean -C $(PATH_SFML)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_NCURSES)) > /dev/null
	@(make fclean -C $(PATH_SDL)) > /dev/null
	@(make fclean -C $(PATH_SFML)) > /dev/null

debug:
	@(make debug -C $(PATH_NCURSES)) > /dev/null
	@(make debug -C $(PATH_SDL)) > /dev/null
	@(make debug -C $(PATH_SFML)) > /dev/null
