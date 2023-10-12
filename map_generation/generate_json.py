import json
import csv
import random
data = [
  {
      "type": "Player",
      "colour": "Red",
      "x": 600,
      "y": 400
  },
  {
      "type": "Player",
      "colour": "Blue",
      "x": 600,
      "y": 500
  },
]

file = open('map_generation/example.csv')
csvreader = csv.reader(file)
data_list = list(csv.reader(file))
for i in range(20):
  for j in range(30):
    if data_list[i][j] == "c":
      data.append({
        'type': "Cell",
        
        'x': j*40,
        'y': i*40
      })

data.append({ 
      "type": "Background",
      "texture": "GameBackground.png"
  })

import json
with open('example_level.json', 'w', encoding='utf-8') as f:
    json.dump(data, f, ensure_ascii=False, indent=4)