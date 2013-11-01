CXX=g++
LD=ld
CFLAGS=-c -Wall -std=c++11 -MMD
LDFLAGS=

MAIN=main.cpp
SOURCES=Character.cpp Hero.cpp Berserker.cpp Fighter.cpp Knight.cpp Rogue.cpp Wizard.cpp Monster.cpp Random.cpp $(MAIN) 
OBJECTS=$(SOURCES:.cpp=.o)
DEPS=$(OBJECTS:.o=.d)
EXECUTABLE=$(MAIN:.cpp=.out)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

-include $(DEPS)

.cpp.o:
	$(CXX) $(CFLAGS) -MF $(patsubst %.o,%.d,$@) $< -o $@

clean: 
	rm -rf $(OBJECTS) $(DEPS) $(EXECUTABLE)
