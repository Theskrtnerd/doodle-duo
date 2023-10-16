# List of source files
SOURCE_FILES = gametest.cpp class/Map.cpp class/GameObject.cpp ... class/Obstacle.cpp
INCLUDES = -I/usr/include/jsoncpp
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
FLAGS = -Wpedantic
EXECUTABLE = doodle_duo

# Main target
all: $(EXECUTABLE)

# Compile and link
$(EXECUTABLE): 
	g++ $(FLAGS) -o $(EXECUTABLE) $(SOURCE_FILES) $(INCLUDES) $(LIBRARIES)

# Run the executable
run: 
	./$(EXECUTABLE)

# Clean up object files and executable
clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean