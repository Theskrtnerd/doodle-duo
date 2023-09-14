#!/bin/bash

# Compile the C++ code
g++ -o doodle_duo gametest.cpp Map.cpp GameEngine.cpp -I/C:/SFML-2.5.1/include -lsfml-graphics -lsfml-window -lsfml-system -L/C:/SFML-2.5.1/lib

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./doodle_duo
else
    echo "Compilation failed."
fi
