#!/bin/bash

# List of source files
source_files=(
    gametest.cpp 
    Class/Map.cpp 
    Class/GameObject.cpp 
    Class/GameObjectArray.cpp 
    Class/MoveableObject.cpp 
    Class/ImmoveableObject.cpp 
    Class/GameEngine.cpp 
    Class/Player.cpp 
    Class/functions.cpp
    Class/Background.cpp
    Class/Cell.cpp
    Class/GameTextures.cpp
    Class/ScreenButton.cpp
    Class/Button.cpp
    Class/Door.cpp
    Class/Lever.cpp
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
