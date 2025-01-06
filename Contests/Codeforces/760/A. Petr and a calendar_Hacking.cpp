/***************************************************************
*   FILE NAME:  A. Petr and a calendar_Hacking.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   23 Jan 16      New         1.0         Completed
*****************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int m, wd, mth[12] = {31,28,31,30,31,30, 31, 31, 30, 31, 30, 31};
    cin >> m >> wd;
    cout << (6-((42-mth[m-1])-(wd-1))/7);
    return  0;
}
