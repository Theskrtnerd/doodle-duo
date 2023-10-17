# List of source files
SOURCE_FILES = src/GameObject.cpp src/GameObjectArray.cpp src/MoveableObject.cpp src/ImmoveableObject.cpp src/GameEngine.cpp src/Player.cpp src/functions.cpp src/Background.cpp src/Cell.cpp src/GameTextures.cpp src/ScreenButton.cpp src/Button.cpp src/Door.cpp src/Lever.cpp src/Exit.cpp src/Text.cpp src/Obstacle.cpp
MAIN_SOURCE = main.cpp
TESTING_SOURCE = tests/test.cpp
INCLUDES = -I/usr/include/jsoncpp
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
FLAGS = -Wpedantic
EXECUTABLE = doodle_duo

# Main target
all: $(EXECUTABLE)

# Compile and link
$(EXECUTABLE): 
	g++ $(FLAGS) $(MAIN_SOURCE) $(SOURCE_FILES) $(INCLUDES) -o $(EXECUTABLE) $(LIBRARIES)
	
test: $(EXECUTABLE)
	g++ $(FLAGS) -o test_exec $(TESTING_SOURCE) $(INCLUDES) $(LIBRARIES)
	./test_exec

# Debug target
debug: FLAGS += -g
debug: $(EXECUTABLE)

# Release target
release: FLAGS += -O3
release: $(EXECUTABLE)

# Clean
clean:
	rm -f $(EXECUTABLE)

# Run the executable
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all run debug release clean test