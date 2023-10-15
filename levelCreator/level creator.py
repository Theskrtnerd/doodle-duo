import csv
import json

def cell(x, y):
    output = {}
    output["type"] = "Cell"
    output["texture"] = random.choice(["Cell", "Cell1", "Cell2", "Cel3"])+".png"
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

# Mapping of function and color
func_map = {'c': cell, 'i': invisCell, 'p': player, 'd': door, 'b': button, 'l': lever, 'e': exit, 'o': obstacle}
color_map = {'r': 'red', 'b': 'blue', 'g': 'green', 'y': 'yellow', 'm': 'magenta', 'c': 'cyan'}


csv_file_path = "input.csv"
grid = []
with open(csv_file_path, mode='r') as file:
    csv_reader = csv.reader(file)
    for y_index, row in enumerate(csv_reader):
        row_list = []
        for x_index, cell_content in enumerate(row):
            if cell_content == '':
                row_list.append(cell(x_index, y_index))
            else:
                func_char, color_char = cell_content[0], cell_content[1]
                func = func_map.get(func_char.lower())
                color = color_map.get(color_char.lower())
                row_list.append(func(color, x_index, y_index))
        grid.append(row_list)

# Save to JSON
json_file_path = "output.json"
with open(json_file_path, 'w') as json_file:
    json.dump(grid, json_file)
