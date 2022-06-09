##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD05-matteo.linzi
## File description:
## Makefile
##


### SOURCES ###
#----c_sources----#
SRC			:=	src/strlen.asm
SRC			+=	src/strchr.asm
SRC			+=	src/strrchr.asm
SRC			+=	src/memset.asm
SRC			+=	src/memcpy.asm
SRC			+=	src/strcmp.asm
SRC			+=	src/strncmp.asm
SRC			+=	src/strstr.asm
SRC			+=	src/memmove.asm
#------other------#
OBJ			:=	$(SRC:.asm=.o)
INC			:=	./headers/
#----tests_sources----#
UT_SRC		:= tests/test_strlen.c
UT_SRC		+= tests/test_strchr.c
UT_SRC		+= tests/test_strrchr.c
UT_SRC		+= tests/test_memset.c
UT_SRC		+= tests/test_memcpy.c
UT_SRC		+= tests/test_strcmp.c
UT_SRC		+= tests/test_strncmp.c
UT_SRC		+= tests/test_strstr.c
UT_SRC		+= tests/test_memmove.c
### SOURCES ###


### COMPILE_USEFULL ###
#----general_usefull----#
NASM		=	nasm
CC			=	gcc
#----project_usefull----#
NAME		=	libasm.so
MAKEFLAGS 	+=	--no-print-directory
NASMFLAGS	+=	-f elf64 -I headers/ -Werror
LD			=	ld
#----unit_test_usefull----#
UT_NAME		=	testbin
UT_FLAGS	=	--coverage -lcriterion
### COMPILE_USEFULL ###


### RULES_USEFULL ###
GCOVR		=	gcovr --exclude tests/
### RULES_USEFULL ###


all:		$(NAME) clean

%.o:		%.asm
			$(NASM) $(NASMFLAGS) -o $@ $<

$(NAME):	$(OBJ)
			$(LD) -shared -o $(NAME) $(OBJ)

tests_run:	fclean all $(UT_NAME)
$(UT_NAME):
			$(CC) $(UT_FLAGS) -o $(UT_NAME) $(UT_SRC) $(LFLAGS)
			@$(call ccend, "Unit tests successfully compiled.")
			./$(UT_NAME)

utest:		tests_run
			$(GCOVR)
			$(GCOVR) --branche
			$(RM) *.gc* $(UT_NAME)

clean:
			$(RM) $(OBJ) $(UT_OBJ) *.gc* *.o *vgcore.*

fclean:		clean
			$(RM) $(NAME) $(UT_NAME)

re:			fclean all

.PHONY:		all clean fclean re