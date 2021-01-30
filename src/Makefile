TARGET 	:= pkmn
OS 	:= linux

ifeq ($(OS),windows)
	CC 	:= x86_64-w64-mingw32-gcc
	WIN_INC := -I../include
	WIN_LIB := -L../lib
	LIBS 	:= -lSDL2 -lSDL2_image -lm -mwindows
	D 	:= -DWINDOWS
	SUFFIX	:= .exe
else
	CC 	:= gcc
	LIBS 	:= -lSDL2 -lSDL2_image -lm
endif

OBJS 	:= main.o \
	utils.o \
	draw/draw.o \
	init/init.o \
	input/input.o \
	state.o \
	asset/asset_manager.o \
	time/date_time.o \

pkmn: $(OBJS)
	@echo OS target: $(OS)
ifeq ($(OS),windows)
	@echo Macros defined: $(D)
endif
	$(CC) $(D) -o $(TARGET)$(SUFFIX) $(OBJS) $(WIN_INC) $(WIN_LIB) $(LIBS)
	@echo Sucessfully built file: pkmn$(SUFFIX)

%.o: %.c
	$(CC) $(D) -c $< $(WIN_INC) $(WIN_LIB) $(LIBS) -o $@

clean:
	rm -f $(TARGET)
	find . -name "*.o" -type f -delete

rebuild: clean pkmn
