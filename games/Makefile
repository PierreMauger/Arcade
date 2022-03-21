##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_NIBBLER		=	nibbler/

PATH_OTHER			=	other/

################# COMPILATION #################
.PHONY: all nibbler other re clean fclean debug

all:
	make -C	$(PATH_NIBBLER)
	make -C	$(PATH_OTHER)

nibbler:
	make -C	$(PATH_NIBBLER)

other:
	make -C	$(PATH_OTHER)

re:	fclean all

clean:
	@(make clean -C $(PATH_NIBBLER)) > /dev/null
	@(make clean -C $(PATH_OTHER)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_NIBBLER)) > /dev/null
	@(make fclean -C $(PATH_OTHER)) > /dev/null

debug:
	@(make debug -C $(PATH_NIBBLER)) > /dev/null
	@(make debug -C $(PATH_OTHER)) > /dev/null
