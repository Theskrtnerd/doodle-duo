#!/bin/bash

# Compile the C++ code
g++ -o doodle_duo gametest.cpp Map.cpp GameObject.cpp ImmoveableObject.cpp GameEngine.cpp -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./doodle_duo
else
    echo "Compilation failed."
fi
