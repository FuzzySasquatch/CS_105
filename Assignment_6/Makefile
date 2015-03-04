CC = g++
CFLAGS = -Wall
SOURCES = Person.cpp Rating.cpp Matcher.cpp main.cpp
HEADERS = Person.h Rating.h Matcher.h
OBJECTS = $(SOURCES: .cpp = .o)
EXECUTABLE = a.out
TEST = input.txt

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o: 
	$(CC) $(CFLAGS) $< -o $@

test: $(EXECUTABLE)
	./$(EXECUTABLE) < $(TEST)

clean:
	rm -rf *.o $(EXECUTABLE)
