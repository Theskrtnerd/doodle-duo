


import subprocess
from collections import defaultdict

import os


""""
def count_lines_per_contributor(file_path, repo_path):
    os.chdir(repo_path)
    result = subprocess.run(['git', 'log', '--pretty=format:%an', '--follow', '--', file_path], capture_output=True, text=True)
    
    lines = result.stdout.split('\n')
    contributors = defaultdict(int)
    
    for line in lines:
        if line:
            contributors[line] += 1
            
    return contributors

if __name__ == "__main__":
    file_path = "src/GameEngine.cpp"  # Relative to repo root
    repo_path = "/mnt/c/Users/Tyler/Documents/GitHub/DoodleDuo"  # Repo root path
    contributors = count_lines_per_contributor(file_path, repo_path)
    
    for contributor, line_count in contributors.items():
        print(f"{contributor}: {line_count} lines")

"""

def count_contributors_single_file(file_path):
    result = subprocess.run(['git', 'blame', '--line-porcelain', file_path], capture_output=True, text=True)
    lines = result.stdout.split('\n')
    contributors = defaultdict(int)
    
    for line in lines:
        if line.startswith("author "):
            contributor = line[len("author "):]
            if contributor == "=":
                contributor = "Unknown"
            contributors[contributor] += 1
            
    return contributors


def count_total_contributors(repo_path, src_folder):
    os.chdir(repo_path)
    total_contributors = defaultdict(int)
    
    for file_name in os.listdir(src_folder):
        if not file_name.endswith(('.cpp', '.h')):
            continue  # Skip non-C++ files
        
        file_path = os.path.join(src_folder, file_name)
        contributors = count_contributors_single_file(file_path)
        
        for contributor, count in contributors.items():
            total_contributors[contributor] += count
            
    return total_contributors

if __name__ == "__main__":
    repo_path = "/mnt/c/Users/Tyler/Documents/GitHub/DoodleDuo"
    src_folder = "src"
    file_path = os.path.join(src_folder, "GameEngine.cpp")
    
    os.chdir(repo_path)
    contributors = count_contributors_single_file(file_path)
    
    for contributor, line_count in contributors.items():
        print(f"{contributor}: {line_count} lines")
