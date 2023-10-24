


import subprocess
from collections import defaultdict

import os

def count_lines_per_contributor(file_path, repo_path):
    os.chdir(repo_path)  # Change to repo root directory
    result = subprocess.run(['git', 'blame', file_path], capture_output=True, text=True)
    
    print("Git Blame Output:", result.stdout)
    
    lines = result.stdout.split('\n')
    contributors = defaultdict(int)
    
    for line in lines:
        if line:
            contributor = line.split('(')[1].split(' ')[0]
            contributors[contributor] += 1
            
    return contributors

if __name__ == "__main__":
    file_path = "src/GameEngine.cpp"  # Relative to repo root
    repo_path = "/mnt/c/Users/Tyler/Documents/GitHub/DoodleDuo"  # Repo root path
    contributors = count_lines_per_contributor(file_path, repo_path)
    
    for contributor, line_count in contributors.items():
        print(f"{contributor}: {line_count} lines")
