#!/bin/bash

TEST_SCRIPT=key_code_flag_tool.py
WITH_FLAG_FILE_DIR=test_dir_with_flag_file
NO_FLAG_FILE_DIR=test_dir_no_flag_file
INVALID_FLAG_FILE_DIR=test_dir_with_invalid_file
g_test_case_cnt=0
g_test_case_passed=0
g_test_case_failed=0

function test_args_sufficency()
{
    output=`./$TEST_SCRIPT`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e WRONG_ARGS_INSUFFICENT`
    if [ $ret -eq $errcode ]
    then
        echo "test_args_sufficency passed"
        return 0
    else
        echo "test_args_sufficency failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function test_wrong_args()
{
    output=`./$TEST_SCRIPT -e`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e WRONG_OPTIONS`
    if [ $ret -eq $errcode ]
    then
        echo "test_wrong_args passed"
        return 0
    else
        echo "test_wrong_args failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function test_invalid_args()
{
    output=`./$TEST_SCRIPT --error=WRONG_OPTIONS`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e INVALID_ARGS`
    if [ $ret -eq $errcode ]
    then
        echo "test_invalid_args passed"
        return 0
    else
        echo "test_invalid_args failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function test_missing_operate_args_case()
{
    output=`./$TEST_SCRIPT -t target_directory`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e MISSING_OPERATE_ARGS`
    if [ $ret -eq $errcode ]
    then
        echo "test_missing_operate_args_case passed"
        return 0
    else
        echo "test_missing_operate_args_case failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function test_unknown_target_dir_case()
{
    output=`./$TEST_SCRIPT -t ./unknown_directory -p`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e UNKNOWN_DIRECTORY`
    if [ $ret -eq $errcode ]
    then
        echo "test_unknown_target_dir_case passed"
        return 0
    else
        echo "test_unknown_target_dir_case failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function test_correct_target_dir_case()
{
    output=`./$TEST_SCRIPT -t $WITH_FLAG_FILE_DIR -p`
    ret=($echo $?)
    if [ $ret -eq 0 ]
    then
        echo "test_correct_target_dir_case passed"
        return 0
    else
        echo "test_correct_target_dir_case failed, expected value: 0 real value: $ret"
        return 1
    fi
}
 
function test_invalid_flag_file_case()
{
    output=`./$TEST_SCRIPT -t $INVALID_FLAG_FILE_DIR -p`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e INVALID_FLAG_FILE`
    if [ $ret -eq $errcode ]
    then
        echo "test_invalid_flag_file_case passed"
        return 0
    else
        echo "test_invalid_flag_file_case failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function test_no_flag_file_conf_case()
{
    result=`find $NO_FLAG_FILE_DIR -name .ky_code_file_flag`
    if [ -n "$result" ]
    then
        echo "please clean the .ky_code_flag_file first"
        return 1
    else
        output=`./$TEST_SCRIPT -t $NO_FLAG_FILE_DIR -p`
        ret=($echo $?)
        if [ $ret -eq 0 ]
        then
            result=`find $NO_FLAG_FILE_DIR -name .ky_code_flag_file`
            err_code=($echo $?)
            if [[ $err_code -eq 0 && -n $result ]]
            then
                echo "test_no_flag_file_conf_case passed, .ky_code_file_flag can be found at $NO_FLAG_FILE_DIR"
            else
                echo "test_no_flag_file_conf_case failed, $result $err_code"
                return 1
            fi
        else
            echo "test_invalid_flag_file_case failed, expected value: 0 real value: $ret"
            return 1
        fi
    fi

    return 0
}

function test_add_not_exist_key_code_file_case()
{
    output=`./$TEST_SCRIPT -t $NO_FLAG_FILE_DIR -a not_exist_file`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e KEY_CODE_FILE_NOT_EXIST`
    if [ $ret -eq $errcode ]
    then
        echo "test_add_not_exist_key_code_file_case passed"
        return 0
    else
        echo "test_add_not_exist_key_code_file_case failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function test_add_file_not_in_root_dir_case()
{
    output=`./$TEST_SCRIPT -t $NO_FLAG_FILE_DIR -a not_in_root_file`
    ret=($echo $?)
    errcode=`./$TEST_SCRIPT -e NOT_IN_ROOT_DIR`
    if [ $ret -eq $errcode ]
    then
        echo "test_add_file_not_in_root_dir_case passed"
        return 0
    else
        echo "test_add_file_not_in_root_dir_case failed, expected value: $errcode real value: $ret"
        return 1
    fi
}

function run_test_case()
{
    ((g_test_case_cnt++))
    test_name=$1
    echo "start $test_name......."

    $test_name
    ret=$?
    if [ $ret -eq 0 ]
    then
        ((g_test_case_passed++))
    else
        ((g_test_case_failed++))
    fi
}

function post_test()
{
    `rm -rf $NO_FLAG_FILE_DIR/.ky_code_flag_file`
}

function report_test_result()
{
    echo "===============       test result     =============="
    echo "test case num: $g_test_case_cnt"
    echo "test case passed: $g_test_case_passed"
    echo "test case failed: $g_test_case_failed"
    echo $(date)
    echo "===================================================="

}
### main
echo "test start at $(date)"
echo "===============      test running     =============="

run_test_case "test_args_sufficency"
run_test_case "test_wrong_args"
#run_test_case "test_invalid_args"
run_test_case "test_missing_operate_args_case"
run_test_case "test_unknown_target_dir_case"
run_test_case "test_correct_target_dir_case"
run_test_case "test_invalid_flag_file_case"
run_test_case "test_no_flag_file_conf_case"
run_test_case "test_add_not_exist_key_code_file_case"
run_test_case "test_add_file_not_in_root_dir_case"

./key_code_flag_tool_test.py
ret=$(echo $?)
if [ $ret -eq 0 ]
then
    echo "python test case all passed"
else
    echo "some cases failed in key_code_flag_tool_test.py"
fi

post_test
report_test_result
