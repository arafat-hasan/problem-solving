/***********************************************************************
 *   FILE NAME: Chocolate-13037.cpp
 *
 *   PURPOSE:
 *
 *   @author: Md. Arafat Hasan Jenin
 *   EMAIL:  OpenDoor.Arafat[at]gmail[dot]com
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * -------------------------------------------------------------------
 *    19 Nov 2016    New             0.0         Completed, TE
 *    20 Nov 2016    New             0.0         NM
 *    12 Mar 2017    New             1.0         Accepted
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

#define MAX 1000002

int A[3][MAX], comb[MAX*2], dup[MAX];

int makedup(int arr[], int size){
    int i, k=0;
    size--;
    for(i = 0; i < size; i++){
        if(arr[i] == arr[i+1]){
            dup[k++] = arr[i];
            i++;
        }
    }
    return k;
}  



void merge(int *a, int low, int high, int mid) { //used by merge_sort

    int i, j, k, c[MAX];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) a[i] = c[i];
}

void merge_sort(int *a, int low, int high) { //low and high inclusive

    int mid;
    if (low < high) {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}


int binarysearch (int *array, int end,int key) {
    //array must be sorted, if key is found return 0 based index,
    //else -1;
    int start = 0, mid;
    end--;
    while (start <= end) {
        mid = (start + end) / 2;
        if (key == array[mid]) return mid;
        else if (key < array[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}


int main() {
    int T, cs = 0;
    scanf("%d", &T);
    while (T--) {
        int n[3];
        for (int i = 0; i < 3; i++)
            scanf("%d", &n[i]);


        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n[i]; j++)
                scanf("%d", &A[i][j]);
            merge_sort(A[i], 0, n[i]-1);
            n[i] = unique(A[i], A[i]+n[i]) - A[i];
        }

        int i , j, len_dup, rmdup_len, ans[3][2], count;

        //////////////////////////////////////////////////////////////////////////

        for(i = 0; i < n[0]; i++){
            comb[i] = A[0][i];
        }
        for(j = 0; j < n[1]; j++){
            comb[i++] = A[1][j];
        }
        merge_sort(comb, 0, n[0]+n[1]-1);
        len_dup = makedup(comb, n[0]+n[1]);
        rmdup_len = unique(comb, comb+n[0]+n[1])-comb;
        count = len_dup;
        for(i = 0; i < n[2]; i++) {
            if(binarysearch(dup, len_dup, A[2][i]) != -1) count--;       
        }
        ans[2][1] = count;
        count = 0;
        for(i = 0; i < n[2]; i++) {
            if(binarysearch(comb, rmdup_len, A[2][i]) == -1) count++;       
        }

        ans[2][0] = count;

        //////////////////////////////////////////////////////////////////////////

        for(i = 0; i < n[1]; i++){
            comb[i] = A[1][i];
        }
        for(j = 0; j < n[2]; j++){
            comb[i++] = A[2][j];
        }
        merge_sort(comb, 0, n[1]+n[2]-1);
        len_dup = makedup(comb, n[1]+n[2]);
        rmdup_len = unique(comb, comb+n[1]+n[2]) - comb;
        count = len_dup;
        for(i = 0; i < n[0]; i++) {
            if(binarysearch(dup, len_dup, A[0][i]) != -1) count--;       
        }
        ans[0][1] = count;
        count = 0;
        for(i = 0; i < n[0]; i++) {
            if(binarysearch(comb, rmdup_len, A[0][i]) == -1) count++;       
        }

        ans[0][0] = count;


        //////////////////////////////////////////////////////////////////////////

        for(i = 0; i < n[2]; i++){
            comb[i] = A[2][i];
        }
        for(j = 0; j < n[0]; j++){
            comb[i++] = A[0][j];
        }
        merge_sort(comb, 0, n[2]+n[0]-1);
        len_dup = makedup(comb, n[2]+n[0]);
        rmdup_len = unique(comb, comb+n[2]+n[0])-comb;
        count = len_dup;
        for(i = 0; i < n[1]; i++) {
            if(binarysearch(dup, len_dup, A[1][i]) != -1) count--;       
        }
        ans[1][1] = count;
        count = 0;
        for(i = 0; i < n[1]; i++) {
            if(binarysearch(comb, rmdup_len, A[1][i]) == -1) count++;       
        }

        ans[1][0] = count;

        //////////////////////////////////////////////////////////////////////////////////////////


        printf("Case #%d:\n", ++cs);
        for (int i = 0; i < 3; i++)
            printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}

