#!/bin/bash

# List of source files
source_files=(
    gametest.cpp 
    Map.cpp 
    GameObject.cpp 
    GameObjectArray.cpp 
    MoveableObject.cpp 
    ImmoveableObject.cpp 
    GameEngine.cpp 
    Player.cpp 
    functions.cpp
    Background.cpp
    Cell.cpp
    GameTextures.cpp
    ScreenButton.cpp
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
