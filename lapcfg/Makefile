#############################
##
##
#############################

## Define tools here
CPP = g++
LD = $(CPP)
CFLAGS = -c -std=c++11
LDFLAGS = -std=c++11

HEADERS = $(wildcard *.h)
SOURCES = $(wildcard [!.]*.cpp)
ADDITIONAL_DEPS = $(wildcard .*.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

TARGET = lapcfg

## Actual targets start here

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "[$(LD)] Linking $@...";
	@echo -n "[$(LD), $(LDFLAGS), $<, $@]";
	@$(LD) $(LDFLAGS) $< -o $@ && echo " SUAVE!" || echo " ERRÔ!"

$(OBJECTS) : $(ADDITIONAL_DEPS)

.cpp.o:
	@echo "[$(CPP)] Compiling $< -> $@...";
	@echo -n "[$(CPP), $(CFLAGS), $<, $@]";
	@$(CPP) $(CFLAGS) $< -o $@ && echo " SUAVE!" || echo " ERRÔ!";
	@echo;

clean:
	@rm -f $(OBJECTS)

purge: clean
	@rm -f $(TARGET)

rebuild: purge all
