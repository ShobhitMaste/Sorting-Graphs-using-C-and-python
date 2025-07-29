import os

os.system("python generate_record.py")
os.system("g++ analyse_time.cpp sorts.cpp -o result")
os.system("result.exe")
os.system("python plot_graph.py")