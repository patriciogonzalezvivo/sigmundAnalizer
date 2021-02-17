EXE = sigmundAnalizer
CXX = g++
SOURCES := 	$(wildcard src/*.cpp)
HEADERS := 	$(wildcard src/*.h)
OBJECTS := $(SOURCES:.cpp=.o)

INCLUDES +=	-Isrc/ -Iinclude/
CFLAGS += -Wall -O2 -std=c++11 -fpermissive 
LDFLAGS += -lglut -lGL -lasound -lfftw3f -lm -pthread 

all: $(EXE)

%.o: %.cpp
	@echo $@
	$(CXX) $(CFLAGS) $(INCLUDES) -g -c $< -o $@ -Wno-deprecated-declarations

$(EXE): $(OBJECTS) $(HEADERS)
	$(CXX) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -rdynamic -o $@

clean:
	@rm -rvf $(EXE) src/*.o

install:
	@cp $(EXE) /usr/local/bin
