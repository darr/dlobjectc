/////////////////////////////////////
// File name : testdllog.c
// Create date : 2016-05-22 05:18
// Modified date : 2020-04-07 21:07
// Author : DARREN
// Describe : not set
// Email : lzygzh@126.com
////////////////////////////////////

#include <stdio.h>
#include "../objectc/objectc/dllog.h"
#include "../objectc/objectc/dlcpstring.h"

static void
testUtf8Log(){
    DEBUG_LOG("你好 调试 日志");
    INFO_LOG("你好 信息 日志");
    WARNING_LOG("你好 警告 日志");
    ERROR_LOG("你好 错误 日志");
    FATAL_LOG("你好 致命 日志");
}

static void
testAsciLog(){
    DEBUG_LOG("hello debug log");
    INFO_LOG("hello info log");
    WARNING_LOG("hello warning log");
    ERROR_LOG("hello error log");
    FATAL_LOG("hello fatal log");
}

static void
testString(){
    char * testChar = mallocFormatString("testStr:%s testNo:%d","yes this is the test str",8);
    INFO_LOG(testChar);
    testChar = mallocFormatString("testStr:%s testNo:%d","是的 这就是测试字符串",8);
    INFO_LOG(testChar);
}

static void
testWriteLog(){
    setIsWriteLog(1);
    setLogWriteLevel(log_level_warning);
    DEBUG_LOG("write debug log");
    INFO_LOG("write info log");
    WARNING_LOG("write warning log");
    ERROR_LOG("write error log");
    FATAL_LOG("write fatal log");
}

static void
testAssert(){
    printf("set log mode release\n");
    setLogMode(log_mode_release);
    printf("set close log assert\n");
    setIsOpenAssert(0);
    DEBUG_LOG("assert debug log");
    INFO_LOG("assert info log");
    WARNING_LOG("assert warning log");
    ERROR_LOG("assert error log");
    FATAL_LOG("assert fatal log");

    printf("set open log assert \n");
    setLogMode(log_mode_develop);
    setIsOpenAssert(1);
    printf("set open assert level fatal \n");
    setOpenAssertLevel(log_level_fatal);
    DEBUG_LOG("assert debug log");
    INFO_LOG("assert info log");
    WARNING_LOG("assert warning log");
    //printf("set open assert level info \n");
    //setOpenAssertLevel(log_level_info);
    ERROR_LOG("assert error log");
    FATAL_LOG("assert fatal log");
}

static void
_linetest(){
    printf("linetest");
}

static void
testLogMain(){
    testAsciLog();
    testUtf8Log();
    testString();
    testAssert();
    testWriteLog();
    _linetest();
}

////// test code //////////////////////////////////////////

void
testLog(){
    testLogMain();
}


