#!/bin/bash

# List of source files
source_files=(
    gametest.cpp 
    class/Map.cpp 
    class/GameObject.cpp 
    class/GameObjectArray.cpp 
    class/MoveableObject.cpp 
    class/ImmoveableObject.cpp 
    class/GameEngine.cpp 
    class/Player.cpp 
    class/functions.cpp
    class/Background.cpp
    class/Cell.cpp
    class/GameTextures.cpp
    class/ScreenButton.cpp
    class/Button.cpp
    class/Door.cpp
    class/Lever.cpp
    class/Exit.cpp
    class/Text.cpp
)

# Compile the C++ code
g++ -Wpedantic -o doodle_duo "${source_files[@]}" -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp -I/usr/include/jsoncpp
#//g++ -Wpedantic -o doodle_duo gametest.cpp Map.cpp GameObject.cpp GameObjectArray.cpp MoveableObject.cpp ImmoveableObject.cpp GameEngine.cpp Player.cpp functions.cpp -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp -I/usr/include/jsoncpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./doodle_duo
else
    echo "Compilation failed."
fi
