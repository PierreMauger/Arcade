##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_NIBBLER		=	nibbler/

PATH_QIX			=	qix/

PATH_MENU			=	menu/

################# COMPILATION #################
.PHONY: all nibbler qix menu re clean fclean debug

all:
	make -C	$(PATH_NIBBLER)
	# make -C	$(PATH_QIX)
	make -C	$(PATH_MENU)

nibbler:
	make -C	$(PATH_NIBBLER)

qix:
	make -C	$(PATH_QIX)

menu:
	make -C	$(PATH_MENU)

re:	fclean all

clean:
	@(make clean -C $(PATH_NIBBLER)) > /dev/null
	# @(make clean -C $(PATH_QIX)) > /dev/null
	@(make clean -C $(PATH_MENU)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_NIBBLER)) > /dev/null
	# @(make fclean -C $(PATH_QIX)) > /dev/null
	@(make fclean -C $(PATH_MENU)) > /dev/null

debug:
	make debug -C $(PATH_NIBBLER)
	# make debug -C $(PATH_QIX)
	make debug -C $(PATH_MENU)
