#!/usr/bin/python


import os
import json

FLAG_FILE = ".flag_file_conf"
DEFAULT_TARGET_DIR = "./"

def find_flag_file(target_dir):
    current_files = os.listdir(target_dir)
    for file_name in current_files:
        if file_name == FLAG_FILE:
            return 0
    return 1

def create_flag_file():
    try:
        f = open(os.path.join(DEFAULT_TARGET_DIR, FLAG_FILE), "w")
        init_dict = {os.path.abspath(DEFAULT_TARGET_DIR): []}
        init_content = json.dumps(init_dict)
        f.write(init_content)
        f.close()
    except IOError as e:
        print "Failed to create flag file %s" % e
        exit(2)

if __name__ == "__main__":
    ret_find = find_flag_file(DEFAULT_TARGET_DIR)
    if ret_find != 0:
        create_flag_file()
