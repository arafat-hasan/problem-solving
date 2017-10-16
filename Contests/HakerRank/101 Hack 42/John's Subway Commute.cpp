/***************************************************************************************
*   FILE NAME:  John's Subway Commute.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   18 Oct 16      New         1.0         Completed,Accepted, Test Case #12 WA
**************************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <string.h>
int x[10000001];
int main() {

    char str[1000001];
    int i , j, max, index, len;

    scanf("%s", str);
    len=strlen(str);

    if(str[0]=='E'&&str[len-1]=='E') {
        printf("%i\n", len-1);
        return 0;
    }

    if(str[len-1]=='E') {
        printf("%i\n", len-1);
        return 0;
    }

    if(str[0]=='E') {
        printf("0\n");
        return 0;
    }

    for(i=1; i<len; i++) {
        if(str[i]=='E') {
            for(j=i+1; j<len; j++) {
                if(str[j]!='E') {
                    x[i]=j-i;
                    break;
                }
            }
        }
    }
    max=INT_MIN;
    for(i=0; i<len; i++) {
        if(x[i]>max) {
            max=x[i];
            index = i;
        }
    }
    int count=0;
for(i=0;i<len;i++)
if(str[i]=='E')
count++;

if(count==1){
	    printf("%i", index);
	    return 0;
	}

    printf("%i", index+1);

    return 0;
}
