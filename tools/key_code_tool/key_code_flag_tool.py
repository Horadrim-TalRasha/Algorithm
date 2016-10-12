#!/usr/bin/python

import os
import json
import getopt
import sys

### ERROR CODE DEFINATION
ERROR_CODES = {
  "NO_ERROR":0,
  "WRONG_OPTIONS":1,
  "WRONG_ARGS_INSUFFICENT":2,
  "INVALID_ARGS":3,
  "EXCLUSIVE_ARGS":4,
  "MISSING_OPERATE_ARGS":5,
  "UNKNOWN_ERR_CODE":6,
  "CREATE_FLAG_FILE_ERR":10,
  "UNKNOWN_DIRECTORY":11,
  "KEY_CODE_FILE_NOT_EXIST":12,
  "NOT_IN_ROOT_DIR":13,
  "INVALID_FLAG_FILE":14
}

def parseOptions():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "e:t:a:p",
                                       [
                                        'error=', 'target=', 
                                        'add=', 'print'
                                       ])
    except getopt.GetoptError as e:
        print "Wrong options %s" % e
        ### to call usage()
        exit(ERROR_CODES['WRONG_OPTIONS'])
    except Exception as e:
        print e.value
        exit(ERROR_CODES['EXCLUSIVE_ARGS'])

    return parseDetailOptions(opts)

def parseDetailOptions(opts):
    cmd = ""
    args = {}
    if len(opts) == 0:
        print "Arguments is insufficent"
        ### to call usage()
        exit(ERROR_CODES['WRONG_ARGS_INSUFFICENT'])

    for opt, value in opts:
        if opt in ("-e", "--error"):
            cmd = "error-code"
            args["error-code-name"] = value
        elif opt in ("-t", "--target"):
            args["target-dir"] = value
        elif opt in ("-a", "--add"):
            cmd = "add-key-code"
            args["key-code"] = value
        elif opt in ("-p", "--print"):
            cmd = "print-key-codes"
        else:
            print "Arguments is invalid"
            ### to call usage()
            exit(ERROR_CODES['INVALID_ARGS'])
    return cmd, args

def displayErrCode(code_name):
    if code_name in ERROR_CODES.keys():
        print ERROR_CODES[code_name]
        return 0
    else:
        print "Unknown error code"
        return ERROR_CODES["UNKNOWN_ERR_CODE"]

def main(cmd, args):
    if cmd == "error-code":
        return displayErrCode(args["error-code-name"])
    elif cmd == "":
        print "missing operate arguments like add or print"
        return ERROR_CODES["MISSING_OPERATE_ARGS"]

    key_code_flag = None
    if args.get("target-dir") is None:
        key_code_flag = ky_code_flag()
    else:
        key_code_flag = ky_code_flag(args["target-dir"])
    if key_code_flag.find_flag_file() != 0:
        key_code_flag.create_flag_file()
    else:
        ret = key_code_flag.get_flag_file_conf()
        if ret != 0:
            return ret

    if cmd == "print-key-codes":
        key_code_flag.display_flag_files()
    elif cmd == "add-key-code":
        ret_add = key_code_flag.add_key_code_file(args["key-code"])
        if ret_add == 0:
            key_code_flag.commit_flag_conf()
        else:
            return ret_add
    return 0
        

class ky_code_flag:
    DEFAULT_TARGET_DIR = "./"
    FLAG_FILE_NAME = ".ky_code_flag_file"
    def __init__(self, target_dir = DEFAULT_TARGET_DIR):
        self.__conf_file_dir = target_dir
        self.__conf_file_name = ""
        self.__conf = {}

    def getConfFileDir(self):
        return self.__conf_file_dir

    def getConfFileName(self):
        return self.__conf_file_name

    def getFlagConf(self):
        return self.__conf

    def find_flag_file(self):
        if os.path.exists(self.__conf_file_dir):
            self.__conf_file_name = os.path.join(self.__conf_file_dir, ky_code_flag.FLAG_FILE_NAME)
        else:
            print "unknown target directory %s" % self.__conf_file_dir
            exit(ERROR_CODES["UNKNOWN_DIRECTORY"])

        if os.path.exists(self.__conf_file_name):
            return 0
        return 1

    def create_flag_file(self):
        try:
            f = open(self.__conf_file_name, "w")
            self.__conf = {"root":os.path.abspath(self.__conf_file_dir)}
            flag_file_content = json.dumps(self.__conf)
            f.write(flag_file_content)
            f.close()
        except IOError as e:
            print "Failed to create flag file exist: %s" % e
            exit(ERROR_CODES["CREATE_FLAG_FILE_ERR"])
        finally:
            f.close()
        return 0

    def add_key_code_file(self, key_code_file):
        if os.path.exists(key_code_file):
            file_abs_dir = ""
            is_dir = False
            if os.path.isdir(key_code_file):
                file_abs_dir = os.path.abspath(key_code_file)
                is_dir = True
            else:
                file_abs_dir = os.path.abspath(os.path.dirname(key_code_file))

            root_dir = self.__conf["root"]
            if not file_abs_dir.startswith(root_dir):
                return ERROR_CODES["NOT_IN_ROOT_DIR"]

            if self.__conf.get(file_abs_dir) is None:
                self.__conf[file_abs_dir] = []
                if is_dir:
                    return 0
            elif is_dir:
                print "absolute path %s of %s already included" % (file_abs_dir, key_code_file)
                return 0

            file_list = self.__conf[file_abs_dir]
            if key_code_file in file_list:
                return 0
            file_list.append(key_code_file)
            self.__conf[file_abs_dir] = file_list
            return 0
        else:
            print "File %s not exist" % key_code_file
        return ERROR_CODES["KEY_CODE_FILE_NOT_EXIST"]

    def get_flag_file_conf(self):
        with open(self.__conf_file_name, "r") as f:
            flag_file_content = f.read()
            try:
                self.__conf = json.loads(flag_file_content)
            except Exception as e:
                print "flag file is in wrong json format, please remove it and recreate"
                return ERROR_CODES["INVALID_FLAG_FILE"]
        return 0

    def commit_flag_conf(self):
        with open(self.__conf_file_name, "w") as f:
            conf_content = json.dumps(self.__conf)
            f.write(conf_content)

    def display_flag_files(self):
        for dir_name, file_list in self.__conf.items():
            if dir_name == "root":
                continue
            else:
                print "[%s]" % dir_name
                for flag_file in file_list:
                    print "    %s" % os.path.basename(flag_file)

if __name__ == "__main__":
    cmd, args = parseOptions()
    exit(main(cmd, args))
