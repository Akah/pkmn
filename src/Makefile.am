bin_PROGRAMS = pkmn

AM_CFLAGS = $(DEPS_CFLAGS)
AM_LIBS = $(DEPS_LIBS)
AM_LDFLAGS = -lSDL2 -lSDL2_image -lm

pkmn_SOURCES = \
	main.c main.h \
	draw/draw.c draw/draw.h \
	init/init.c init/init.h \
	input/input.c input/input.h \
	state.c state.h \
	asset_manager.c asset_manager.h \
	assets.h \
	common.h

clean-local:
	@rm Makefile Makefile.in
	@rm -r .deps
