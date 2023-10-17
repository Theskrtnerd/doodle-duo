# List of source files
SOURCE_FILES = main.cpp src/GameObject.cpp src/GameObjectArray.cpp src/MoveableObject.cpp src/ImmoveableObject.cpp src/GameEngine.cpp src/Player.cpp src/functions.cpp src/Background.cpp src/Cell.cpp src/GameTextures.cpp src/ScreenButton.cpp src/Button.cpp src/Door.cpp src/Lever.cpp src/Exit.cpp src/Text.cpp src/Obstacle.cpp
INCLUDES = -I/usr/include/jsoncpp
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
FLAGS = -Wpedantic
EXECUTABLE = doodle_duo

# Main target
all: $(EXECUTABLE)

# Compile and link
$(EXECUTABLE): 
	g++ $(FLAGS) -o $(EXECUTABLE) $(SOURCE_FILES) $(INCLUDES) $(LIBRARIES)



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

.PHONY: all run debug release clean