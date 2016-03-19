CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=volimage.cpp VolImage.cpp
DEPS=VolImage.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=volimage

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	@rm -f *.o


