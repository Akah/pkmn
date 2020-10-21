bin_PROGRAMS = pkmn

AM_CFLAGS = $(DEPS_CFLAGS)
AM_LIBS = $(DEPS_LIBS)
AM_LDFLAGS = -lSDL2 -lSDL2_image -lm

pkmn_SOURCES = \
	main.c main.h \
	draw.c draw.h \
	init.c init.h \
	input.c input.h \
	common.h

clean-local:
	@rm Makefile Makefile.in
	@rm -r .deps
