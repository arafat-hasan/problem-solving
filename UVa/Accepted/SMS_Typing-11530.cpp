/**************************************************************
*   FILE NAME:  SMS Typing-11530.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   21 Nov 16      New         1.0         Completed, Accepted
***************************************************************/
#include <stdio.h>
#include <string.h>

int main() {

    int i, j = 0, len, prs, t;
    char str[101];
    scanf("%i", &t);
    getchar();	//Receive new line
    while(j < t) {
		
        j++;
        gets(str);	//As std.in has blank line/s, using "[^\n]" occure WA. 
        len = strlen(str);
        if(len==0) continue;	//It is needed, WA without it.
        prs = 0;
        
        for(i = 0; i < len; i++) {

            switch(str[i]) {

            case 'a':
            case 'd':
            case 'g':
            case 'j':
            case 'm':
            case 'p':
            case 't':
            case 'w':
            case ' ':
                prs +=1;
                break;

            case 'b':
            case 'e':
            case 'h':
            case 'k':
            case 'n':
            case 'q':
            case 'u':
            case 'x':
                prs +=2;
                break;


            case 'c':
            case 'f':
            case 'i':
            case 'l':
            case 'o':
            case 'r':
            case 'v':
            case 'y':
                prs +=3;
                break;


            case 's':
            case 'z':
                prs +=4;
                break;

            default :
                break;

            }
        }
        
        printf("Case #%i: %i\n", j, prs);

    }

    return 0;
}
