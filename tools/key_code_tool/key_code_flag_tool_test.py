#!/usr/bin/python

import os
from key_code_flag_tool import ky_code_flag

case_count = 0
passed_count = 0
failed_count = 0

def test_add_key_code_files_case(flag):
    global case_count
    global passed_count
    global failed_count
    case_count += 1

    ret1 = flag.add_key_code_file("test_dir_no_flag_file/test_code_file1")
    ret2 = flag.add_key_code_file("test_dir_no_flag_file/test_code_file2")
    ret3 = flag.add_key_code_file("test_dir_no_flag_file/test_code_file3")

    if ret1 + ret2 + ret3 > 0:
        failed_count += 1
        print "add key code file failed"
        return 1

    flag_conf = flag.getFlagConf()
    root_dir = os.path.dirname(os.path.abspath(flag.getConfFileName()))

    if len(flag_conf) != 2:
        failed_count += 1
        print "flag file config item is expected to be 2, real value: %s" % len(flag_conf)
        return 1
    elif flag_conf.get("root") is None:
        failed_count += 1
        print "flag_conf has not key \"root\""
        return 1
    elif flag_conf.get(os.path.abspath("test_dir_no_flag_file")) is None:
        failed_count += 1
        print "flag file directory:%s  is not in config" % os.path.abspath("test_dir_no_flag_file")
        return 1
    elif root_dir != flag_conf["root"]:
        failed_count += 1
        print "%s %s" % (root_dir, flag_conf["root"])
        return 1
    elif len(flag_conf[os.path.abspath("test_dir_no_flag_file")]) != 3:
        failed_count += 1
        print "test_dir_no_flag_file's flag file count is expected to be 3, real value: %s" % len(flag_conf[os.path.abspath("test_dir_no_flag_file")])
        return 1
    else:
        passed_count += 1
    return 0

def test_add_same_key_code_files_case(flag):
    global case_count
    global passed_count
    global failed_count
    case_count += 1

    ret1 = flag.add_key_code_file("test_dir_no_flag_file/test_code_file1")
    ret2 = flag.add_key_code_file("test_dir_no_flag_file/test_code_file1")
    flag_conf = flag.getFlagConf()
    root_dir = os.path.dirname(os.path.abspath(flag.getConfFileName()))

    if ret1 + ret2 > 0:
        failed_count += 1
        print "add key code file failed"
        return 1
    elif len(flag_conf) != 2:
        failed_count += 1
        print "flag file config item is expected to be 2, real value: %s" % len(flag_conf)
        return 1
    elif flag_conf.get("root") is None:
        failed_count += 1
        print "flag_conf has not key \"root\""
        return 1
    elif flag_conf.get(os.path.abspath("test_dir_no_flag_file")) is None:
        failed_count += 1
        print "flag file directory:%s  is not in config" % os.path.abspath("test_dir_no_flag_file")
        return 1
    elif root_dir != flag_conf["root"]:
        failed_count += 1
        print "%s %s" % (root_dir, flag_conf["root"])
        return 1
    elif len(flag_conf[os.path.abspath("test_dir_no_flag_file")]) != 1:
        failed_count += 1
        print "test_dir_no_flag_file's flag file count is expected to be 1, real value: %s" % len(flag_conf[os.path.abspath("test_dir_no_flag_file")])
        return 1
    else:
        passed_count += 1

    return 0

def test_add_dir_case(flag):
    global case_count
    global passed_count
    global failed_count
    case_count += 1

    ret = flag.add_key_code_file("test_dir_no_flag_file/test_dir")
    flag_conf = flag.getFlagConf()
    if ret != 0:
        failed_count += 1
        return ret
    elif len(flag_conf) != 2:
        failed_count += 1
        print "flag file config item is expected to be 2, real value: %s" % len(flag_conf)
        return 1
    elif flag_conf.get(os.path.abspath("test_dir_no_flag_file/test_dir")) is None:
        failed_count += 1
        print "flag file directory:%s  is not in config" % os.path.abspath("test_dir_no_flag_file/test_dir")
        return 1
    elif len(flag_conf[os.path.abspath("test_dir_no_flag_file/test_dir")]) != 0:
        failed_count += 1
        print "test_dir_no_flag_file's flag file count is expected to be 1, real value: %s" % len(flag_conf[os.path.abspath("test_dir_no_flag_file/test_dir")])
        return 1
    else:
        passed_count += 1
    return 0

def test_add_dir_included_case(flag):
    global case_count
    global passed_count
    global failed_count
    case_count += 1

    ret = flag.add_key_code_file("test_dir_no_flag_file/test_dir")
    flag_conf = flag.getFlagConf()
    if ret != 0:
        failed_count += 1
        return ret
    elif len(flag_conf) != 2:
        failed_count += 1
        print "flag file config item is expected to be 2, real value: %s" % len(flag_conf)
        return 1
    elif flag_conf.get(os.path.abspath("test_dir_no_flag_file/test_dir")) is None:
        failed_count += 1
        print "flag file directory:%s  is not in config" % os.path.abspath("test_dir_no_flag_file/test_dir")
        return 1
    elif len(flag_conf[os.path.abspath("test_dir_no_flag_file/test_dir")]) != 0:
        failed_count += 1
        print "test_dir_no_flag_file's flag file count is expected to be 1, real value: %s" % len(flag_conf[os.path.abspath("test_dir_no_flag_file/test_dir")])
        return 1
    else:
        passed_count += 1
    return 0

def post_test():
    pass

def report_test_ret():
    global case_count
    global passed_count
    global failed_count

    print "case count: %s" % case_count
    print "passed count: %s" % passed_count
    print "failed count: %s" % failed_count

if __name__ == "__main__":
    flag = ky_code_flag("test_dir_no_flag_file")
    if flag.find_flag_file() != 0:
        flag.create_flag_file()
    else:
        ret = flag.get_flag_file_conf()
        if ret != 0:
            exit(ret)

    test_add_key_code_files_case(flag)

    os.system("rm -rf test_dir_no_flag_file/.ky_code_flag_file")

    flag_2 = ky_code_flag("test_dir_no_flag_file")
    if flag_2.find_flag_file() != 0:
        flag_2.create_flag_file()
    else:
        ret = flag_2.get_flag_file_conf()
        if ret != 0:
            exit(ret)

    test_add_same_key_code_files_case(flag_2)

    os.system("rm -rf test_dir_no_flag_file/.ky_code_flag_file")

    flag_3 = ky_code_flag("test_dir_no_flag_file")
    if flag_3.find_flag_file() != 0:
        flag_3.create_flag_file()
    else:
        ret = flag_3.get_flag_file_conf()
        if ret != 0:
            exit(ret)

    test_add_dir_case(flag_3)
    test_add_dir_included_case(flag_3)

    post_test()
    report_test_ret()
    if failed_count > 0:
        exit(1)
    else:
        exit(0)
