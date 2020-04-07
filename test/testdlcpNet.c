/////////////////////////////////////
// File name : testdlcpNet.c
// Create date : 2016-05-22 05:18
// Modified date : 2020-04-07 21:05
// Author : DARREN
// Describe : not set
// Email : lzygzh@126.com
////////////////////////////////////

#include "testdlcpNet.h"
#include "../objectc/objectc/dlcpNet.h"
#include "../objectc/objectc/dllog.h"


////// test code //////////////////////////////////////////
void
testdlcpNetClient(){
    int serverPort = 7589;
    char *sendContent = "send this message from a client\n";
    char *serverIP = "106.187.39.151";
    //char *serverIP = "127.0.0.1";
    char* ret_content = blockTcpRequest(sendContent,serverIP,serverPort);
    INFO_LOG(ret_content);
}

void
testdlcpNetServer(){
    int serverPort = 7589;
    char *sendContent = "send this message from a client \n";
    char *serverIP = "127.0.0.1";
    char* ret_content = blockTcpRequest(sendContent,serverIP,serverPort);
    INFO_LOG(ret_content);
}

void
testdlcpNet(){
    testdlcpNetClient();
}


