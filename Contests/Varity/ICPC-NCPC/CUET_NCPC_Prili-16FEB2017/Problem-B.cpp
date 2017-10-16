/*
 * FILE: Problem-B.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 *
 */


#include <iostream>
#include <cstdio>
#include <cstring>

int main() {

    int t, c = 0, date, month;
    char M;
    cin >> t;
    while(c++ < t) {
        scanf("%s", M);
        cin << date;

        if(strcmp(M, "January") == 0)			month = 1;
        else if(strcmp(M, "February") == 0)		month = 2;
        else if(strcmp(M, "March") == 0)		month = 3;
        else if(strcmp(M, "April") == 0)		month = 4;
        else if(strcmp(M, "May") == 0)			month = 5;
        else if(strcmp(M, "June") == 0)			month = 6;
        else if(strcmp(M, "July") == 0)			month = 7;
        else if(strcmp(M, "August") == 0)		month = 8;
        else if(strcmp(M, "September") == 0)	month = 9;
        else if(strcmp(M, "October") == 0) 		month = 10;
        else if(strcmp(M, "November") == 0)		month = 11;
        else 									month = 12;


    }

    return 0;
}


