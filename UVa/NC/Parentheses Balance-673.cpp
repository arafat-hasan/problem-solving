/***************************************************************
*   FILE NAME:  Parentheses Balance-673.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ----------------------------------------------------------------------
*   02 Nov 16      New         1.0         not-Completed
*****************************************************************/
#include <stdio.h>
int main() {
    int t,i, c_f_o, c_f_c, c_t_o, c_t_c;
    char str[200];
    scanf("%i", &t);
    while(t-- && scanf(" %[^\n]", str)==1) {
		c_f_o = 0, c_f_c = 0, c_t_o = 0, c_t_c = 0;
        for(i=0; ; i++) {
            if(str[i]=='\0')
                break;
            if(str[i]=='(')
                c_f_o++;

            else if(str[i]==')')
                c_f_c++;

            else if(str[i]=='[')
                c_t_o++;

            else if(str[i]==']')
                c_t_c++;

        }
        
        if(c_f_o!=c_f_c||c_t_o!=c_t_c)
        printf("No\n");
        else
        printf("Yes\n");
    }
    return 0;
}
