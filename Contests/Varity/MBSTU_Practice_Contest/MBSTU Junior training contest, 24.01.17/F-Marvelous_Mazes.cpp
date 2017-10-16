/***********************************************************************
*   FILE NAME: F-Marvelous_Mazes.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    24 Jan 17    New             1.0         Completed,NC
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {

    char str[1000];

    while(gets(str)) {

        if(str[0]=='\n')
            printf("\n");
        else
            printf("##%s\n", str);


    }

    return 0;
}
