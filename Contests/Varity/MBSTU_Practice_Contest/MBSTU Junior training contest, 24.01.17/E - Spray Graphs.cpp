/***********************************************************************
*   FILE NAME: E - Spray Graphs.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    24 Jan 17    New             1.0         Completed,Accepted
***********************************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    int t, n,  ans[31]={0, 1, 4, 12, 28, 60, 124, 252, 508, 1020, 2044, 4092, 8188, 16380, 32764, 65532, 131068, 262140, 524284, 1048572, 2097148, 4194300, 8388604, 16777212, 33554428, 67108860, 134217724, 268435452, 536870908, 1073741820, 2147483644};

    scanf("%i", &t);

    while(t--) {
		
        scanf("%i", &n);
        printf("%i\n", ans[n]);


    }

    return 0;
}







//~ int main() {

    //~ int t, n, i, ans;

    //~ scanf("%i", &t);

    //~ while(t--) {
		
        //~ scanf("%i", &n);
        
        //~ if(n == 1)
           //~ ans =1;
            
        //~ else {
            //~ ans = 0;
            //~ for(i = 1; i < n; i++) {
                //~ ans = (ans * 2) + 4;
            //~ }
        //~ }
        
        //~ printf("%i\n", ans);


    //~ }

    //~ return 0;
//~ }
