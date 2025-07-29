import os

os.system("python generate_record.py")
os.system("g++ analyse_time.cpp sorts.cpp -o result")
os.system("result.exe")