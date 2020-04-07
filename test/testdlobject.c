/////////////////////////////////////
// File name : testdlobject.c
// Create date : 2016-06-05 03:39
// Modified date : 2020-04-07 21:07
// Author : DARREN
// Describe : not set
// Email : lzygzh@126.com
////////////////////////////////////


#include <stdio.h>
#include "../objectc/objectc/dllog.h"
#include "../objectc/dlobject/DLObject.h"
//#include "../objectc/dlsqlite/DLSqlite.h"
#include "../objectc/dlADTbase/DLADTBase.h"
#include "testdlobject.h"

static
void
testDLObject(void){
    Class DLObject* dlo = DLObject();
    const char* name = dlo->func->getClassName((void*)dlo);
    DL_TEST_COMPARE_VALUE(name,"DLObject","str")
    const char* name2 = dlo->func->getClassStack((void*)dlo);
    DL_TEST_COMPARE_VALUE(name2,"DLObject","str")
    dlo->func->freeSelf((void*)dlo);
}

//  static
//  void
//  testDLSqlite(void){
//      Class DLSqlite* dlp = DLSqlite("liuzy");
//      const char* name = dlp->func->getClassName((void*)dlp);
//      DL_TEST_COMPARE_VALUE(name,"DLSqlite","str")
//      char* person_name = dlp->func->getName((void*)dlp);
//      DL_TEST_COMPARE_VALUE(person_name,"liuzy","str")
//      dlp->func->freeSelf((void*)dlp);
//  }

static
void
testDLADTBase(void){
    Class DLADTBase* dlp = DLADTBase("liuzy");
    const char* name = dlp->func->getClassName((void*)dlp);
    DL_TEST_COMPARE_VALUE(name,"DLADTBase","str")
    char* person_name = dlp->func->getName((void*)dlp);
    DL_TEST_COMPARE_VALUE(person_name,"liuzy","str")
    const char* name2 = dlp->func->getClassStack((void*)dlp);
    DL_TEST_COMPARE_VALUE(name2,"DLADTBase","str")
    dlp->func->freeSelf((void*)dlp);
}

static
void
runtest(){
    testDLObject();
//    testDLSqlite();
    testDLADTBase();
}

void testdlobject(void){
    runtest();
}
