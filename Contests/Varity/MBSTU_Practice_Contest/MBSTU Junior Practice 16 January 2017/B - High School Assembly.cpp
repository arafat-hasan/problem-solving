/**************************************************************
*   FILE NAME:  B - High School Assembly.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   16 Jan 16      New         1.0         Completed
***************************************************************/
#include <stdio.h>
#include <string.h>
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
int cnt;
int main() {

    int c = 0, t, n, h[20002], i, j;
    scanf("%i", &t);
    while(c<t) {

        scanf("%i", &n);

        for(i=0; i<20002; i++)
            h[i]=0;

        for(i=0; i<n; i++) {
            scanf("%i", &h[i]);
        }
        /*j=n;
        int cnt=0;
                for(i=1; h[i]>0; i++) {//4 5 1 2 6 3 8 9 7
                  if(h[i-1]>h[i]) {
                    h[j++]=h[i-1];
                  h[i-1]=-1;
                cnt++;
         }
        int temp;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                if (h[j] > h[j + 1]) {
                    temp = h[j];
                    h[j] = h[j + 1];
                    h[j + 1] = temp;
                }
            }
*/

bubbleSort(h, n);
            for(i=0; i<n; i++) {
                printf("%i ", h[i]);
            }


        







        c++;
    }
    return 0;
}
//4 5 1 2 6 3 8 9 7



void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}


void swap(int *xp, int *yp)
{
    cnt++;
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
