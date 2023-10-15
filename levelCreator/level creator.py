import csv
import json
import random

def cell(x, y):
    output = {}
    output["type"] = "Cell"
    output["texture"] = random.choice(["Cell", "Cell1", "Cell2", "Cell3"])+".png"
    output["x"] = x*40
    output["y"] = y*40
    return output

def invisCell(x, y):
    output = {}
    output["type"] = "Cell"
    output["texture"] = "CellInvisible.png"
    output["x"] = x*40
    output["y"] = y*40
    return output

def player(color, x, y):
    output = {}
    output["type"] = "Player"
    output["colour"] = color
    output["x"] = x * 40
    output["y"] = y * 40
    return output

def door(color, x, y):
    output = {}
    output["type"] = "Door"
    output["colour"] = color
    output["x"] = x * 40
    output["y"] = y * 40
    return output

def button(color, x, y):
    output = {}
    output["type"] = "Button"
    output["colour"] = color
    output["x"] = x * 40
    output["y"] = y * 40
    return output

def lever(color, x, y):
    output = {}
    output["type"] = "Lever"
    output["colour"] = color
    output["x"] = x * 40
    output["y"] = y * 40
    return output

def exit(color, x, y):
    output = {}
    output["type"] = "Exit"
    output["colour"] = color
    output["x"] = x * 40
    output["y"] = y * 40
    return output

def obstacle(color, x, y):
    output = {}
    output["type"] = "Obstacle"
    output["colour"] = color
    output["x"] = x * 40
    output["y"] = y * 40
    return output



def createJsonFromCSV(level):
    # Mapping of function and color
    func_map = {'c': cell, 'i': invisCell, 'p': player, 'd': door, 'b': button, 'l': lever, 'e': exit, 'o': obstacle}
    color_map = {'r': 'red', 'b': 'blue', 'g': 'green', 'y': 'yellow', 'm': 'magenta', 'c': 'cyan'}

    csv_file_path = f"levelCreator/levels - Lv{level}.csv"
    json_file_path = f"assets/levels/level{level}.json"
    output = []
    
    with open(csv_file_path, 'r') as file:
        csv_reader = csv.reader(file)
        for y_index, row in enumerate(csv_reader):
            for x_index, cell_content in enumerate(row):
                if cell_content == 'c':
                    output.append(cell(x_index, y_index))
                elif cell_content == 'i':
                    output.append(invisCell(x_index, y_index))
                elif cell_content == '':
                    pass
                else:
                    func_char, color_char = cell_content[0], cell_content[1]
                    func = func_map.get(func_char.lower())
                    color = color_map.get(color_char.lower())
                    output.append(func(color, x_index, y_index))
    
    # Add additional elements
    output.append({"type": "Text", "text": f"Lv. {level}", "x": 25, "y": 735, "fontSize": 44, "colour": "black"})
    output.append({"type": "ScreenButton", "texture": "SettingsGear.png", "action": "openSettings", "x": 1120, "y": 720})
    output.append({"type": "ScreenButton", "texture": "3x2.png", "action": "EASTER", "x": 0, "y": 720})
    output.append({"type": "Background", "texture": "GameBackground.png"})
    
    # Save to JSON
    with open(json_file_path, 'w') as json_file:
        json.dump(output, json_file)

createJsonFromCSV(1)
createJsonFromCSV(2)
createJsonFromCSV(3)
createJsonFromCSV(4)
createJsonFromCSV(5)
createJsonFromCSV(6)
