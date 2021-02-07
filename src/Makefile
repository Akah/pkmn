TARGET 	:= pkmn
OS 	:= linux

ifeq ($(OS),windows)
	CC 	:= x86_64-w64-mingw32-gcc
	INC	:= -I../include
	LIBS 	:= -L../lib -lSDL2 -lSDL2_image -lm -mwindows
	D 	:= -DWINDOWS
	SUFFIX	:= .exe
else
	CC 	:= gcc
	LIBS 	:= -lSDL2 -lSDL2_image -lm
endif

OBJS := main.o \
	utils.o \
	draw/draw.o \
	init/init.o \
	input/input.o \
	state.o \
	console.o \
	asset/asset_manager.o \
	time/date_time.o \

pkmn: $(OBJS)
	@echo OS target: $(OS)
ifeq ($(OS),windows)
	@echo Macros defined: $(D)
endif
	$(CC) $(D) -o $(TARGET)$(SUFFIX) $(OBJS) $(INC) $(LIBS)
	@echo Sucessfully built file: pkmn$(SUFFIX)

%.o: %.c
	$(CC) $(D) -c $< $(INC) $(LIBS) -o $@

clean:
	rm -f pkmn*
	find . -name "*.o" -type f -delete

rebuild: clean pkmn
