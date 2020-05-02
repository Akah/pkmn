#OBJS specifies which files to compile as part of the project
OBJS = main.c init.c draw.c

#temp removal:
DEL = main.o init.o draw.o

CC = gcc

COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lm
OBJ_NAME = pkmn

# dpkg only
dependencies:
	sudo apt update -y
	sudo apt install -y libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev

build : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ../$(OBJ_NAME)
	rm -f $(DEL)

run:
	.././pkmn
