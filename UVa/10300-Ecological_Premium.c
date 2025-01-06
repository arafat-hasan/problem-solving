/***********************************************************************
*   FILE NAME: Ecological Premium-10300.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    02 Aug 2016    New             1.0         Completed,Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int environment_friendline,farmyard,t,f,budget;
    scanf("%d",&t);
    while(t>0) {
        t--;
        scanf("%d",&f);
        budget=0;
        while(f>0) {
            f--;
            scanf("%d %*d %d",&farmyard,&environment_friendline);
            budget+=environment_friendline*farmyard;
        }
        printf("%d\n",budget);
    }
    return 0;
}
