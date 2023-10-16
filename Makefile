# List of source files
SOURCE_FILES = main.cpp class/GameObject.cpp class/GameObjectArray.cpp class/MoveableObject.cpp class/ImmoveableObject.cpp class/GameEngine.cpp class/Player.cpp class/functions.cpp class/Background.cpp class/Cell.cpp class/GameTextures.cpp class/ScreenButton.cpp class/Button.cpp class/Door.cpp class/Lever.cpp class/Exit.cpp class/Text.cpp class/Obstacle.cpp
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