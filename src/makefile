objects =\
	main.o\
	init.o\
	input.o\
	draw.o\

libs =-lSDL2 -lSDL2_image -lm

pkmn: $(objects)
	cc -o pkmn $(objects) $(libs)

main.o: main.h
init.o: init.h
input.o: input.h
draw.o: draw.h

dependencies:
	sudo apt update -y
	sudo apt install -y libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev

.PHONY: clean

clean:
	rm -f *.o
