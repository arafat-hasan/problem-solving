/***********************************************************************
*   FILE NAME:	Egypt-11854.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    04 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int b,h,o;
    while(scanf("%d %d %d",&b,&h,&o)==3) {
        if(b==0&&h==0&&o==0)
            break;
        if(b>h) {
            b=b+h;
            h=b-h;
            b=b-h;
        }
        if(h>o) {
            h=h+o;
            o=h-o;
            h=h-o;
        }
        if(b>h) {
            b=b+h;
            h=b-h;
            b=b-h;
        }
        if(b*b+h*h==o*o)
            printf("right\n");
        else
            printf("wrong\n");
        }
    return 0;
}
